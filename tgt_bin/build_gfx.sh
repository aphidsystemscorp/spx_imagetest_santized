#!/usr/bin/env bash

echo "HELLO"

export DISCIMAGE=~/yocto-discimage
export WORKDIR=~/yocto-workdir
#export CROSS_COMPILE=arm-linux-gnueabihf-
export CROSS_COMPILE=aarch64-oe-linux-

export ARCH=arm64
export RGX_BVNC="22.104.208.318" 
export BUILD=release 
export PVR_BUILD_DIR=r8a779g_linux

#export KERNELDIR=~/build/tmp-glibc/work-shared/whitehawk/kernel-source
#export SYSROOT=~/build/tmp-glibc/sysroots/whitehawk
export KERNELDIR=~/build/tmp-glibc/work-shared/whitehawk/kernel-build-artifacts
export SYSROOT=${KERNELDIR}
export CROSS_BIN=~/build/tmp-glibc/sysroots-components/x86_64/gcc-cross-aarch64/usr/bin/aarch64-oe-linux
export PATH=$CROSS_BIN:$PATH
export TARGET_OS=Linux

cd /home/yoctodev/build/rogue_km/build/linux/r8a779g_linux
make BUILD=debug SYSROOT=${SYSROOT} CROSS_COMPILE=${CROSS_COMPILE} KERNELDIR=${KERNELDIR} TARGET_OS=${TARGET_OS} PVR_BUILD_DIR=${PVR_BUILD_DIR} ARCH=${ARCH} 
WINDOW_SYSTEM=wayland