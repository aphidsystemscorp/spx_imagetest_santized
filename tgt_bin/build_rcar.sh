#!/usr/bin/env bash

chmod u+w /home/yoctodev/build/tmp-glibc/work/aarch64-oe-linux/gtk+3/3.24.14-r0/gtk+-3.24.14/config.rpath

bitbake rcar-image-minimal

home="/home/yoctodev"
whitehawk="${home}/build/tmp-glibc/deploy/images/whitehawk"
dest="${home}/build/deploy"

sudo cp  ${whitehawk}/Image ${dest}/
sudo cp  ${whitehawk}/r8a779g0-whitehawk.dtb ${dest}/
sudo cp  ${whitehawk}/*rootfs*.bz2 ${dest}/