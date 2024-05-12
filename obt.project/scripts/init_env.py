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
  spxdir = os.path.normpath(project_dir/"..")
  assert(spxbin_dir.exists())

  ##############################################
  # mark ORKID as project
  ##############################################

  obt.env.set("SPX_WORKSPACE_DIR",spxdir)

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

  obt.env.append("OBT_SEARCH_EXTLIST", ".bb:.conf")

  ##############################################

  print(deco.yellow("Initialized Spx Build Enviroment"))
