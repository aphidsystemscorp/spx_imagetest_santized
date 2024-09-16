Image Builder for Renesas R-Car V4H WhiteHawk 

**First Steps**

0. ensure you are using bash, not zsh
1. review ork.build docs : https://github.com/tweakoz/ork.build

**Prepare Working Copy**

2. clone this repo
3. ```cd spx_imagetest_santized``` - enter working copy
4. ```git submodule init``` - clone submodule dependencies
5. ```git submodule update``` - update submodule dependencies

**Build Staging Environment**

6. ```python3 -m venv .venv``` - create virtual env 
7. ```source .venv/bin/activate``` - activate virtual env 
8. ```pip3 install ork.build==0.0.214``` install ork.build into virtual env
9. ```obt.env.create.py --staging .staging --project .``` - create obt staging environment : see https://github.com/tweakoz/ork.build
10. launch the environment ```~/.staging/obt-launch-env```

**More working copy preparations**

11. ```spx.outputfolders.prep.py``` - create output folders
12. ```sudo chown -R $USER:$USER tmp``` - fix permissions

**Build Yocto Docker Image**

13. ```spx.docker.build.py``` - build yocto docker image

**Build Kernel**

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

**Build R8 SDK**

18. ```spx.sdk.build.py``` - to build the r8 sdk, like the kernel build it is not deterministic, repeat until it succeeds...
19. ```spx.sdk.install.py``` - install the r8 sdk we just built

**Chromium/Wayland/Ozone**

Now we would like to build chromium targeting wayland (using ozone platform layer)
see: https://chromium.googlesource.com/chromium/src/+/HEAD/docs/ozone_overview.md
Of course to do this, we will need wayland for whitehawk v4h.

**Wayland Attempts**

At this point you can try and configure yocto to build wayland for whitehawk, 
 unfortunately due to issues in the yocto layers, I am unable to set a configuration 
 that builds or runs successfully. 

With this I attempted to build wayland myself.....
   
**Activate R8 SDK**

20. ```spx.r8sdk.sh.py``` - "push" r8 sdk subshell on shell stack (type exit to pop)

**Build Wayland dependency stack**

22. ```spx.user.build.waylandkms.py``` - build wayland kms
23. ```spx.user.build.libgbm.py``` - build libgbm
24. trying to find a version of wayland that build using the r8sdk proved difficult.
    wayland's build system requires a lot of specifics on the build host. I am not
    convinced cross compiling wayland for arm on x86 is commonly done. If I were
    moving forward with this - I would build up the arm device's filesystem and
    try to compile natively..
    
**Build Compositor**

2x. ```spx.user.build.compositor.py``` - build compositor test (in <repo>/testprogs/compositor)
