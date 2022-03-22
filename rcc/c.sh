#!/bin/sh -e
cd $(dirname $0)
cmake -S . -B build
cd ./build
make
cd ..