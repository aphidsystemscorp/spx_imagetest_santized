#!/usr/bin/env python3

from obt import command, pathtools, host
from obt import path as obt_path
from spx import path as spx_path

project_src = spx_path.root/"submodules"/"cef-project"
project_dst = obt_path.builds()/"aarch64-cef-project"
project_bld = project_dst/".build"
sysroot = obt_path.stage()/"r8toolchain"/"sysroots"/"aarch64-poky-linux"

project_dest = spx_path.root/"tmp"/"deploy"/"overlays"/"opt"

pathtools.rmdir(project_dst,force=True)
pathtools.mkdir(project_dst,parents=True)
pathtools.chdir(project_dst)
pathtools.mkdir(project_bld)

################################
# cmake configuration
################################

conf_vars = {
  "CMAKE_TOOLCHAIN_FILE": "%s/testprogs/r8toolchain.cmake"%spx_path.root, 
}


command.run([
             "cmake",
             "-DPROJECT_ARCH=arm64",
             project_src
             ],
            working_dir=project_bld, 
            environment=conf_vars, 
            do_log=True)

################################
# build
################################

command.run(["make",'-j',host.NumCores,"minimal"], working_dir=project_bld, do_log=True)

################################
# install
################################

pathtools.mkdir(project_dest)

cef_dst = project_dest/"cef-project"
pathtools.rmdir(cef_dst)
pathtools.copydir(project_bld/"Release", cef_dst)

#command.run(["make",'install'], working_dir=project_bld, do_log=True)
