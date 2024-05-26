from spx import path as spx_path
from obt import command, path
from functools import lru_cache

#########################################################################

@lru_cache(maxsize=None)
def sdk_environment():
  sdk_env = command.eval_bash_source_env(path.stage()/"r8toolchain"/"environment-setup-aarch64-poky-linux")
  for k,v in sdk_env.items():
    sdk_env[k] = v
  return sdk_env

#########################################################################

def run( cmdlist, working_dir=None, environment=None, do_log=True):
  merged_env = sdk_environment()
  if environment is not None:
    for item in environment.items():
      merged_env[item[0]] = item[1]
  
  for item in merged_env.items():
    print(item)
  command.run( cmdlist, 
               working_dir=working_dir, 
               environment=merged_env, 
               do_log=do_log )

#########################################################################
