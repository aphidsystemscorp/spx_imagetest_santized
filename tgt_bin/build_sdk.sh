#!/usr/bin/env bash

bitbake rcar-image-adas-dev -c populate_sdk

home="/home/yoctodev"
builddir="${home}/build"
whitehawk="${builddir}/tmp/deploy/images/whitehawk"
dest="${home}/build/deploy"

