#!/bin/bash

set -e

rm -rf build

mkdir -p bin

cmake -S . -B build \
    -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

bear -- cmake --build build

echo -e "Compilation complete!\n"
