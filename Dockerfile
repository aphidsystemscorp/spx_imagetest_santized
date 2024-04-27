FROM ubuntu:20.04

# Prevent debconf from prompting for input (set noninteractive frontend)
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    gawk wget git-core diffstat unzip texinfo gcc-multilib \
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

# Set up build environment
RUN git clone -b dunfell git://git.yoctoproject.org/poky.git
WORKDIR /home/yocto-user/poky

# Clone the specific meta BSP layer
RUN git clone -b dunfell https://github.com/renesas-rcar/meta-renesas meta-custom

# Copy the entry script into the image
COPY entrypoint.sh /usr/local/bin/entrypoint.sh
RUN sudo chmod +x /usr/local/bin/entrypoint.sh

# Set the entrypoint
ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
CMD ["/bin/bash"]