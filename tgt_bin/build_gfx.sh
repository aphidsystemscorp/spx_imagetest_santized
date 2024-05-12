#!/usr/bin/env bash

echo "HELLO"

export DISCIMAGE=~/yocto-discimage
export WORKDIR=~/yocto-workdir
#export CROSS_COMPILE=arm-linux-gnueabihf-
export CROSS_COMPILE=aarch64-oe-linux-


export RGX_BVNC="22.104.208.318" 
export BUILD=release 
export PVR_BUILD_DIR=r8a779g_linux

export KERNELDIR=~/build/tmp-glibc/work-shared/whitehawk/kernel-source
export CROSS_BIN=~/build/tmp-glibc/sysroots-components/x86_64/gcc-cross-aarch64/usr/bin/aarch64-oe-linux
export PATH=$CROSS_BIN:$PATH
export TARGET_OS=linux

#export CROSS_COMPILE=aarch64-none-linux-gnu3. 
#export SYSROOT=/media/${USER}/rootfs/ (SD card that was created in step 4)
cd /home/yoctodev/build/rogue_km/build/linux/r8a779g_linux
#make ARCH=arm64 KERNELDIR=/home/yoctodev/build/tmp-glibc/work-shared/whitehawk/kernel-source
make BUILD=debug
WINDOW_SYSTEM=wayland