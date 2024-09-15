1. clone 
2. ```git submodule init``` # clone submodule dependencies
3. ```git submodule update``` # update submodule dependencies
4. create obt staging environment : see https://github.com/tweakoz/ork.build
    ensure this is a subproject of the enviroment using --project <path to spx_imagetest_sanitized>
6. launch the enviroment ```~/.staging-spx/obt-env-launch```
7. ```spx.goto.root``` - change dir to this repo's working copy
8. ```spx.outputfolders.prep.py``` - create output folders
9. ```sudo chown -R user:user tmp``` - fix permissions
10. ```spx.docker.build.py``` - build yocto docker image
11. ```spx.kernel.build.py``` - build the r8 kernel
12. ```spx.sdk.build.py``` - to build the r8 sdk
13. fix build error - replace 
```
#ifdef __DATE__
      " on ", __DATE__
#else
      "", ""
#endif
    );
``` 
with 
```
"", ""
``` 
on line 1712 of: 
```./tmp/work/x86_64-linux/unzip-native/1_6.0-r5/unzip60/unix/unix.c```

14. ```spx.sdk.build.py``` - again, because we fixed the build error
15. ```spx.sdk.install.py``` - install the r8 sdk we just built
16. ```spx.r8sdk.sh.py``` - enter r8 sdk subshell 
17. ```spx.user.build.waylandkms.py``` - build wayland kms
18.   
