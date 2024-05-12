#!/usr/bin/env bash

bitbake rcar-image-minimal

home="/home/yoctodev"
whitehawk="${home}/build/tmp-glibc/deploy/images/whitehawk"
dest="${home}/build/deploy"

sudo cp  ${whitehawk}/Image ${dest}/
sudo cp  ${whitehawk}/r8a779g0-whitehawk.dtb ${dest}/
sudo cp  ${whitehawk}/*rootfs*.bz2 ${dest}/