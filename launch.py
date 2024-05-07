#!/usr/bin/env python3
#

import os, sys
from obt import path, command

this_dir = path.Path(os.path.dirname(os.path.realpath(__file__)))

this_local_conf = this_dir/"local.conf"
this_bblayers_conf = this_dir/"bblayers.conf"
output_products = this_dir/"output_products"
#this_rogue_ddk = str(this_dir/"rogue_ddk.bb")

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
      +  vmapstr(this_dir/"list_images.sh",B/"list_images.sh") \
      +  ["yocto-build"]

      #+  #vmapstr(this_local_conf,B/"conf/local.conf"), \
#         vmapstr(this_dir/"custom_image.bb",B/"conf/local.conf"),
#         vmapstr(this_dir/"rogue_ddk.bb",H/"meta-custom/recipes-custom/rogue-ddk/rogue_ddk.bb"),

command.run(d_cmd, working_dir=this_dir)
