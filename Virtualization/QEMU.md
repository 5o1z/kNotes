### Build QEMU from Source

```bash
# Install dependencies
sudo apt update
sudo pip3 install ninja
sudo apt install libglib2.0-dev libgcrypt20-dev zlib1g-dev autoconf automake libtool bison flex libpixman-1-dev

# Download QEMU source code
wget https://download.qemu.org/qemu-8.0.2.tar.xz

# Build
tar -xvf qemu-8.0.2.tar.xz
cd qemu-8.0.2
./configure --enable-debug
make -j$(nproc)
```

### Nouns

- **Memory Mapped I/O (MMIO):** A method used by computers to perform input/output (I/O) operations by mapping device registers into the system's address space. This allows the CPU to communicate with hardware devices using standard memory access instructions.

- **Port-Mapped I/O (PMIO):** Also known as isolated I/O, it is a method of performing input/output operations using a separate address space specifically designated for I/O devices. This allows the CPU to communicate with hardware devices using special I/O instructions.

- **VirtIO:** A virtualization standard for network and disk device drivers where the guest's device driver "knows" it is running in a virtual environment, and cooperates with the hypervisor. Note in [VirtIO.md](./VirtIO.md).

- **Direct Memory Access (DMA):** A feature that allows hardware devices to access the main system memory (RAM) directly, bypassing the CPU. This enables faster data transfer rates and reduces CPU overhead, improving overall system performance.

- **Base Address Registers (BARs):** are used in PCI and PCIe devices to define the memory or I/O address ranges that the device will use for communication with the system. Each BAR specifies a starting address and size for a specific region of memory or I/O space that the device can access.

- **Input/Output Memory Management Unit (IOMMU):** A hardware component that manages the mapping of device-visible virtual addresses to physical addresses in system memory. It provides memory protection and isolation for devices, preventing them from accessing unauthorized memory regions and enhancing overall system security.

- **Peripheral Component Interconnect (PCI):** is an expansion bus standard that allows the CPU to communicate with peripheral devices (network cards, GPUs, disk controllers, etc.). Each PCI Device is identified by Vendor ID, Device ID, has a configuration space (256 B/4 KB) containing configuration information and `BARs (Base Address Registers)` used to map the MMIO or PIO region used by the device. In QEMU, PCI devices are emulated using PCIDevice and registered via `pci_register_bar()` to map MemoryRegion into the guest's address space, allowing the driver in the guest to read/write device registers like real hardware.

- **Random Access Memory (RAM):** simply a memory region that the host can allocate to the guest. Initialized using the `memory_region_init_ram()` function

- **Random Read-Only Memory (ROM):** Like RAM, but read-only (directly accesses a region of host memory). Initialized with `memory_region_init_rom_device()`

- **Others:**
    - APIC - Advanced Programmable Interrupt Controller
    - SRAT - System Resource Affinity Table
    - SLIT - System Locality Information Table
    - GPA - Guest Physical Address
    - HVP - Host Virtual Address
    - MSI - Message Signaled Interrupts
    - IPI - Inter-Processor Interrupt
    - SDM - Sofeware Developer Manual
    - TPR - Task-Priority Register
    - RVI / SVI
    - RVI - Requesting virtual interrupt (low byte)
    - SVI - Servicing virtual interrupt (high byte)

    - EOI - end of interrupt
    - PIR - Posted Interrupt Requests
    - VIRR - Virtual interrupt-request register
    - RDMA- remote direct memory access

### QEMU Memory Layout

```
                        Guest' processes
                     +--------------------+
Virtual addr space   |                    |
                     +--------------------+
                     |                    |
                     \__   Page Table     \__
                        \                    \
                         |                    |  Guest kernel
                    +----+--------------------+----------------+
Guest's phy. memory |    |                    |                |
                    +----+--------------------+----------------+
                    |                                          |
                    \__                                        \__
                       \                                          \
                        |             QEMU process                 |
                   +----+------------------------------------------+
Virtual addr space |    |                                          |
                   +----+------------------------------------------+
                   |                                               |
                    \__                Page Table                   \__
                       \                                               \
                        |                                               |
                   +----+-----------------------------------------------++
Physical memory    |    |                                               ||
                   +----+-----------------------------------------------++
```

