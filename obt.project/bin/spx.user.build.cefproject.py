#!/usr/bin/env python3

import os, argparse 

from obt import command, pathtools, host
from obt import path as obt_path
from spx import path as spx_path
from spx import r8sdk 

argparser = argparse.ArgumentParser(description='Build CEF project')  
argparser.add_argument('--clean', action='store_true', help='Clean build directory')
args = argparser.parse_args()
clean = args.clean

project_src = spx_path.root/"submodules"/"cef-project"
project_dst = obt_path.builds()/"aarch64-cef-project"
project_bld = project_dst/".build"
sysroot = obt_path.stage()/"r8toolchain"/"sysroots"/"aarch64-poky-linux"
sysroot_host = obt_path.stage()/"r8toolchain"/"sysroots"/"x86_64-pokysdk-linux"
pkconfigsrc = sysroot/"usr"/"lib"/"pkgconfig"

project_dest = sysroot/"opt"

if clean:
  pathtools.rmdir(project_dst,force=True)
  pathtools.mkdir(project_dst,parents=True)

pathtools.chdir(project_dst)
pathtools.mkdir(project_bld)

################################
# cmake configuration
################################

conf_vars = {
  "PKG_CONFIG": sysroot_host/"usr"/"bin"/"pkg-config",
  "PKG_CONFIG_PATH": ("%s"%(pkconfigsrc)),
  "CMAKE_TOOLCHAIN_FILE": "%s/testprogs/r8toolchain.cmake"%spx_path.root, 
}


r8sdk.run([
             "/usr/bin/cmake",
             "-DPROJECT_ARCH=arm64",
             "-DPYTHON_EXECUTABLE=%s"%os.environ["PYTHON_BIN_PATH"],
             project_src
             ],
            working_dir=project_bld, 
            environment=conf_vars, 
            do_log=True)

################################
# build
################################

r8sdk.run(["make",'-j',host.NumCores,"minimal"], working_dir=project_bld, do_log=True)

################################
# install
################################

pathtools.mkdir(project_dest)
cef_dst = project_dest/"cef-project"
pathtools.rmdir(cef_dst)
pathtools.copydir(project_bld/"Release", cef_dst)

#command.run(["make",'install'], working_dir=project_bld, do_log=True)
