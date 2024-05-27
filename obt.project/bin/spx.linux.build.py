#!/usr/bin/env python3

from obt import command, pathtools, host

command.run(["spx.kernel.patch.py"])
command.run(["spx.docker.launch.py", "-c", "./build_linux.sh"])
