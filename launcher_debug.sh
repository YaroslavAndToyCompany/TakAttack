#!/bin/bash

set -e

mkdir -p build-Debug

cd build-Debug/ && \
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug .. && \
make

cd ..

echo "Launch the program..."
cd build-Debug/bin/
./TakAttack

