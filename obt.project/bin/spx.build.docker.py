#!/usr/bin/env python3

from obt import command
from spx import path as spx_path

cmd_list = [
  "docker",
  "build",
  "-t",
  "yocto-build",
  spx_path.root
]

command.run(cmd_list, working_dir=spx_path.root, do_log=True)