### QEMU Device: Structures & Functions in Use

A device goes through these phases:

- The device is described by a `TypeInfo` struct.
- `type_new()` creates a `TypeImpl`, whose data mirrors `TypeInfo`.
- Register the device type (`module_call_init()`).
- Initialize the device type (`type_initialize()`).
- Instantiate the device.

#### TypeImpl — the concrete instance of a TypeInfo

```c
struct TypeImpl
{
    const char *name;
    size_t class_size;
    size_t instance_size;
    size_t instance_align;

    void (*class_init)(ObjectClass *klass, void *data);
    void (*class_base_init)(ObjectClass *klass, void *data);
    void *class_data;

    void (*instance_init)(Object *obj);
    void (*instance_post_init)(Object *obj);
    void (*instance_finalize)(Object *obj);

    bool abstract;

    const char *parent;
    TypeImpl *parent_type;

    ObjectClass *class; // must be initialized

    int num_interfaces;
    InterfaceImpl interfaces[MAX_INTERFACES];
};
```

-> QEMU creates this from user-defined `TypeInfo`

#### TypeInfo — describes a device

```c
struct TypeInfo
{
    const char *name;
    const char *parent;

    size_t instance_size;
    size_t instance_align;
    void (*instance_init)(Object *obj);
    void (*instance_post_init)(Object *obj);
    void (*instance_finalize)(Object *obj);

    bool abstract;
    size_t class_size;

    void (*class_init)(ObjectClass *klass, void *data);
    void (*class_base_init)(ObjectClass *klass, void *data);
    void *class_data;

    InterfaceInfo *interfaces;
};
```

- Defined by the user
- `*class_init` points to the class initialization function; override virtual methods here (via function pointers).

#### Object — base object that all others extend

```c
struct Object
{
    ObjectClass *class;
    ObjectFree *free;
    GHashTable *properties;
    uint32_t ref;
    Object *parent;
};
```

- The first member must be a pointer to ObjectClass.
- `ObjectClass` → the class initialized in `class_init()`
- `Object` → instance of class initialized in `instance_init()`.

#### Initialization Overview

1. TypeInfo → ModuleEntry → TypeImpl → ObjectClass → Object
2. Register `TypeImpl` using `TypeInfo`
3. `class_init()` initializes `ObjectClass`
4. `instance_init()` initializes `Object`
5. Actual hardware setup happens in `realize()`:
    - Create memory regions
    - Mounting the bus

At compile time, the device adds the registered device's function to the init array by `type_init()`

#### Module Initialization

`qemu_init()` → `qemu_init_subsystems()` → `module_call_init(MODULE_INIT_QOM)`

- Fetches all ModuleEntry with type `MODULE_INIT_QOM`
- Calls their `init()` functions

#### Type Initialization Path

**Functions called in order:** `qemu_init()` → `qemu_create_machine()` → `select_machine()` →
`object_class_get_list()` → `object_class_foreach()` →
`g_hash_table_foreach()` → `object_class_foreach_tramp()` → `type_initialize()`

**Steps:**

1. If `ti->class` exists → already initialized.
2. Allocate space: `ti->class = g_malloc0(ti->class_size)`
3. Get parent: `parent = type_get_parent(ti)`
4. Copy parent: `memcpy(ti->class, parent->class, parent->class_size)`
5. `type_initialize_interface()`
6. Create property table
7. Set `ti->class->type = ti`
8. Call `parent->class_base_init()` if defined
9. Finally call `ti->class_init()`

#### Object Instantiation Path

**Functions called in order:** `qemu_init()` → `qemu_create_machine()` →
`object_new_with_class()` → `object_new_with_type()` →
`object_initialize_with_type()` → `object_init_with_type()` → `ti->instance_init()`

