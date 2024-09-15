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
12. 
    
