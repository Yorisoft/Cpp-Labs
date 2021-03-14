# This Dockerfile is used to build an headles vnc image based on Ubuntu
FROM consol/ubuntu-xfce-vnc

USER root

# Setting env
ENV VNC_RESOLUTION=1920x1080 \
    VNC_PW=cpplabs

# Create app directory
WORKDIR /usr/src/app

COPY . ./
# update, install dependencies
RUN apt-get update -y \
    && apt-get install -y sudo \
    && sudo apt-get install -y gcc g++ make ca-certificates wget \
    && curl -sL https://deb.nodesource.com/setup_10.x | bash - \
    && sudo apt-get install -y nodejs \
    && sudo apt-get -y autoremove


RUN whoami \
	&& useradd -m docker && echo "docker:docker" | chpasswd && adduser docker sudo \
    && useradd -m jenkins && echo "jenkins:jenkins" | chpasswd && adduser jenkins sudo
 
#ENTRYPOINT ["/dockerstartup/vnc_startup.sh"]
#CMD /bin/bash
