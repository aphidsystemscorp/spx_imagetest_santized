#!/bin/bash

WORK=`pwd`
echo $WORK

git clone git://git.yoctoproject.org/poky
git clone git://git.openembedded.org/meta-openembedded
git clone https://github.com/renesas-rcar/meta-renesas.git

cd $WORK/poky
git checkout -b tmp 74b22db6879b388d700f61e08cb3f239cf940d18
cd $WORK/meta-openembedded
git checkout -b tmp 814eec96c2a29172da57a425a3609f8b6fcc6afe
cd $WORK/meta-renesas
git checkout -b tmp 194beecc5398ff04f8b350902560158d2c32d91b

case "$1" in
"all" | "grayhawk" | "whitehawk" | "eagle" | "condor")
    echo "Use build configuration for $1 board"
    ;;
*)
    echo "Provide board name. Supported boards: grayhawk, whitehawk, condor, eagle."
    exit -1
    ;;
esac

case "$2" in
"bsp" | "adas")
    echo "Use build option $2 for $1 board"
    ;;
*)
    echo "Provide build option. Supported option: bsp, adas."
    exit -1
    ;;
esac

BOARD=$1
OPTION=$2

build_function () {
cd $WORK

source $WORK/poky/oe-init-build-env build-$1-$2

cp $WORK/meta-renesas/meta-rcar-bsp/docs/sample/conf/$1/poky-gcc/$2/*.conf conf/

echo "The build directory is $(pwd) "

if [ $2 = "bsp" ]; then
    echo "Run command: #bitbake rcar-image-minimal"
    bitbake rcar-image-minimal
elif [ $2 = "adas" ]; then
    echo "Run command: #bitbake rcar-image-adas"
    bitbake rcar-image-adas
fi
}

if [ $BOARD = "all" ]; then
    build_function grayhawk $OPTION
    build_function whitehawk $OPTION
    build_function condor $OPTION
else
    build_function $BOARD $OPTION
fi
