# SPDX-License-Identifier: MIT
# Copyright (C) <year> <copyright holder>

SUMMARY = "Custom Image with Rogue DDK"
DESCRIPTION = "Custom image for your target with Rogue DDK and GFX layer."

LICENSE = "MIT"

# Inherit the base image
require rcar-image-minimal.bb

# Add the custom GFX layer
IMAGE_INSTALL_append = " \
    my-custom-gfx-layer \
    vim \
"

# Set any additional configuration variables here if needed
# For example:
# MY_CUSTOM_VARIABLE = "value"

# Set any additional image features here if needed
# For example:
# IMAGE_FEATURES += "debug-tweaks"

