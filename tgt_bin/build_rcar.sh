#!/usr/bin/env bash

chmod u+w /home/yoctodev/build/tmp/work/aarch64-poky-linux/gtk+3/3.24.14-r0/gtk+-3.24.14/config.rpath

bitbake rcar-image-adas-dev
#bitbake rcar-image-minimal

home="/home/yoctodev"
builddir="${home}/build"
whitehawk="${builddir}/tmp/deploy/images/whitehawk"
dest="${home}/build/deploy"

sudo cp  ${whitehawk}/Image ${dest}/
sudo cp  ${whitehawk}/r8a779g0-whitehawk-native.dtb ${dest}/r8a779g0-whitehawk.dtb
sudo cp  ${whitehawk}/*rootfs*.bz2 ${dest}/

#./work/whitehawk-poky-linux/linux-renesas/5.10.147+gitAUTOINC+4b2bf1dfb8-r1/linux-whitehawk-standard-build/drivers/gpu/drm/rcar-du/
#./work/whitehawk-poky-linux/linux-renesas/5.10.147+gitAUTOINC+4b2bf1dfb8-r1/linux-whitehawk-standard-build