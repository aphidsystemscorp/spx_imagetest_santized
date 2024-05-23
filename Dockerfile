FROM ubuntu:20.04
#FROM arm64v8/ubuntu:20.04

# Prevent debconf from prompting for input (set noninteractive frontend)
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    gawk wget git-core diffstat unzip texinfo  \
#    gcc-multilib libarchive-zip-perl \
    build-essential chrpath socat cpio python3 python3-pip python3-pexpect \
    xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa \
    libsdl1.2-dev pylint3 xterm tzdata 
    libncurses5-dev libtinfo-dev

RUN apt-get update && apt-get install -y sudo locales 
RUN apt-get -y install vim

# Set the timezone
RUN ln -fs /usr/share/zoneinfo/America/Denver /etc/localtime && dpkg-reconfigure --frontend noninteractive tzdata

#######################################
ARG HOME=/home/yoctodev
ARG SMR=submodules/meta-renesas
ARG BSP=$SMR/meta-rcar-bsp
ARG SCONF=$BSP/docs/sample/conf
ARG BOARD=whitehawk
ARG DCONF=$HOME/build/conf
ARG SADAS=$SCONF/$BOARD/poky-gcc/adas
ARG DADAS=$HOME/meta-renesas/meta-rcar-adas
ARG SGFX=submodules/rcar-gfx
#######################################

# Create a non-root user
RUN groupadd -g 1000 yoctodev
RUN useradd -m yoctodev -u 1000 -g 1000
RUN echo "yoctodev:yocto" | chpasswd
RUN echo 'yoctodev ALL=(ALL) NOPASSWD: ALL' > /etc/sudoers.d/yoctodev

USER yoctodev
WORKDIR $HOME

# Set up locale
RUN sudo locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LC_ALL en_US.UTF-8


# Clone the specific meta BSP layer
COPY --chown=yoctodev submodules/meta-openembedded $HOME/meta-openembedded
COPY --chown=yoctodev submodules/meta-renesas $HOME/meta-renesas
COPY --chown=yoctodev submodules/meta-browser $HOME/meta-browser
COPY --chown=yoctodev submodules/poky $HOME/poky
COPY --chown=yoctodev $SGFX $HOME/rcar-gfx

COPY --chown=yoctodev $SGFX/gfxdrv/GSX_KM_V4H.tar.bz2 $DADAS/recipes-kernel/kernel-module-gles/kernel-module-gles/
COPY --chown=yoctodev $SGFX/opengl/r8a779g0_linux_gsx_binaries_gles.tar.bz2 $DADAS/recipes-graphics/gles-user-module/gles-user-module/


#RUN chmod 755 $HOME/meta-openembedded
WORKDIR $HOME/rcar-gfx/gfxdrv
#RUN tar xvf GSX_KM_V4H.tar.bz2

WORKDIR $HOME
RUN mkdir -p $HOME/build/conf
COPY --chown=yoctodev $SADAS/bblayers.conf $DCONF/bblayers.conf
COPY --chown=yoctodev $SADAS/local.conf $DCONF/local.conf

ENV KBLD=~/build/tmp/work/whitehawk-poky-linux/linux-renesas/5.10.147+gitAUTOINC+4b2bf1dfb8-r1/linux-whitehawk-standard-build
ENV KSRC=~/build/tmp/work-shared/whitehawk/kernel-source

CMD ["/bin/bash","-c","source ~/poky/oe-init-build-env build && bash"]