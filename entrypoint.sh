#!/usr/bin/bash

# Navigate to the poky directory and source the Yocto environment setup script
cd /home/yocto-user/poky
#source oe-init-build-env

# Since oe-init-build-env changes the working directory to the build directory,
# we need to ensure all subsequent commands run there.

# Append custom layer to bblayers.conf if not already present
#if ! grep -q "meta-custom/meta-rcar-bsp" conf/bblayers.conf; then
#  echo "BBLAYERS += \"\${BSPDIR}/../meta-custom/meta-rcar-bsp\"" >> conf/bblayers.conf
#fi

# Execute any passed commands or fall back to bash
exec "$@"
