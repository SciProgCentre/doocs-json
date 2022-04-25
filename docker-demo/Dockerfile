FROM ubuntu

WORKDIR /root

RUN  apt-get update \
  && apt-get install -y wget gnupg iproute2 lsb-release debconf-utils systemctl libzmqpp-dev \
  && wget -qO - http://doocs.desy.de/pub/doocs/DOOCS-key.gpg.asc | apt-key add - \
  && echo "deb http://doocs.desy.de/pub/doocs `lsb_release -sc` main" > /etc/apt/sources.list.d/doocs.list \
  && apt-get update \
  && printf '#!/bin/sh\nexit 0' > /usr/sbin/policy-rc.d \
  && mkdir /run/sendsigs.omit.d/ \
  && touch /run/sendsigs.omit.d/rpcbind \
  && touch /etc/init.d/doocs_watchdog_epics \
  && touch /etc/init.d/doocs_watchdog