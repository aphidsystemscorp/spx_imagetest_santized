1. clone 
2. ```git submodule init``` # clone submodule dependencies
3. ```git submodule update``` # update submodule dependencies
4. create virtual env : see https://github.com/tweakoz/ork.build
5. ```pip3 install ork.build==0.0.214``` install ork.build into virtual env
6. create obt staging environment : see https://github.com/tweakoz/ork.build
    ensure this is a subproject of the enviroment using --project <path to spx_imagetest_sanitized>
7. launch the environment ```~/.staging-spx/obt-env-launch```
9. ```spx.outputfolders.prep.py``` - create output folders
10. ```sudo chown -R user:user tmp``` - fix permissions
11. ```spx.docker.build.py``` - build yocto docker image
12. ```spx.kernel.build.py``` - build the r8 kernel
13. ```spx.sdk.build.py``` - to build the r8 sdk
14. fix build error - replace 
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
