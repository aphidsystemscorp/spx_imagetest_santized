#!/usr/bin/env python3

import datetime, os
from obt import path, pathtools, command
from spx import path as spx_path

#######################################################

def latest_of(base,pattern):
  x = pathtools.patglob(str(base), pattern)
  x = sorted(x, key=os.path.getmtime, reverse=True)
  return x[0]

#######################################################

deploy_src = spx_path.root/"tmp"/"deploy"/"images"/"whitehawk"
dest_tftp = path.Path("/srv/tftp")
dest_rfs = path.Path("/export/rfs")

#####################
# convenience
#####################

def copy(src,dest):
  command.run(["sudo","cp",src,dest],do_log=True)

####################
# kernel and dtb
####################

copy(deploy_src/"Image",dest_tftp/"Image")
copy(deploy_src/"r8a779g0-whitehawk.dtb",dest_tftp/"r8a779g0-whitehawk.dtb")

copy(deploy_src/"Image",dest_rfs/"boot"/"Image")
copy(deploy_src/"r8a779g0-whitehawk.dtb",dest_rfs/"boot"/"r8a779g0-whitehawk.dtb")

####################

command.run(["md5sum",dest_tftp/"Image"])
command.run(["md5sum",dest_tftp/"r8a779g0-whitehawk.dtb"])

####################
