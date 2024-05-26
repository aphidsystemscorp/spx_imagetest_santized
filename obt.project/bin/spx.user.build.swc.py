#!/usr/bin/env python3

import os, argparse 
from obt import command, pathtools, host
from obt import path as obt_path
from spx import path as spx_path
from spx import r8sdk 

argparser = argparse.ArgumentParser(description='Build swc project')  
argparser.add_argument('--clean', action='store_true', help='Clean build directory')
args = argparser.parse_args()
clean = args.clean

swc_src = spx_path.root/"submodules"/"swc"
swc_dst = obt_path.builds()/"aarch64-swc"
swc_bld = swc_dst/".build"
sysroot = obt_path.stage()/"r8toolchain"/"sysroots"/"aarch64-poky-linux"
sysroot_host = obt_path.stage()/"r8toolchain"/"sysroots"/"x86_64-pokysdk-linux"

if clean:
  pathtools.rmdir(swc_bld,force=True)

pathtools.mkdir(swc_bld,parents=True)
pathtools.chdir(swc_dst)

pkconfigsrc = sysroot/"usr"/"lib"/"pkgconfig"

backup = dict(os.environ)
for item in backup.items():
  del os.environ [item[0]]

os.environ["OBT_STAGE"] = backup["OBT_STAGE"]
os.environ["PYTHONPATH"] = backup["PYTHONPATH"]
os.environ["VIRTUAL_ENV"] = backup["VIRTUAL_ENV"]
os.environ["PS1"] = backup["PS1"]
os.environ["OBT_SUBSPACE_PROMPT"] = "R8SDK"
os.environ["SPX_WORKSPACE_DIR"] = backup["SPX_WORKSPACE_DIR"]
  
my_env = dict()
my_env["PATH"] = backup["OBT_BIN_PUB_DIR"] 
my_env["PATH"] += ":"
my_env["PATH"] += backup["OBT_BIN_PRIV_DIR"]
my_env["PATH"] += ":"
my_env["PATH"] += backup["OBT_ORIGINAL_PATH"]
my_env["PATH"] += ":"
my_env["PATH"] += backup["SPX_WORKSPACE_DIR"]+"/obt.project/bin"
my_env["PATH"] += ":"
my_env["PATH"] += backup["R8_SDK_ROOT"]+"/sysroots/x86_64-pokysdk-linux/usr/bin/aarch64-poky-linux"
my_env["PYTHONPATH"] = backup["PYTHONPATH"]
#my_env["CMAKE_TOOLCHAIN_FILE"] = "%s/testprogs/r8toolchain.cmake"%spx_path.root, 
my_env["PKG_CONFIG"] = sysroot_host/"usr"/"bin"/"pkg-config"
my_env["PKG_CONFIG_PATH"] =  str(pkconfigsrc)
my_env["PKG_CONFIG_PATH"] += ":"+str(sysroot)+"/usr/share/pkgconfig"

r8sdk.run([
              "make"
              ], 
            working_dir=swc_src, 
            environment=my_env,
            do_log=True)

if False:
  r8sdk.run( [ "ninja", "-j", "1" ],
              working_dir=swc_bld,
              environment=my_env,
              do_log=True)
 