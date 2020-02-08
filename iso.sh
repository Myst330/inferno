#!/bin/sh
set -e
. ./build.sh
 
mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
 
cp sysroot/boot/inferno.kernel isodir/boot/inferno.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "inferno" {
	multiboot /boot/inferno.kernel
}
EOF
grub-mkrescue -o inferno.iso isodir
