#!/usr/bin/env python3
#

import os, sys
from obt import path, command

this_dir = path.Path(os.path.dirname(os.path.realpath(__file__)))

this_local_conf = str(this_dir/"local.conf")
this_bblayers_conf = str(this_dir/"bblayers.conf")

d_cmd = ["docker","run","-it",
         "-v", this_local_conf+":/home/yoctodev/build/conf/local.conf",
         "-v", this_bblayers_conf+":/home/yoctodev/build/conf/bblayers.conf",
         "yocto-build" ]

command.run(d_cmd, working_dir=this_dir)
