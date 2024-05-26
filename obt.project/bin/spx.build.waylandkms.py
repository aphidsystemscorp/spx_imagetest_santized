#!/usr/bin/env python3

from obt import command, pathtools, host
from obt import path as obt_path
from spx import path as spx_path
from spx import r8sdk 

wayland_src = spx_path.root/"submodules"/"wayland-kms"
wayland_dst = obt_path.builds()/"aarch64-wayland-kms"
wayland_bld = wayland_dst/".build"
sysroot = obt_path.stage()/"r8toolchain"/"sysroots"/"aarch64-poky-linux"
sysroot_host = obt_path.stage()/"r8toolchain"/"sysroots"/"x86_64-pokysdk-linux"
pkconfigsrc = sysroot/"usr"/"lib"/"pkgconfig"
overlays = spx_path.root/"tmp"/"deploy"/"overlays"
pkconfigdest = overlays/"usr"/"lib"/"pkgconfig"

pathtools.rmdir(wayland_dst)
pathtools.copydir(wayland_src, wayland_dst)
pathtools.chdir(wayland_dst)
command.run(["autoreconf","-i"], working_dir=wayland_dst, do_log=True)

pathtools.mkdir(wayland_bld)

conf_vars = {
  "PKG_CONFIG": sysroot_host/"usr"/"bin"/"pkg-config",
  "PKG_CONFIG_PATH": ("%s"%(pkconfigsrc)),
  #"PKG_CONFIG_PATH": ("%s"%(pkconfigsrc)),
  #"PKG_CONFIG_SYSROOT_DIR": sysroot,
  #"PKG_CONFIG_LIBDIR": "usr"/"lib",
}

print(conf_vars)
#assert(False)
r8sdk.run([
             "../configure",
             "--build=x86_64-linux-gnu",
             "--host=aarch64-poky-linux",
             "--target=aarch64-poky-linux",
             #"--with-pkgconfigdir=%s"%pkconfigsrc, 
             "--with-sysroot=%s"%sysroot,
             "--prefix=%s"%sysroot, 
             "--includedir=%s/usr/include"%sysroot, 
             "--libdir=%s/usr/lib"%sysroot
             ],
            working_dir=wayland_bld, 
            environment=conf_vars, 
            do_log=True)

r8sdk.run(["make",'-j',host.NumCores], working_dir=wayland_bld, do_log=True)
r8sdk.run(["make",'install'], working_dir=wayland_bld, do_log=True)
