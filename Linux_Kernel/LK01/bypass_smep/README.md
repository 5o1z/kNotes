## Table of Contents

- [prepare_kernel_cred and commit_creds overview](#prepare_kernel_cred-and-commit_creds-overview)
- [Return to user](#return-to-user)


## prepare_kernel_cred and commit_creds overview

All the processes in Linux have a set of credentials that define their permissions. The `prepare_kernel_cred` function is used to prepare a new set of credentials, while `commit_creds` applies those credentials to the current process. This is handled on the heap within a structure known as the `cred` structure. And each process (task) is managed by a structure called a `task_struct` structure, which contains a pointer to a `cred` structure.

```c
struct cred {
	atomic_t	usage;
#ifdef CONFIG_DEBUG_CREDENTIALS
	atomic_t	subscribers;	/* number of processes subscribed */
	void		*put_addr;
	unsigned	magic;
#define CRED_MAGIC	0x43736564
#define CRED_MAGIC_DEAD	0x44656144
#endif
	kuid_t		uid;		/* real UID of the task */
	kgid_t		gid;		/* real GID of the task */
	kuid_t		suid;		/* saved UID of the task */
	kgid_t		sgid;		/* saved GID of the task */
	kuid_t		euid;		/* effective UID of the task */
	kgid_t		egid;		/* effective GID of the task */
	kuid_t		fsuid;		/* UID for VFS ops */
	kgid_t		fsgid;		/* GID for VFS ops */
	unsigned	securebits;	/* SUID-less security management */
	kernel_cap_t	cap_inheritable; /* caps our children can inherit */
	kernel_cap_t	cap_permitted;	/* caps we're permitted */
	kernel_cap_t	cap_effective;	/* caps we can actually use */
	kernel_cap_t	cap_bset;	/* capability bounding set */
	kernel_cap_t	cap_ambient;	/* Ambient capability set */
#ifdef CONFIG_KEYS
	unsigned char	jit_keyring;	/* default keyring to attach requested
					 * keys to */
	struct key	*session_keyring; /* keyring inherited over fork */
	struct key	*process_keyring; /* keyring private to this process */
	struct key	*thread_keyring; /* keyring private to this thread */
	struct key	*request_key_auth; /* assumed request_key authority */
#endif
#ifdef CONFIG_SECURITY
	void		*security;	/* LSM security */
#endif
	struct user_struct *user;	/* real user ID subscription */
	struct user_namespace *user_ns; /* user_ns the caps and keyrings are relative to. */
	struct ucounts *ucounts;
	struct group_info *group_info;	/* supplementary groups for euid/fsgid */
	/* RCU deletion */
	union {
		int non_rcu;			/* Can we skip RCU deletion? */
		struct rcu_head	rcu;		/* RCU deletion hook */
	};
} __randomize_layout;


struct task_struct {
    ...
	/* Process credentials: */

	/* Tracer's credentials at attach: */
	const struct cred __rcu		*ptracer_cred;

	/* Objective and real subjective task credentials (COW): */
	const struct cred __rcu		*real_cred;

	/* Effective (overridable) subjective task credentials (COW): */
	const struct cred __rcu		*cred;
    ...
}
```

The `cred` structure is created at the time of process creation and is stored in the `task_struct` of the process. The `real_cred` pointer points to the original credentials of the process, while the `cred` pointer points to the effective credentials that are currently in use. So in the case of Privilege Escalation, we just need to focus on process credentials and how to manipulate them. So our goal is to change the `cred` and `real_cread` pointers in the `task_struct` of the process to `root` credentials ([init_cred](https://elixir.bootlin.com/linux/v5.14.9/source/kernel/cred.c#L41)).

To do this, we will use the `prepare_kernel_cred` function to prepare a new set of credentials and then use the `commit_creds` function to apply those credentials to the current process. The `prepare_kernel_cred` function takes a pointer to a `task_struct` as an argument, which is usually the current process. If we pass `NULL`, it will prepare the credentials for the `init` process, which has root privileges.

```c
struct cred *prepare_kernel_cred(struct task_struct *daemon)
{
	const struct cred *old;
	struct cred *new;

	new = kmem_cache_alloc(cred_jar, GFP_KERNEL);
	if (!new)
		return NULL;

	kdebug("prepare_kernel_cred() alloc %p", new);

	if (daemon)
		old = get_task_cred(daemon);
	else
		old = get_cred(&init_cred);

    ...

    return new;
}
```

And pass the prepared credentials to the [commit_creds](https://elixir.bootlin.com/linux/v5.14.9/source/kernel/cred.c#L449) function, which will apply them to the current process:

```c
void commit_creds(struct cred *new)
```

or

```c
void commit_creds(prepare_kernel_cred(NULL))
```

**PATCHED: But sadly, in Kernel 6.2, the [prepare_kernel_cred](https://elixir.bootlin.com/linux/v6.2/source/kernel/cred.c#L712) function has been modified to prevent the use of `NULL` as an argument. However, the `init_cred` is still there, so we can easily pass the address of `init_cred` to `commit_cred` without using `prepare_kernel_cred`**

## Return to user

After we have successfully changed the credentials of the current process to `root`, we need to return to user mode. This is important because if not return to user safely, the kernel will panic and stop our exploit before using root privileges to do anything.

Transitioning between user space and kernel space involves switching CPU privilege modes. Going from user space to kernel space is typically done via a syscall or an interrupt like `int 0x80`. When userspace trigger syscall it will swap from userspace to kernelspace through the `entry_SYSCALL`.

<!-- Conversely, going back from kernel space to user space typically uses instructions like `sysexit`, `iretq`. Among them, `iretq` is simpler to use, so it's commonly used in kernel exploits. Therefore, when returning from kernel mode to user mode, it's necessary to switch the GS segment from the kernel GS to the user GS. For that purpose, the `swapgs` instruction is used. -->