**Steps:**

1. `object_new_with_class()` calls `object_new_with_type(klass->type)`.
2. `object_new_with_type()` ensures class initialized via `type_initialize()`.
3. `object_initialize_with_type()` sets `object->class`, allocates properties.
4. `object_init_with_type()` ensures parent initialized → calls `instance_init()`.

#### register_module_init() - Add the device to be registered to the linked list of a specific type

```c
void register_module_init(void (*fn)(void), module_init_type type)
{
    ModuleEntry *e;
    ModuleTypeList *l;

    e = g_malloc0(sizeof(*e));
    e->init = fn;
    e->type = type;

    l = find_type(type);

    QTAILQ_INSERT_TAIL(l, e, node); // Add to the end of the linked list
}
```

- `MODULE_INIT_QOM` is one of the types used to register the device
- The register functions of these devices will be called at the beginning of `main()`:

    ```c
    int main(int argc, char **argv, char **envp)
    {
        ...
        module_call_init(MODULE_INIT_TRACE);
        qemu_init_cpu_list();
        module_call_init(MODULE_INIT_QOM);
        ...
    }
    ```

#### ObjectClass — Base class for all classes

```c
/**
 * struct ObjectClass:
 *
 * The base for all classes.  The only thing that #ObjectClass contains is an
 * integer type handle.
 */
struct ObjectClass
{
    /* private: */
    Type type;
    GSList *interfaces;

    const char *object_cast_cache[OBJECT_CLASS_CAST_CACHE];
    const char *class_cast_cache[OBJECT_CLASS_CAST_CACHE];

    ObjectUnparent *unparent;

    GHashTable *properties;
};
```

#### type_initialize() - used to initialize a registered `TypeImpl`

```c
static void type_initialize(TypeImpl *ti)
{
    TypeImpl *parent;

    if (ti->class) {
        return;
    }
    // Set the size
    ti->class_size = type_class_get_size(ti);
    ti->instance_size = type_object_get_size(ti);
    /* Any type with zero instance_size is implicitly abstract.
     * This means interface types are all abstract.
     */
    if (ti->instance_size == 0) {
        ti->abstract = true;
    }
    // highest type ?
    if (type_is_ancestor(ti, type_interface)) {
        assert(ti->instance_size == 0);
        assert(ti->abstract);
        assert(!ti->instance_init);
        assert(!ti->instance_post_init);
        assert(!ti->instance_finalize);
        assert(!ti->num_interfaces);
    }
    // First allocate space to store the class
    ti->class = g_malloc0(ti->class_size);

    parent = type_get_parent(ti);
    if (parent) { // Initialize parent first
        type_initialize(parent); // recursively call
        GSList *e;
        int i;

        g_assert(parent->class_size <= ti->class_size);
        g_assert(parent->instance_size <= ti->instance_size);
        // Copy the contents of the parent class
        memcpy(ti->class, parent->class, parent->class_size);
        ti->class->interfaces = NULL;

        // Get the parent's interface entry and initialize it yourself (?)
        for (e = parent->class->interfaces; e; e = e->next) {
            InterfaceClass *iface = e->data;
            ObjectClass *klass = OBJECT_CLASS(iface);

            type_initialize_interface(ti, iface->interface_type, klass->type);
        }

        for (i = 0; i < ti->num_interfaces; i++) {
            TypeImpl *t = type_get_by_name(ti->interfaces[i].typename);
            if (!t) {
                error_report("missing interface '%s' for object '%s'",
                             ti->interfaces[i].typename, parent->name);
                abort();
            }
            // Find the upper layer of TypeImpl of interface and initialize it
            for (e = ti->class->interfaces; e; e = e->next) {
                TypeImpl *target_type = OBJECT_CLASS(e->data)->type;

                if (type_is_ancestor(target_type, t)) {
                    break;
                }
            }

            if (e) {
                continue;
            }

            type_initialize_interface(ti, t, t);
        }
    }

    ti->class->properties = g_hash_table_new_full(g_str_hash, g_str_equal, NULL,
                                                  object_property_free);

    ti->class->type = ti;

    // Initialize all parent classes
    while (parent) {
        if (parent->class_base_init) {
            parent->class_base_init(ti->class, ti->class_data);
        }
        parent = type_get_parent(parent);
    }

    // Execute user-defined init function (?)
    if (ti->class_init) {
        ti->class_init(ti->class, ti->class_data);
    }
}
```

