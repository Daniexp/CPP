#!/bin/bash

docker build ~/Documents/CPP -t pruebas
docker run -it --rm -v=$PWD:/code pruebas
