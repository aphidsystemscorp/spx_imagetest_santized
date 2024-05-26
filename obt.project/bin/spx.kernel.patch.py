#!/usr/bin/env python3

import os
from obt import command, pathtools, host
from obt import path as obt_path
from spx import path as spx_path
from spx import r8sdk 

def patch(fname):
  command.run([
    "cp",
    spx_path.root/"bitbakes"/fname,
    spx_path.kernel_source/"arch"/"arm64"/"boot"/"dts"/"renesas"/fname,
  ])

patch("r8a779g0-whitehawk.dts")
patch("r8a779g0.dtsi")