#### type_initialize_interface() - Initialize the interface in the device

```c
static void type_initialize_interface(TypeImpl *ti, TypeImpl *interface_type,
                                      TypeImpl *parent_type)
{
    InterfaceClass *new_iface;
    TypeInfo info = { };
    TypeImpl *iface_impl;

    info.parent = parent_type->name;
    info.name = g_strdup_printf("%s::%s", ti->name, interface_type->name);
    info.abstract = true;

    iface_impl = type_new(&info);
    iface_impl->parent_type = parent_type;
    type_initialize(iface_impl); // Initialize the device class again...
    g_free((char *)info.name);

    new_iface = (InterfaceClass *)iface_impl->class;
    new_iface->concrete_class = ti->class;
    new_iface->interface_type = interface_type;

    ti->class->interfaces = g_slist_append(ti->class->interfaces, new_iface);
}
```

(Not sure about this one behavior...)

#### object_initialize() - Create a device instance

```c
void object_initialize(void *data, size_t size, const char *typename)
{
    TypeImpl *type = type_get_by_name(typename);

#ifdef CONFIG_MODULES
    if (!type) {
        module_load_qom_one(typename);
        type = type_get_by_name(typename);
    }
#endif
    if (!type) {
        error_report("missing object type '%s'", typename);
        abort();
    }

    object_initialize_with_type(data, size, type);
}
```

This wrapper will first get the type corresponding to `typename` and call `object_initialize_with_type()` to initialize it:

```c
static void object_initialize_with_type(Object *obj, size_t size, TypeImpl *type)
{
    type_initialize(type);

    g_assert(type->instance_size >= sizeof(Object));
    g_assert(type->abstract == false);
    g_assert(size >= type->instance_size);

    memset(obj, 0, type->instance_size);
    obj->class = type->class;
    object_ref(obj);
    object_class_property_init_all(obj);
    obj->properties = g_hash_table_new_full(g_str_hash, g_str_equal,
                                            NULL, object_property_free);
    object_init_with_type(obj, type);
    object_post_init_with_type(obj, type);
}
```

#### DeviceClass - the parent class for many devices

