#!/usr/bin/env bash

home="/home/yoctodev"
builddir="${home}/build"
whitehawk="${builddir}/tmp/deploy/images/whitehawk"
dest="${home}/build/deploy"

bitbake -c compile -f linux-renesas
bitbake -c deploy linux-renesas

sudo cp  ${whitehawk}/Image ${dest}/
sudo cp  ${whitehawk}/r8a779g0-whitehawk.dtb ${dest}/r8a779g0-whitehawk.dtb

echo "checksums: (image,dtree)"
md5sum ${dest}/Image
md5sum ${dest}/r8a779g0-whitehawk.dtb