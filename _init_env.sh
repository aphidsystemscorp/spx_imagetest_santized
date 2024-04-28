#!/usr/bin/env bash

cd /home/yocto-user
source /home/yocto-user/poky/oe-init-build-env 
bash -c "bitbake --runall=fetch rcar-image-minimal"