```c
/**
* DeviceClass:
* @props: Properties accessing state fields.
* @realize: Callback function invoked when the #DeviceState:realized
* property is changed to %true.
* @unrealize: Callback function invoked when the #DeviceState:realized
* property is changed to %false.
* @hotpluggable: indicates if #DeviceClass is hotpluggable, available
* as readonly "hotpluggable" property of #DeviceState instance
*
* # Realization #
* Devices are constructed in two stages,
* 1) object instantiation (實例化) via object_initialize() and
* 2) device realization (實現) via #DeviceState:realized property.
* The former may not fail (and must not abort or exit, since it is called
* during device introspection already), and the latter may return error
* information to the caller and must be re-entrant.
* Trivial field initializations should go into #TypeInfo.instance_init.
* Operations depending on @props static properties should go into @realize.
* After successful realization, setting static properties will fail.
*
* As an interim step, the #DeviceState:realized property can also be
* set with qdev_realize().
* In the future, devices will propagate this state change to their children
* and along busses they expose.
* The point in time will be deferred to machine creation, so that values
* set in @realize will not be introspectable beforehand. Therefore devices
* must not create children during @realize; they should initialize them via
* object_initialize() in their own #TypeInfo.instance_init and forward the
* realization events appropriately.
*
* Any type may override the @realize and/or @unrealize callbacks but needs
* to call the parent type's implementation if keeping their functionality
* is desired. Refer to QOM documentation for further discussion and examples.
*
* <note>
*   <para>
* Since TYPE_DEVICE doesn't implement @realize and @unrealize, types
* derived directly from it need not call their parent's @realize and
* @unrealize.
* For other types consult the documentation and implementation of the
* respective parent types.
*   </para>
* </note>
*
* # Hiding a device #
* To hide a device, a DeviceListener function hide_device() needs to
* be registered.
* It can be used to defer adding a device and therefore hide it from
* the guest. The handler registering to this DeviceListener can save
* the QOpts passed to it for re-using it later. It must return if it
* wants the device to be hidden or visible. When the handler function
* decides the device shall be visible it will be added with
* qdev_device_add() and realized as any other device. Otherwise
* qdev_device_add() will return early without adding the device. The
* guest will not see a "hidden" device until it was marked visible
* and qdev_device_add called again.
*
*/
struct DeviceClass {
    /*< private >*/
    ObjectClass parent_class;
    /*< public >*/

    DECLARE_BITMAP(categories, DEVICE_CATEGORY_MAX);
    const char *fw_name;
    const char *desc;

    /*
     * The underscore at the end ensures a compile-time error if someone
     * assigns to dc->props instead of using device_class_set_props.
     */
    Property *props_;

    /*
     * Can this device be instantiated with -device / device_add?
     * All devices should support instantiation with device_add, and
     * this flag should not exist.  But we're not there, yet.  Some
     * devices fail to instantiate with cryptic error messages.
     * Others instantiate, but don't work.  Exposing users to such
     * behavior would be cruel; clearing this flag will protect them.
     * It should never be cleared without a comment explaining why it
     * is cleared.
     * TODO remove once we're there
     */
    bool user_creatable;
    /*
    Traditional PCI and ISA devices require the computer to be cold before plugging in.

    Hotplug, on the other hand, allows you to plug in devices without shutting down the computer or disconnecting the power.

    e.g., a USB drive.
    */
    bool hotpluggable;

    /* callbacks */
    /*
     * Reset method here is deprecated and replaced by methods in the
     * resettable class interface to implement a multi-phase reset.
     * TODO: remove once every reset callback is unused
     */
    DeviceReset reset;
    DeviceRealize realize;
    DeviceUnrealize unrealize;

    /* device state */
    const VMStateDescription *vmsd;

    /* Private to qdev / bus.  */
    const char *bus_type;
};
```

#### device_initfn

```c
static void device_initfn(Object *obj)
{
    DeviceState *dev = DEVICE(obj);

    if (phase_check(PHASE_MACHINE_READY)) {
        dev->hotplugged = 1;
        qdev_hot_added = true;
    }

    dev->instance_id_alias = -1;
    dev->realized = false;
    dev->allow_unplug_during_migration = false;

    QLIST_INIT(&dev->gpios);
    QLIST_INIT(&dev->clocks);
}
```

Do some simple initialization and put it in `QLIST_INIT`

```c
static void device_class_init(ObjectClass *class, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(class);
    VMStateIfClass *vc = VMSTATE_IF_CLASS(class);
    ResettableClass *rc = RESETTABLE_CLASS(class);

    class->unparent = device_unparent;

    /* by default all devices were considered as hotpluggable,
     * so with intent to check it in generic qdev_unplug() /
     * device_set_realized() functions make every device
     * hotpluggable. Devices that shouldn't be hotpluggable,
     * should override it in their class_init()
     */
    dc->hotpluggable = true;
    dc->user_creatable = true;
    vc->get_id = device_vmstate_if_get_id;
    rc->get_state = device_get_reset_state;
    rc->child_foreach = device_reset_child_foreach;

    /*
     * @device_phases_reset is put as the default reset method below, allowing
     * to do the multi-phase transition from base classes to leaf classes. It
     * allows a legacy-reset Device class to extend a multi-phases-reset
     * Device class for the following reason:
     * + If a base class B has been moved to multi-phase, then it does not
     *   override this default reset method and may have defined phase methods.
     * + A child class C (extending class B) which uses
     *   device_class_set_parent_reset() (or similar means) to override the
     *   reset method will still work as expected. @device_phases_reset function
     *   will be registered as the parent reset method and effectively call
     *   parent reset phases.
     */
    dc->reset = device_phases_reset;
    rc->get_transitional_function = device_get_transitional_reset;

    object_class_property_add_bool(class, "realized",
                                   device_get_realized, device_set_realized);
    object_class_property_add_bool(class, "hotpluggable",
                                   device_get_hotpluggable, NULL);
    object_class_property_add_bool(class, "hotplugged",
                                   device_get_hotplugged, NULL);
    object_class_property_add_link(class, "parent_bus", TYPE_BUS,
                                   offsetof(DeviceState, parent_bus), NULL, 0);
}
```

