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
RUN useradd -m yocto-user
RUN echo "yocto-user:yocto" | chpasswd
RUN echo 'yocto-user ALL=(ALL) NOPASSWD: ALL' > /etc/sudoers.d/yocto-user

USER yocto-user
WORKDIR /home/yocto-user

# Set up locale
RUN sudo locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LC_ALL en_US.UTF-8

# Clone the specific meta BSP layer
RUN git clone -b dunfell https://github.com/renesas-rcar/meta-renesas meta-renesas

# Set up build environment
RUN git clone -b dunfell git://git.yoctoproject.org/poky.git
WORKDIR /home/yocto-user/poky
RUN git checkout bdfabf0409896e44ee6bd4a94cf43beb6b1c4490
WORKDIR /home/yocto-user

# Setup build environment and fetch all necessary sources
RUN /bin/bash -c "source oe-init-build-env && bitbake --runall=fetch core-image-minimal"

#WORKDIR /home/yocto-user/poky
#source oe-init-build-env

WORKDIR /home/yocto-user
RUN git clone -b dunfell https://github.com/openembedded/meta-openembedded.git
WORKDIR /home/yocto-user/meta-openembedded
RUN git checkout 9d722e88d79e3a19d2ae07ac922109c18e2f5559

RUN mkdir  /home/yocto-user/build

WORKDIR /home/yocto-user/
CMD ["/bin/bash","-c","source ~/poky/oe-init-build-env && bash"]