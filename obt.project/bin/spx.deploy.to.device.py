#!/usr/bin/env python3

import datetime, os
from obt import path, pathtools, command
from spx import path as spx_path

home = path.Path(os.environ["HOME"])
output_products = spx_path.root/"output_products"
deploy_src = output_products/"deploy"
dest_tftp = path.Path("/srv/tftp")
dest_nfs = path.Path("/export/")

# find latest tarball matching deploy_src/"rcar-image-minimal-v4h-*.rootfs.tar.bz2"

print(output_products)

latest_tarball = None
x = pathtools.patglob(str(deploy_src), "rcar-image-minimal-v4h-*.rootfs.tar.bz2")
x = sorted(x, key=os.path.getmtime, reverse=True)
latest = x[0]
latest_stripped = os.path.basename(latest).replace(".tar.bz2","")
print(latest)
print(latest_stripped)

#####################
# convenience
#####################

def copy(src,dest):
  command.run(["sudo","cp",src,dest],do_log=True)
def copy_recursive(src,dest):
  command.run(["sudo","cp","-r",src,dest],do_log=True)

####################
# kernel and dtb
####################

copy(deploy_src/"Image",dest_tftp/"Image")
copy(deploy_src/"r8a779g0-whitehawk.dtb",dest_tftp/"r8a779g0-whitehawk.dtb")

####################
# root filesystem
####################

dest_dir = dest_nfs/latest_stripped
command.run(["sudo","mkdir",dest_dir],do_log=True)
os.chdir(dest_dir)
command.run(["sudo","tar","-xvf",latest],do_log=True)
os.chdir(dest_nfs)
command.run(["sudo","rm","-rf", "rfs"])
command.run(["sudo","cp","-r",latest_stripped,"rfs"])
command.run(["rm","-f",home/".ssh"/"known_hosts"],do_log=True)

####################