Property settings can usually be assigned by giving parameters when running QEMU, but here we initialize the three properties `realized`, `hotpluggable`, and `hotplugged`

```c
static const TypeInfo device_type_info = {
    .name = TYPE_DEVICE,
    .parent = TYPE_OBJECT,
    .instance_size = sizeof(DeviceState),
    .instance_init = device_initfn, // Responsible for initializing instance
    .instance_post_init = device_post_init,
    .instance_finalize = device_finalize,
    .class_base_init = device_class_base_init,
    .class_init = device_class_init, // Responsible for initializing the class
    .abstract = true,
    .class_size = sizeof(DeviceClass),
    .interfaces = (InterfaceInfo[]) {
        { TYPE_VMSTATE_IF },
        { TYPE_RESETTABLE_INTERFACE },
        { }
    }
};
```

#### MemoryRegion - About the memory structure in the VM

```c
/* MemoryRegion:
 * A struct representing a memory region.
 */
struct MemoryRegion {
    Object parent_obj;

    /* private: */

    /* The following fields should fit in a cache line */
    bool romd_mode;
    bool ram;
    bool subpage;
    bool readonly; /* For RAM regions */
    bool nonvolatile;
    bool rom_device;
    bool flush_coalesced_mmio;
    uint8_t dirty_log_mask;
    bool is_iommu;
    RAMBlock *ram_block;
    Object *owner;

    const MemoryRegionOps *ops;
    void *opaque; // (?) Pointer to the operations of this memory region
    MemoryRegion *container;
    Int128 size;
    hwaddr addr;
    void (*destructor)(MemoryRegion *mr);
    uint64_t align;
    bool terminates;
    bool ram_device;
    bool enabled;
    bool warning_printed; /* For reservations */
    uint8_t vga_logging_count;
    MemoryRegion *alias;
    hwaddr alias_offset;
    int32_t priority;
    // The memory region actually uses a tree data structure to store
    QTAILQ_HEAD(, MemoryRegion) subregions;
    QTAILQ_ENTRY(MemoryRegion) subregions_link;
    QTAILQ_HEAD(, CoalescedMemoryRange) coalesced;
    const char *name;
    unsigned ioeventfd_nb;
    MemoryRegionIoeventfd *ioeventfds;
    RamDiscardManager *rdm; /* Only for RAM */
};
```

- Organized as a tree of subregions
- Memory setup path: `main()` → `qemu_init()`
      → `qemu_create_machine()`
      → `cpu_exec_init_all()`
      → `io_mem_init()`
      → `memory_map_init()`

#### AddressSpace - Another structure related to memory

```c
/**
 * struct AddressSpace: describes a mapping of addresses to #MemoryRegion objects
 */
struct AddressSpace {
    /* private: */
    struct rcu_head rcu;
    char *name;
    MemoryRegion *root; // root of MemoryRegion tree

    /* Accessed via RCU.  */
    struct FlatView *current_map;

    int ioeventfd_nb;
    struct MemoryRegionIoeventfd *ioeventfds;
    QTAILQ_HEAD(, MemoryListener) listeners;
    QTAILQ_ENTRY(AddressSpace) address_spaces_link;
};
```

