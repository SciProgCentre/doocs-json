#!/bin/bash

apt update
apt install -y slapd ldap-utils doocs-ldapens-server doocs-watchdog-server doocs-scripts doocs-clientlib-21-7-1-focal1 doocs-singenerator-server doocstools
ln /export/doocs/lib/libDOOCSapi.so.21.7.1-focal1 /export/doocs/lib/libDOOCSapi.so.21.7.1

adduser --disabled-password --gecos "" doocs_user

sed -i "s/oper_gid:.*/oper_gid:\t1000/" /export/doocs/server/watchdog_server/watchdog_server.conf

sed -i "s/SVR.RATE:.*/SVR.RATE:\t0 10000 0 0/" /export/doocs/server/singenerator_server/singenerator_server.conf
# sed -i "s/SVR.RATE:.*/SVR.RATE:\t0 10000 0 0/" /export/doocs/server/singenerator_server/singenerator_CONF.TEMPLATE
