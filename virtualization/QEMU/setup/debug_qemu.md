## Setup for Debugging QEMU

Make sure QEMU is built with debug symbols and without optimizations for effective debugging. See [Build a QEMU](./build_qemu.md) for build instructions.

## Steps to Debug QEMU

1. Confirm QEMU is built with debug options:

   ```sh
   qemu-system-x86_64 --version
   ```

2. Run GDB with QEMU and your desired VM parameters:

   ```sh
   gdb --args /usr/local/bin/qemu-system-x86_64\
    -enable-kvm \
    -m 2048 \
    -smp 2 \
    -cpu host \
    -drive format=raw,file=laag.img \
    -serial mon:stdio \
    -net nic,macaddr=00:16:3e:60:0a:50 \
    -net tap \
    -vnc :3
   ```
