1. clone 
2. ```git submodule init``` # clone submodule dependencies
3. ```git submodule update``` # update submodule dependencies
4. create obt staging environment : see https://github.com/tweakoz/ork.build
    ensure this is a subproject of the enviroment using --project <path to spx_imagetest_sanitized>
6. launch the enviroment ```~/.staging-spx/obt-env-launch```
7. spx.goto.root
8. spx.outputfolders.prep.py
9. sudo chown -R user:user tmp
10. spx.docker.build.py
11. spx.kernel.build.py
12. spx.sdk.build.py
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

14. spx.sdk.build.py (again)
15. spx.sdk.install.py
16. spx.user.build.waylandkms.py
17.   
