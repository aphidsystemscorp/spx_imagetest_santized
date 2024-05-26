#!/usr/bin/env python3
#

import os, sys, argparse
from obt import path, command
from obt import path as obt_path
from spx import path as spx_path

parser = argparse.ArgumentParser(description='Launch a docker container for Yocto build')
parser.add_argument('-c', "--command", type=str, default="bash", help='command to run in the container')
args = parser.parse_args()

submodules = spx_path.root/"submodules"
bitbakes = spx_path.root/"bitbakes"
tgt_bin = spx_path.root/"tgt_bin"

output_products = spx_path.root/"output_products"
#this_rogue_ddk = str(spx_path.root/"rogue_ddk.bb")

def vmapstr(src,dest):
    return ["-v", str(src)+":"+str(dest)]

def setenv(key,val):
    return ["-e", str(key)+"="+str(val)]

H = path.Path("/home/yoctodev")
B = H/"build"

d_cmd = ["docker","run","-it"]
####################################################
d_cmd += vmapstr(tgt_bin/"list_images.sh",B/"list_images.sh")
d_cmd += vmapstr(tgt_bin/"prefetch_sources.sh",B/"prefetch_sources.sh")
d_cmd += vmapstr(tgt_bin/"build_dumpvars.sh",B/"build_dumpvars.sh")
d_cmd += vmapstr(tgt_bin/"build_linux.sh",B/"build_linux.sh")
d_cmd += vmapstr(tgt_bin/"build_sdk.sh",B/"build_sdk.sh")
d_cmd += vmapstr(tgt_bin/"incr_kernel.sh",B/"incr_kernel.sh")
d_cmd += vmapstr(tgt_bin/"clean_min.sh",B/"clean_min.sh")
d_cmd += vmapstr(tgt_bin/"clean_all.sh",B/"clean_all.sh")
####################################################
d_cmd += vmapstr(bitbakes/"local.conf",B/"conf/local.conf")
d_cmd += vmapstr(bitbakes/"bblayers.conf",B/"conf/bblayers.conf")
d_cmd += vmapstr(bitbakes/"meta-tozlayer",H/"meta-tozlayer")
####################################################
d_cmd += vmapstr(submodules/"meta-openembedded",H/"meta-openembedded")
d_cmd += vmapstr(submodules/"meta-renesas",H/"meta-renesas")
d_cmd += vmapstr(submodules/"meta-clang",H/"meta-clang")
d_cmd += vmapstr(submodules/"meta-browser",H/"meta-browser")
d_cmd += vmapstr(submodules/"meta-retro",H/"meta-retro")
d_cmd += vmapstr(submodules/"rcar-gfx",H/"rcar-gfx")
d_cmd += vmapstr(submodules/"poky",H/"poky")
#d_cmd += vmapstr(submodules/"wayland-kms",H/"wayland-kms")
#d_cmd += vmapstr(submodules/"wlroots",H/"wlroots")
#d_cmd += vmapstr(submodules/"libgbm",H/"libgbm")
####################################################
d_cmd += vmapstr(output_products/"cache",B/"cache")
d_cmd += vmapstr(output_products/"sstate-cache",B/"sstate-cache")
d_cmd += vmapstr(output_products/"downloads",B/"downloads")
####################################################
d_cmd += vmapstr(spx_path.root/"deploy",B/"deploy")
d_cmd += vmapstr(spx_path.root/"tmp",B/"tmp")
d_cmd += vmapstr(spx_path.root/"testprogs",B/"testprogs")
# vmapstr(this_local_conf,B/"conf/local.conf"), \
# vmapstr(spx_path.root/"custom_image.bb",B/"conf/local.conf"),
# vmapstr(spx_path.root/"rogue_ddk.bb",H/"meta-custom/recipes-custom/rogue-ddk/rogue_ddk.bb"),
####################################################

d_cmd += ["yocto-build", "bash", "-c", "source ~/poky/oe-init-build-env build && %s" % args.command]


command.run(d_cmd, working_dir=spx_path.root,do_log=True)
