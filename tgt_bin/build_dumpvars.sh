#!/usr/bin/env bash

#chmod u+w /home/yoctodev/build/tmp/work/aarch64-poky-linux/gtk+3/3.24.14-r0/gtk+-3.24.14/config.rpath

bitbake -e rcar-image-adas
