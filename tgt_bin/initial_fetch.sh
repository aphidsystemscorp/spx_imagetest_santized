#!/usr/bin/env bash

#cd /home/yoctodev
#source /home/yoctodev/poky/oe-init-build-env 
bash -c "bitbake --runall=fetch rcar-image-adas-dev"