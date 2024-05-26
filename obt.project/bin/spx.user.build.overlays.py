#!/usr/bin/env python3

from obt import command

command.run(["spx.user.build.waylandkms.py"], do_log=True)
command.run(["spx.user.build.libgbm.py"], do_log=True)
command.run(["spx.user.build.cefproject.py"], do_log=True)
