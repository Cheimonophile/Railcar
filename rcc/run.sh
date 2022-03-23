#!/bin/sh -xe
cd $(dirname $0)
./c.sh
./build/rcc ./test/test.rc