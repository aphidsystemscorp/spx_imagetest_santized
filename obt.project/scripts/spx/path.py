from obt import path as obt_path
import os 

def _root():
	return obt_path.Path(os.environ["SPX_WORKSPACE_DIR"])

def __getattr__(name):
  if name == "root":
  	return _root()
  elif name == "obt_project":
  	return _root()/"obt.project"
  elif name == "scripts":
  	return _root()/"obt.project"/"scripts"
  elif name == "modules":
  	return _root()/"obt.project"/"modules"
  elif name == "r8sdk":
  	return obt_path.stage()/"r8toolchain"
  elif name == "kernel_source":
  	return obt_path.Path(os.environ["SPX_KERNELSRC_DIR"])
  return None