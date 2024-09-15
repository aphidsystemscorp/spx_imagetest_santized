#!/usr/bin/env python3

import os
from obt import command, pathtools, host
from obt import path as obt_path
from spx import path as spx_path
from spx import r8sdk 

libgbm_src = spx_path.root/"submodules"/"libgbm2"
libgbm_dst = obt_path.builds()/"aarch64-libgbm"
libgbm_bld = libgbm_dst/".build"
sysroot = obt_path.stage()/"r8toolchain"/"sysroots"/"aarch64-poky-linux"
sysroot_host = obt_path.stage()/"r8toolchain"/"sysroots"/"x86_64-pokysdk-linux"
overlays = spx_path.root/"tmp"/"deploy"/"overlays"
pkconfigsrc = sysroot/"usr"/"lib"/"pkgconfig"

pathtools.rmdir(libgbm_dst,force=True)
pathtools.copydir(libgbm_src, libgbm_dst)
pathtools.chdir(libgbm_dst)

pathtools.mkdir(libgbm_bld)
pathtools.chdir(libgbm_bld)


conf_vars = {
  "PKG_CONFIG": sysroot_host/"usr"/"bin"/"pkg-config",
  "PKG_CONFIG_PATH": ("%s"%(pkconfigsrc)),
  #"PKG_CONFIG_SYSROOT_DIR": sysroot,
  #"PKG_CONFIG_LIBDIR": "usr"/"lib",
}

r8sdk.run(["../autogen.sh","--host=aarch64-poky-linux"], 
             working_dir=libgbm_bld,
             environment=conf_vars, 
             do_log=True)

r8sdk.run([
              "../configure",
              "--build=x86_64-linux-gnu",
              "--host=aarch64-poky-linux",
              "--target=aarch64-poky-linux",
#              "--with-sysroot=%s"%sysroot,
              "--prefix=%s"%sysroot,
              "--includedir=%s/usr/include"%sysroot, 
              #"--libdir=%s/usr/lib"%sysroot
              ], 
            working_dir=libgbm_bld, 
            environment=conf_vars, 
            do_log=True)

command.run(["make",'-j',host.NumCores], working_dir=libgbm_bld, do_log=True)
command.run(["make",'install'], working_dir=libgbm_bld, do_log=True)

r8sdk = spx_path.r8sdk
src_sysroot = r8sdk/"sysroots"/"aarch64-poky-linux"
dst_sysroot = spx_path._root()/"tmp"/"deploy"/"merged_sysroot"

cmd = "cp -r %s/opt/* %s/opt/" % (src_sysroot, dst_sysroot)
#print(cmd)
#os.system(cmd)
