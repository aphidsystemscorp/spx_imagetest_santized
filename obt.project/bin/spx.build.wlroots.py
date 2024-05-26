#!/usr/bin/env python3

import os, argparse 
from obt import command, pathtools, host
from obt import path as obt_path
from spx import path as spx_path
from spx import r8sdk 

argparser = argparse.ArgumentParser(description='Build wlroots project')  
argparser.add_argument('--clean', action='store_true', help='Clean build directory')
args = argparser.parse_args()
clean = args.clean

wlroots_src = spx_path.root/"submodules"/"wlroots"
wlroots_dst = obt_path.builds()/"aarch64-wlroots"
wlroots_bld = wlroots_dst/".build"
sysroot = obt_path.stage()/"r8toolchain"/"sysroots"/"aarch64-poky-linux"
sysroot_host = obt_path.stage()/"r8toolchain"/"sysroots"/"x86_64-pokysdk-linux"

if clean:
  pathtools.rmdir(wlroots_bld,force=True)
  #pathtools.copydir(wlroots_src, wlroots_dst)
  #pathtools.chdir(wlroots_dst)

pathtools.mkdir(wlroots_bld,parents=True)
pathtools.chdir(wlroots_dst)
#command.run(["../autogen.sh","--host=aarch64-poky-linux"], working_dir=wlroots_bld, do_log=True)

#/usr/bin/meson setup --cross-file $SPX_WORKSPACE_DIR/testprogs/mesonr8.txt .build

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
              #str(spx_path.r8sdk)+"/sysroots/x86_64-pokysdk-linux/usr/bin/meson",
              "/usr/bin/meson",
              "setup",
              "--prefix",
              sysroot,
              "--cross-file",
              "%s/testprogs/mesonr8.ini"%spx_path.root,
              "--cmake-prefix-path",
              spx_path.r8sdk/"usr"/"lib"/"cmake",
              "-Dxdg-foreign=disabled",
              "-Dx11-backend'=disabled",
              "-Dxwayland'=disabled",
              wlroots_bld
              ], 
            working_dir=wlroots_src, 
            environment=my_env,
            do_log=True)

if True:
  r8sdk.run( [ "ninja", "-j", "1" ],
              working_dir=wlroots_bld,
              environment=my_env,
              do_log=True)
 