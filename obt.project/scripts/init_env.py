###############################################################################
# Orkid Media Engine
# Copyright 2010-2022, Michael T. Mayers
# email: michael@tweakoz.com
###############################################################################
# orkid as project initialization

import os
import obt.deco
import obt.env
import obt.path

def setup():

  this_dir = obt.path.directoryOfInvokingModule(__file__)

  ##############################################
  # compute paths
  ##############################################

  deco = obt.deco.Deco()
  file_path = os.path.realpath(__file__)
  scripts_dir = obt.path.Path(os.path.dirname(file_path))
  project_dir = scripts_dir/".."
  spxbin_dir = project_dir/"bin"
  spxdir = obt.path.Path(os.path.normpath(project_dir/".."))
  tmpdir = spxdir/"tmp"
  workdir = tmpdir/"work"
  workshdir = spxdir/"work-shared"
  assert(spxbin_dir.exists())

  crossgccdir = obt.path.Path("/home/yoctodev/build/tmp/work")/"x86_64-linux"/"gcc-cross-aarch64"/"9.3.0-r0"/"sysroot-destdir"/"home"/"yoctodev"/"build"/"tmp"/"work"/"x86_64-linux"/"gcc-cross-aarch64"/"9.3.0-r0"/"recipe-sysroot-native"/"usr"/"bin"/"aarch64-poky-linux"
  
  ##############################################
  # mark ORKID as project
  ##############################################

  obt.env.set("SPX_WORKSPACE_DIR",spxdir)
  obt.env.set("SPX_KERNELSRC_DIR",workshdir/"whitehawk"/"kernel-source")
  obt.env.set("SPX_FSROOTSTAGE_DIR",workdir/"whitehawk-poky-linux"/"rcar-image-adas-dev"/"1.0-r0"/"rootfs")
  obt.env.set("SPX_TGT_CXX", crossgccdir/"aarch64-poky-linux-g++")
  obt.env.set("SPX_TGT_CC", crossgccdir/"aarch64-poky-linux-gcc")

  ##############################################
  # add orkid scripts to enviromment PATH
  ##############################################

  obt.env.prepend("PATH",spxbin_dir)

  obt.env.append("PYTHONPATH",this_dir)

  ##############################################
  # add search paths
  #  for obt.find.py
  ##############################################

  obt.env.append("OBT_SEARCH_PATH",project_dir/"obt.project")
  obt.env.append("LUA_PATH",project_dir/"ork.data"/"src"/"scripts"/"?.lua")

  ##############################################
  # add search extensions
  #  for obt.find.py
  ##############################################

  obt.env.append("OBT_SEARCH_EXTLIST", ".bb:.bbappend:.bbclass:.conf")
  obt.env.append("OBT_SEARCH_EXTLIST", ".sh:.patch:.ini:.md")

  ##############################################

  print(deco.yellow("Initialized Spx Build Enviroment"))

def extend_bashrc():
  return [
    "spx.goto.root() { cd ${SPX_WORKSPACE_DIR}; };\n",
    "spx.goto.fsrootstage() { cd ${SPX_FSROOTSTAGE_DIR}; };\n",
    "spx.goto.kernelsrc() { cd ${SPX_KERNELSRC_DIR}; };\n"
    ];