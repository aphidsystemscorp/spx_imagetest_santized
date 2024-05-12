#!/usr/bin/env python3
#

import os, sys
from obt import pathtools
from obt import command
from obt import path as obt_path
from spx import path as spx_path

output_products = spx_path.root/"output_products"

command.Command(["sudo","rm","-rf",output_products],do_log=True).exec()

pathtools.mkdir(output_products/"cache",parents=True)
pathtools.mkdir(output_products/"sstate-cache",parents=True)
pathtools.mkdir(output_products/"downloads",parents=True)
pathtools.mkdir(output_products/"tmp-glibc",parents=True)
pathtools.mkdir(output_products/"deploy",parents=True)

command.run(["chmod","-R","ugo+rwx",output_products],do_log=True)