#!/bin/bash

docker run -d -it -v `pwd`/scripts:/scripts --add-host=host.docker.internal:host-gateway --name doocs-env doocs-env
docker exec doocs-env /scripts/start.sh
