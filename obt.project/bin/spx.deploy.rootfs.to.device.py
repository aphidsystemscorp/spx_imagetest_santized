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

user = os.environ["USER"]
home = path.Path(os.environ["HOME"])
submodules = spx_path.root/"submodules"
rogue = submodules/"rogue"

deploy_src = spx_path.root/"tmp"/"deploy"/"images"/"whitehawk"

dest_nfs = path.Path("/export/")

#######################################################
# find latest tarball matching deploy_src/"rcar-image-minimal-v4h-*.rootfs.tar.bz2"
#######################################################

latest_tarball = None
latest = latest_of(deploy_src, "rcar-image-adas-dev-v4h-*.rootfs.tar.bz2")
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

#######################################################
# build root staging area
#######################################################

dest_dir = dest_nfs/latest_stripped
command.run(["sudo","rm","-rf",dest_dir],do_log=True)
command.run(["sudo","mkdir",dest_dir],do_log=True)
os.chdir(dest_dir)
command.run(["sudo","tar","-xvf",latest],do_log=True)
os.chdir(dest_nfs)

#######################################################
# tweak root filesystem
#######################################################

command.run(["sudo","mkdir", dest_dir/"opt"],do_log=True)
command.run(["sudo","cp", "-r", spx_path.root/"testprogs", dest_dir/"opt"/"testprogs"],do_log=True)
command.run(["sudo","cp", "-r", spx_path.root/"tmp"/"deploy"/"overlays", dest_dir],do_log=True)

#######################################################
# copy to nfs export
#######################################################

command.run(["sudo","rm","-rf", "rfs"])
command.run(["sudo","cp","-r",latest_stripped,"rfs"])
X = " ".join(["sudo","cp","-r","%s/*"%str(rogue),str(dest_nfs/"rfs")+"/"])
print(X)
os.system(X)
command.run(["sudo","chown","-R","%s:%s"%(user,user),dest_nfs/"rfs"],do_log=True)
command.run(["rm","-f",home/".ssh"/"known_hosts"],do_log=True)

####################