- `struct FlatView` stores the flattened `MemoryRegion`
- `generate_memory_topology()` - render a memory topology into a list of disjoint absolute ranges
    - render_memory_region() - render a memory region into the global view. Ranges in @view obscure
  - `flatview_add_to_dispatch()`:
    ```c
    /*
    * The range in *section* may look like this:
    *
    *      |s|PPPPPPP|s|
    *
    * where s stands for subpage and P for page.
    */
    ```

- `address_space_set_flatview()` - Constructs the `AddressSpaceDispatch` structure:

    ```c
    struct AddressSpaceDispatch {
        // MemoryRegionSection
        // @describes a fragment of a #MemoryRegion
        MemoryRegionSection *mru_section;
        /* This is a multi-level map on the physical address space.
        * The bottom level has pointers to MemoryRegionSections.
        */
        PhysPageEntry phys_map;
        PhysPageMap map;
    };

    struct PhysPageEntry {
        /* How many bits skip to next level (in units of L2_SIZE). 0 for a leaf. */
        uint32_t skip : 6;
        /* index into phys_sections (!skip) or phys_map_nodes (skip) */
        uint32_t ptr : 26;
    ```

#### memory_region_init() - Initializes a memory region

```c
void memory_region_init(MemoryRegion *mr,
                        Object *owner,
                        const char *name,
                        uint64_t size)
{
    object_initialize(mr, sizeof(*mr), TYPE_MEMORY_REGION);
    memory_region_do_init(mr, owner, name, size);
}
```

It is a wrapper that uses `object_initialize()` to initialize the object first, and then initializes the MemoryRegion through `memory_region_do_init()`

#### RAMBlock - related to VM mapping memory

```c
struct RAMBlock {
    struct rcu_head rcu;
    struct MemoryRegion *mr;
    uint8_t *host;
    uint8_t *colo_cache; /* For colo, VM's ram cache */
    ram_addr_t offset;
    ram_addr_t used_length;
    ram_addr_t max_length;
    void (*resized)(const char*, uint64_t length, void *host);
    uint32_t flags;
    /* Protected by iothread lock.  */
    char idstr[256];
    /* RCU-enabled, writes protected by the ramlist lock */
    QLIST_ENTRY(RAMBlock) next;
    QLIST_HEAD(, RAMBlockNotifier) ramblock_notifiers;
    int fd;
    size_t page_size;
    /* dirty bitmap used during migration */
    unsigned long *bmap;
    /* bitmap of already received pages in postcopy */
    unsigned long *receivedmap;

    /*
     * bitmap to track already cleared dirty bitmap.  When the bit is
     * set, it means the corresponding memory chunk needs a log-clear.
     * Set this up to non-NULL to enable the capability to postpone
     * and split clearing of dirty bitmap on the remote node (e.g.,
     * KVM).  The bitmap will be set only when doing global sync.
     *
     * NOTE: this bitmap is different comparing to the other bitmaps
     * in that one bit can represent multiple guest pages (which is
     * decided by the `clear_bmap_shift' variable below).  On
     * destination side, this should always be NULL, and the variable
     * `clear_bmap_shift' is meaningless.
     */
    unsigned long *clear_bmap;
    uint8_t clear_bmap_shift;

    /*
     * RAM block length that corresponds to the used_length on the migration
     * source (after RAM block sizes were synchronized). Especially, after
     * starting to run the guest, used_length and postcopy_length can differ.
     * Used to register/unregister uffd handlers and as the size of the received
     * bitmap. Receiving any page beyond this length will bail out, as it
     * could not have been valid on the source.
     */
    ram_addr_t postcopy_length;
};
```

- `RAMBlock->host` = Host Virtual Address (HVA)
- `MemoryRegion->addr` = Guest Physical Address (GPA)
- Qemu's memory mapping process:
    - `pc_memory_init()`
    - `memory_region_init_ram()`
        - `memory_region_init_ram_nomigrate()`
        - `memory_region_init_ram_flags_nomigrate()`
            - `memory_region_init()` - Initialize a memory region. The region typically acts as a container for other memory regions. Use `memory_region_add_subregion()` to add subregions

            - `qemu_ram_alloc()`
                - `qemu_ram_alloc_internal()`
        - `vmstate_register_ram()`

