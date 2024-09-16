#!/usr/bin/env python3

import os
from obt import command
from spx import path

command.run(["spx.user.build.waylandkms.py"], do_log=True)
command.run(["spx.user.build.libgbm.py"], do_log=True)
#command.run(["spx.user.build.cefproject.py"], do_log=True)


r8sdk = path.r8sdk
src_sysroot = r8sdk/"sysroots"/"aarch64-poky-linux"
dst_sysroot = path._root()/"tmp"/"deploy"/"merged_sysroot"

#cmd = "cp -r %s/opt/* %s/opt/" % (src_sysroot, dst_sysroot)
#print(cmd)
#os.system(cmd)
