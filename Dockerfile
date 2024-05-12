FROM ubuntu:20.04
#FROM arm64v8/ubuntu:20.04

# Prevent debconf from prompting for input (set noninteractive frontend)
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    gawk wget git-core diffstat unzip texinfo \
    build-essential chrpath socat cpio python3 python3-pip python3-pexpect \
    xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa \
    libsdl1.2-dev pylint3 xterm tzdata 

RUN apt-get update && apt-get install -y sudo locales 
RUN apt-get -y install vim

# Set the timezone
RUN ln -fs /usr/share/zoneinfo/America/Denver /etc/localtime && dpkg-reconfigure --frontend noninteractive tzdata

# Create a non-root user
RUN groupadd -g 9000 yoctodev
RUN useradd -m yoctodev -u 9000 -g 9000
RUN echo "yoctodev:yocto" | chpasswd
RUN echo 'yoctodev ALL=(ALL) NOPASSWD: ALL' > /etc/sudoers.d/yoctodev

USER yoctodev
WORKDIR /home/yoctodev

# Set up locale
RUN sudo locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LC_ALL en_US.UTF-8

# Clone the specific meta BSP layer
COPY --chown=yoctodev submodules/meta-openembedded /home/yoctodev/meta-openembedded
COPY --chown=yoctodev submodules/meta-renesas /home/yoctodev/meta-renesas
COPY --chown=yoctodev submodules/meta-browser /home/yoctodev/meta-browser
COPY --chown=yoctodev submodules/poky /home/yoctodev/poky
COPY --chown=yoctodev submodules/rcar-gfx /home/yoctodev/rcar-gfx
#RUN chmod 755 /home/yoctodev/meta-openembedded
WORKDIR /home/yoctodev/rcar-gfx/gfxdrv
#RUN tar xvf GSX_KM_V4H.tar.bz2

WORKDIR /home/yoctodev
RUN mkdir -p /home/yoctodev/build/conf

CMD ["/bin/bash","-c","source ~/poky/oe-init-build-env && bash"]