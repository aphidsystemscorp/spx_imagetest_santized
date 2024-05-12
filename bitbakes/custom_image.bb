require recipes-core/images/core-image-minimal.bb

SUMMARY = "My custom Yocto image based on core-image-minimal"

IMAGE_INSTALL_append = " vim"
