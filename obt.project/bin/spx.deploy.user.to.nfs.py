#!/usr/bin/env python3

import datetime, os
from obt import path, pathtools, command
from spx import path as spx_path

#######################################################

def latest_of(base,pattern):
  x = pathtools.patglob(str(base), pattern)
  x = sorted(x, key=os.path.getmtime, reverse=True)
  print(base,pattern,x)
  return x[0]

#######################################################

user = os.environ["USER"]
home = path.Path(os.environ["HOME"])
sysroot = spx_path.root/"tmp"/"deploy"/"merged_sysroot"

#####################
# convenience
#####################

def copy(src,dest):
  command.run(["sudo","cp","--preserve=links", src,dest],do_log=True)
def copy_recursive(src,dest):
  command.run(["sudo","cp","-r",src,dest],do_log=True)

#######################################################
# copy to nfs export
#######################################################

def copy_pattern( destdir, base, pattern ):
  l = pathtools.recursive_patglob(base, pattern)
  #print(destdir, base, pattern, l)
  for item in l:
    named = os.path.basename(item)
    # subpath should be relative to base
    subpath = os.path.relpath(item, str(base))
    subdir = os.path.dirname(subpath)
    os.system("sudo mkdir -p %s/%s"%(str(destdir),subdir))
    dest = path.Path(str(destdir))/subpath
    #print(dest)
    #print(named, item, dest)
    #print( "copying", named, "to", dest)
    copy(item, dest)

####################

src_usr_lib = sysroot/"usr"/"lib"
dst_usr_lib = "/export/rfs/usr/lib"

copy_pattern(dst_usr_lib, src_usr_lib, "libgbm*", )
copy_pattern(dst_usr_lib, src_usr_lib, "libwayland*")
copy_pattern(dst_usr_lib, src_usr_lib, "libEGL*")
#copy_pattern(dst_usr_lib, src_usr_lib, "libX11*")
#copy_pattern(dst_usr_lib, src_usr_lib, "lib*")

src_opt = sysroot/"opt"
dst_opt = path.Path("/export/rfs/opt")

copy_pattern(dst_opt/"bin", src_opt/"bin", "*")
copy_pattern(dst_opt/"testprogs", src_opt/"testprogs", "*")

####################
