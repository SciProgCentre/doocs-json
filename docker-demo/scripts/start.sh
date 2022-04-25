#!/bin/bash

systemctl start slapd.service
systemctl start rpcbind.service
systemctl start doocs-watchdog.service
cd /export/doocs/server/singenerator_server && ./singenerator_server &
sudo -u doocs_user LD_LIBRARY_PATH=/export/doocs/lib/ /scripts/doocs_zmq_app tcp://host.docker.internal &