#### x86_cpu_realizefn() - Instantiate the CPU, which is usually tied to the APIC

- Creates and realizes CPU & APIC.
- `x86_cpu_apic_create()` sets CPU props: `"id"`, `"lapic"`.
- `x86_cpu_apic_realize()` calls `qdev_realize()`

#### APICCommonState - Structure describing the APIC

```c
struct APICCommonState {
    /*< private >*/
    DeviceState parent_obj;
    /*< public >*/

    MemoryRegion io_memory; // Memory region registered during initialization
    X86CPU *cpu;
    uint32_t apicbase; // default APIC access address (?)
    uint8_t id; /* legacy APIC ID */
    uint32_t initial_apic_id;
    uint8_t version;
    uint8_t arb_id;
    uint8_t tpr;
    uint32_t spurious_vec;
    uint8_t log_dest;
    uint8_t dest_mode;
    uint32_t isr[8];  /* in service register */
    uint32_t tmr[8];  /* trigger mode register */
    uint32_t irr[8]; /* interrupt request register */
    uint32_t lvt[APIC_LVT_NB];
    uint32_t esr; /* error register */
    uint32_t icr[2];

    uint32_t divide_conf;
    int count_shift;
    uint32_t initial_count;
    int64_t initial_count_load_time;
    int64_t next_time;
    QEMUTimer *timer;
    int64_t timer_expiry;
    int sipi_vector;
    int wait_for_sipi;

    uint32_t vapic_control;
    DeviceState *vapic;
    hwaddr vapic_paddr; /* note: persistence via kvmvapic */
    bool legacy_instance_id;
};
```

#### apic_io_ops - defines the functions that apic will use as a device

```c
static const MemoryRegionOps apic_io_ops = {
    .read = apic_mem_read,
    .write = apic_mem_write,
    .impl.min_access_size = 1,
    .impl.max_access_size = 4,
    .valid.min_access_size = 1,
    .valid.max_access_size = 4,
    .endianness = DEVICE_NATIVE_ENDIAN,
};
```

#### apic_mem_write - function executed when writing to APIC address

```c
...
    case 0x30:
        s->icr[0] = val;
        apic_deliver(dev, (s->icr[1] >> 24) & 0xff, (s->icr[0] >> 11) & 1,
                     (s->icr[0] >> 8) & 7, (s->icr[0] & 0xff),
                     (s->icr[0] >> 15) & 1);
        break;
...
```

- Read [QEMU's instance_init() vs. realize()](https://people.redhat.com/~thuth/blog/qemu/2018/09/10/instance-init-realize.html)
- There are three common initialization functions: `class_init`, `instance_init`, and `realize`.
    - `instance_init()` is called first, followed by `realize()`. The former will not fail, the latter will.
    - instance corresponds to `TypeInfo`.
    - realize operates on `DeviceClass`.
    - Instances can be instantiated and finalized without realizing.

#### Properties

- Static: `DEFINE_PROP_*`
- Dynamic: `object_property_add()`, `object_property_add_child()`
- Modify: `object_property_set_<type>()`, `object_property_get_<type>()`

#### Device Relationships

- Child — parent owns and manages lifecycle of created subdevice. One parent → many children.
- Link — reference to another device (not ownership).

#### KVM Integration Notes

- Guest mode = VMX non-root mode.
- Virtio bypasses trap-emulation; guest communicates directly with QEMU I/O backend.
- QEMU-KVM split:
    - KVM handles CPU and memory.
    - QEMU handles I/O (disk, network, display, USB).
- Posted Interrupts: handled via virtual-APIC page; CPU records them as pending.

### Reference

https://github.com/u1f383/writeup/blob/main/learning/Qemu.md
