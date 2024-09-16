#!/usr/bin/env python3

import os
from spx import r8sdk
from spx import path as spx_path
from obt import path
backup = dict(os.environ)
for item in backup.items():
  del os.environ [item[0]]

os.environ["OBT_STAGE"] = backup["OBT_STAGE"]
os.environ["PYTHONPATH"] = backup["PYTHONPATH"]
os.environ["VIRTUAL_ENV"] = backup["VIRTUAL_ENV"]
os.environ["PS1"] = backup["PS1"]
os.environ["OBT_SUBSPACE_PROMPT"] = "R8SDK"
os.environ["SPX_WORKSPACE_DIR"] = backup["SPX_WORKSPACE_DIR"]
os.environ["OBT_ORIGINAL_PATH"] =backup["OBT_ORIGINAL_PATH"]

my_env = dict()
my_env["PATH"] = backup["VIRTUAL_ENV"]+"/bin" 
my_env["PATH"] += ":"
my_env["PATH"] += backup["VIRTUAL_ENV"]+"/obt/bin_priv"
my_env["PATH"] += ":"
my_env["PATH"] += backup["OBT_ORIGINAL_PATH"]
my_env["PATH"] += ":"
my_env["PATH"] += backup["SPX_WORKSPACE_DIR"]+"/obt.project/bin"
my_env["PATH"] += ":"
my_env["PATH"] += str(spx_path.r8sdk/"sysroots/x86_64-pokysdk-linux/usr/bin/aarch64-poky-linux")

my_env["PYTHONPATH"] = backup["PYTHONPATH"]
my_env["R8_SDK_ROOT"] = backup["OBT_STAGE"]+"/r8toolchain"

r8sdk.run(["bash","--norc","--noprofile","-i"],environment=my_env)
