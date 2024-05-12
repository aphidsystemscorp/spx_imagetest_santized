from obt import path as ork_path
import os 

def _root():
	return ork_path.Path(os.environ["SPX_WORKSPACE_DIR"])

def __getattr__(name):
  if name == "root":
  	return _root()
  elif name == "obt_project":
  	return _root()/"obt.project"
  elif name == "scripts":
  	return _root()/"obt.project"/"scripts"
  elif name == "modules":
  	return _root()/"obt.project"/"modules"
  return None