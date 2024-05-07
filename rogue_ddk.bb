SUMMARY = "Rogue DDK for the Linux kernel"
DESCRIPTION = "Imagination Technologies Rogue DDK for the Linux kernel."
LICENSE = "Proprietary"
LIC_FILES_CHKSUM = "file://LICENSE;md5=<md5sum>"

SRC_URI = "git://github.com/renesas-rcar/rcar-gfx.git"

S = "${WORKDIR}/rcar-gfx"
H = "/home/yoctodev"
T = "${H}/build/tmp-glibc"

do_compile() {
    # Set up environment variables
    export DISCIMAGE=${T}/deploy/images/whitehawk/rcar-image-minimal-v4h-20240506013201.rootfs.tar.bz2
    export KERNELDIR=${T}/work/aarch64-oe-linux/linux-libc-headers/5.10-r0/git/
    export CROSS_COMPILE=arm-linux-gnueabihf-

    # Navigate to the Rogue DDK build directory
    cd ${S}/gfxdrv

    # Build the Rogue DDK kernel module
    make BUILD=debug
}

do_install() {
    # Create destination directory
    install -d ${D}/lib/modules/${KERNEL_VERSION}/extra/

    # Install the Rogue DDK kernel module
    install -m 644 ${S}/gfxdrv/built_module.ko ${D}/lib/modules/${KERNEL_VERSION}/extra/
}

FILES_${PN} += "/lib/modules/${KERNEL_VERSION}/extra/*"
