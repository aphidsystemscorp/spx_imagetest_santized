#!/usr/bin/env python3

from obt import command, pathtools, host
from obt import path as obt_path
from spx import path as spx_path
from spx import r8sdk 

comp_src = spx_path.root/"submodules"/"compositor"
comp_dst = obt_path.builds()/"aarch64-compositor"
comp_bld = comp_dst/".build"
sysroot = obt_path.stage()/"r8toolchain"/"sysroots"/"aarch64-poky-linux"
sysroot_host = obt_path.stage()/"r8toolchain"/"sysroots"/"x86_64-pokysdk-linux"
sysroot_dest = spx_path.root/"tmp"/"deploy"/"merged_sysroot"
pkconfigsrc = sysroot/"usr"/"lib"/"pkgconfig"
#overlays = spx_path.root/"tmp"/"deploy"/"overlays"
#pkconfigdest = overlays/"usr"/"lib"/"pkgconfig"

pathtools.rmdir(comp_dst)
pathtools.mkdir(comp_bld,parents=True)
pathtools.chdir(comp_dst)

conf_vars = {
  "PKG_CONFIG": sysroot_host/"usr"/"bin"/"pkg-config",
  "PKG_CONFIG_PATH": ("%s"%(pkconfigsrc)),
  "CMAKE_TOOLCHAIN_FILE": "%s/testprogs/r8toolchain.cmake"%spx_path.root, 
}

r8sdk.run([
             "/home/michael/.staging-spx-may25/r8toolchain/sysroots/x86_64-pokysdk-linux/usr/bin/cmake",
             "-DCMAKE_INSTALL_PREFIX=%s"%str(sysroot_dest/"opt"),
             spx_path.root/"testprogs"/"compositor",
             ],
            working_dir=comp_bld, 
            environment=conf_vars, 
            do_log=True)

r8sdk.run(["make",'-j',host.NumCores], working_dir=comp_bld, do_log=True)
r8sdk.run(["make",'install'], working_dir=comp_bld, do_log=True)
