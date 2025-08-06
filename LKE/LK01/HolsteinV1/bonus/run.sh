#! /bin/sh
gcc exploit.c -o exploit -Wall -static -std=c2x
cp  exploit root
cd   root; find . -print0 | cpio -o --null --format=newc > ../debugfs.cpio
cd   .. /


qemu-system-x86_64 \
    -m 64M \
    -nographic \
    -kernel bzImage \
    -append "console=ttyS0 loglevel=3 oops=panic panic=-1 nopti" \
    -no-reboot \
    -cpu  qemu64 \
    -smp 1 \
    -monitor /dev/null \
    -initrd debugfs.cpio \
    -net nic,model=virtio \
    -net user \
    -gdb tcp::12345
