#!/usr/bin/env python3

from obt import command
from obt import path as obt_path
from spx import path as spx_path

cmd_list = [
  "sh", 
  #spx_path.root/"tmp"/"deploy"/"sdk"/"poky-glibc-x86_64-rcar-image-adas-dev-aarch64-v4h-toolchain-3.1.11.sh",
  spx_path.root/"tmp"/"deploy"/"sdk"/"poky-glibc-x86_64-rcar-image-adas-aarch64-v4h-toolchain-3.1.11.sh",
  "-y",
  "-d",
  obt_path.stage()/"r8toolchain",
]

c = command.Command(cmd_list, working_dir=spx_path.root, do_log=True)
rval = c.exec()