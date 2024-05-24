#!/usr/bin/env python3

from obt import command, pathtools, host
from obt import path as obt_path
from spx import path as spx_path

wayland_src = spx_path.root/"submodules"/"wayland-kms"
wayland_dst = obt_path.builds()/"aarch64-wayland-kms"
wayland_bld = wayland_dst/".build"
sysroot = obt_path.Path("/opt/r8toolchain/sysroots/aarch64-poky-linux")
pkconfigsrc = sysroot/"usr"/"lib"/"pkgconfig"
instdir = spx_path.root/"tmp"/"deploy"/"overlays"
pkconfigdest = instdir/"usr"/"lib"/"pkgconfig"

pathtools.rmdir(wayland_dst)
pathtools.copydir(wayland_src, wayland_dst)
pathtools.chdir(wayland_dst)
command.run(["autoreconf","-i"], working_dir=wayland_dst, do_log=True)

pathtools.mkdir(wayland_bld)

conf_vars = {
  "PKG_CONFIG_PATH": ("%s:%s"%(pkconfigdest,pkconfigsrc)),
  "PKG_CONFIG_SYSROOT_DIR": sysroot,
  "PKG_CONFIG_LIBDIR": pkconfigdest,
}

command.run([
             "../configure",
             "--host=aarch64-poky-linux",
             "--with-pkgconfigdir=%s"%pkconfigsrc, 
             "--prefix=%s"%instdir, 
             "--includedir=%s/usr/include"%instdir, 
             "--libdir=%s/usr/lib"%instdir
             ],
            working_dir=wayland_bld, 
            environment=conf_vars, 
            do_log=True)

command.run(["make",'-j',host.NumCores], working_dir=wayland_bld, do_log=True)
command.run(["make",'install'], working_dir=wayland_bld, do_log=True)
