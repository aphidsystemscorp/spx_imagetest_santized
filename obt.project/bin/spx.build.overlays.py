#!/usr/bin/env python3

from obt import command

command.run(["spx.build.waylandkms.py"], do_log=True)
command.run(["spx.build.libgbm.py"], do_log=True)
command.run(["spx.build.cefproject.py"], do_log=True)
