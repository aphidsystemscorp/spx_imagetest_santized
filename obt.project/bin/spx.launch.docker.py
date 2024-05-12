#!/usr/bin/env python3
#

import os, sys
from obt import path, command
from obt import path as obt_path
from spx import path as spx_path

bitbakes = spx_path.root/"bitbakes"
this_local_conf = bitbakes/"local.conf"
this_bblayers_conf = bitbakes/"bblayers.conf"

output_products = spx_path.root/"output_products"
#this_rogue_ddk = str(spx_path.root/"rogue_ddk.bb")

def vmapstr(src,dest):
    return ["-v", str(src)+":"+str(dest)]

H = path.Path("/home/yoctodev")
B = H/"build"

d_cmd = ["docker","run","-it"] \
      +  vmapstr(output_products/"cache",B/"cache") \
      +  vmapstr(output_products/"sstate-cache",B/"sstate-cache") \
      +  vmapstr(output_products/"downloads",B/"downloads") \
      +  vmapstr(output_products/"tmp-glibc",B/"tmp-glibc") \
      +  vmapstr(this_local_conf,B/"conf/local.conf") \
      +  vmapstr(spx_path.root/"list_images.sh",B/"list_images.sh") \
      +  ["yocto-build"]

      #+  #vmapstr(this_local_conf,B/"conf/local.conf"), \
#         vmapstr(spx_path.root/"custom_image.bb",B/"conf/local.conf"),
#         vmapstr(spx_path.root/"rogue_ddk.bb",H/"meta-custom/recipes-custom/rogue-ddk/rogue_ddk.bb"),

command.run(d_cmd, working_dir=spx_path.root,do_log=True)
