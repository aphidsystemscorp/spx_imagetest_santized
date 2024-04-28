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
RUN useradd -m yoctodev
RUN echo "yoctodev:yocto" | chpasswd
RUN echo 'yoctodev ALL=(ALL) NOPASSWD: ALL' > /etc/sudoers.d/yoctodev

USER yoctodev
WORKDIR /home/yoctodev

# Set up locale
RUN sudo locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LC_ALL en_US.UTF-8

# Clone the specific meta BSP layer
RUN git clone -b dunfell https://github.com/renesas-rcar/meta-renesas meta-renesas

# Set up build environment
RUN git clone -b dunfell git://git.yoctoproject.org/poky.git
WORKDIR /home/yoctodev/poky
RUN git checkout bdfabf0409896e44ee6bd4a94cf43beb6b1c4490
WORKDIR /home/yoctodev

RUN git clone -b dunfell https://github.com/openembedded/meta-openembedded.git
WORKDIR /home/yoctodev/meta-openembedded
RUN git checkout 9d722e88d79e3a19d2ae07ac922109c18e2f5559

WORKDIR /home/yoctodev
RUN mkdir -p /home/yoctodev/build/conf
COPY --chmod=0444 --chown=yoctodev bblayers.conf /home/yoctodev/build/conf/bblayers.conf
COPY --chmod=0444 --chown=yoctodev local.conf /home/yoctodev/build/conf/local.conf
COPY --chmod=0500 --chown=yoctodev _init_env.sh /home/yoctodev/_init_env.sh
RUN /bin/bash -c /home/yoctodev/_init_env.sh

#COPY --chmod=0500 --chown=yoctodev _build_rcar.sh /home/yoctodev/build/build_rcar.sh

WORKDIR /home/yoctodev
CMD ["/bin/bash","-c","source ~/poky/oe-init-build-env && bash"]