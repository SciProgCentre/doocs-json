#!/bin/bash

docker build -t doocs-env .
docker run -d -it -v `pwd`/scripts:/root/scripts --name doocs-env doocs-env
docker exec -it doocs-env /root/scripts/init.sh
docker commit doocs-env doocs-env
docker kill doocs-env
docker rm doocs-env
echo "Initialization finished"
