## Build a QEMU

Notes about the process of building QEMU from source code.

## Steps to Build QEMU

1. **Install Dependencies**:

```sh
sudo apt update && sudo apt install -y \
build-essential pkg-config ninja-build meson \
python3 python3-pip python3-venv python3-setuptools \
git flex bison gettext libtool \
libglib2.0-dev libpixman-1-dev zlib1g-dev \
libgtk-3-dev libsdl2-dev libsdl2-image-dev libvte-2.91-dev libspice-server-dev libepoxy-dev \
libaio-dev libbluetooth-dev libbrlapi-dev libbz2-dev libcap-ng-dev libcurl4-gnutls-dev libfdt-dev \
libiscsi-dev libjemalloc-dev libjpeg-dev liblzo2-dev librados-dev librbd-dev libseccomp-dev \
libsnappy-dev libssh-dev libusb-1.0-0-dev libusbredirparser-dev libvde-dev libvdeplug-dev \
libxen-dev liblzf-dev libnuma-dev libnfs-dev libpng-dev libcapstone-dev liburing-dev libzstd-dev \
libasound2-dev libpulse-dev gdb
```

2. **Build QEMU**:

```sh
wget https://download.qemu.org/qemu-9.0.2.tar.xz
tar xvJf qemu-9.0.2.tar.xz
cd qemu-9.0.2
../configure \
  --enable-debug \
  --enable-trace-backends=log \
  --enable-gtk --enable-sdl --enable-vnc --enable-curses \
  --enable-kvm --enable-vhost-net --enable-vhost-vdpa \
  --enable-libssh --enable-usb-redir --enable-spice \
  --enable-opengl --enable-virtfs --enable-numa \
  --disable-strip --disable-werror --extra-cflags="-O0 -g3" \
  --extra-ldflags="-rdynamic"
make -j$(nproc)
```

> `--enable-debug`: enable debug symbols, assertions, and debug information.
>
> `--enable-trace-backends=log`: enable QEMU trace backend that writes trace events to a log file.
>
> `--extra-cflags="-O0 -g3"`: compile with no optimizations and with maximum debug info (-O0 disables optimizations; -g3 includes full debugging symbols).
>
> `--disable-strip`: do not strip symbols from the binaries (keeps symbol names in the executable).
>
> `--extra-ldflags="-rdynamic"`: pass `-rdynamic` to the linker so dynamic symbols are exported, making it easier for `gdb` and `addr2line` to resolve symbols.

## References

[The QEMU build system architecture](https://www.qemu.org/docs/master/devel/build-system.html)
