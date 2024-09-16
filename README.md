0. ensure you are using bash, not zsh
1. review ork.build docs : https://github.com/tweakoz/ork.build
2. clone this repo
3. ```cd spx_imagetest_santized``` - enter working copy
4. ```git submodule init``` - clone submodule dependencies
5. ```git submodule update``` - update submodule dependencies
6. ```python3 -m venv .venv``` - create virtual env 
7. ```source .venv/bin/activate``` - activate virtual env 
8. ```pip3 install ork.build==0.0.214``` install ork.build into virtual env
9. ```obt.env.create.py --staging .staging --project .``` - create obt staging environment : see https://github.com/tweakoz/ork.build
10. launch the environment ```~/.staging/obt-launch-env```
11. ```spx.outputfolders.prep.py``` - create output folders
12. ```sudo chown -R $USER:$USER tmp``` - fix permissions
13. ```spx.docker.build.py``` - build yocto docker image
14. ```spx.kernel.build.py``` - build the r8 kernel
15. build error may occur - the yocto build is not deterministically stable - there may be an incomplete build DAG in yocto.
   - see https://lists.yoctoproject.org/g/yocto/topic/date_and_time_in/86967072 for context
   - see https://community.renesas.com/automotive/gateway/f/forum/32314/error-when-building-sdk-v3-16-1-for-s4sk

    example errors included below:
   
   ./tmp/work/x86_64-linux/gdbm-native/1.18.1-r0/gdbm-1.18.1/src/version.c : line 29 

```
" (built " __DATE__ " " __TIME__ ")"
```

./tmp/work/x86_64-linux/lzop-native/1.04-r0/lzop-1.04/src/help.c
"\n$" "Id: lzop " LZOP_VERSION_STRING " built " LZOP_BUILD_DATE_TIME " $\n";

./tmp/work/x86_64-linux/unzip-native/1_6.0-r5/unzip60/unix/unix.c : line 1712

```
#ifdef __DATE__
      " on ", __DATE__
#else
      "", ""
#endif
    );
``` 

16. ```spx.kernel.build.py``` - repeatedly until build succeeds,
                              
- sometimes for a given build this never happens
- in this case ```git clean -fdx``` , ensure working folder is entirely clean, and try again (go back to step 11) ...

18. ```spx.sdk.build.py``` - to build the r8 sdk
19. ```spx.sdk.install.py``` - install the r8 sdk we just built
20. ```spx.r8sdk.sh.py``` - enter r8 sdk subshell 
21. ```spx.user.build.waylandkms.py``` - build wayland kms
22.   
