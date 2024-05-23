#!/usr/bin/env python3

import os, sys
from obt import search, path

#################################################################################
SPX_DIR = path.Path(os.environ["SPX_WORKSPACE_DIR"])
KSRC_DIR = path.Path(os.environ["SPX_KERNELSRC_DIR"])
#################################################################################

pathlist = []
pathlist += [SPX_DIR/"submodules"]

#################################################################################

if __name__ == "__main__":
  if not len(sys.argv) == 2:
    print("usage: word")
    sys.exit(1)
  word = sys.argv[1]
  search.execute_at([word],path_list=pathlist,remove_root=SPX_DIR)