#!/bin/bash

set -e

mkdir -p build-Release

cd build-Release/ && \
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release .. && \
make

cd ..

echo "Launch the program..."
cd build-Release/bin/
./TakAttack

