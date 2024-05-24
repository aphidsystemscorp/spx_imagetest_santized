#!/usr/bin/env python3

from obt import command, pathtools, host
from obt import path as obt_path
from spx import path as spx_path

libgbm_src = spx_path.root/"submodules"/"libgbm2"
libgbm_dst = obt_path.builds()/"aarch64-libgbm"
libgbm_bld = libgbm_dst/".build"
sysroot = obt_path.Path("/opt/r8toolchain/sysroots/aarch64-poky-linux")
instdir = spx_path.root/"tmp"/"deploy"/"overlays"

pathtools.rmdir(libgbm_dst,force=True)
pathtools.copydir(libgbm_src, libgbm_dst)
pathtools.chdir(libgbm_dst)

pathtools.mkdir(libgbm_bld)
pathtools.chdir(libgbm_bld)
command.run(["../autogen.sh","--host=aarch64-poky-linux"], working_dir=libgbm_bld, do_log=True)

command.run([
              "../configure",
              "--host=aarch64-poky-linux",
              "--with-sysroot=%s"%sysroot,
              "--prefix=%s"%instdir,
              "--includedir=%s/usr/include"%instdir, 
              "--libdir=%s/usr/lib"%instdir
              ], 
            working_dir=libgbm_bld, 
            do_log=True)

command.run(["make",'-j',host.NumCores], working_dir=libgbm_bld, do_log=True)
command.run(["make",'install'], working_dir=libgbm_bld, do_log=True)
