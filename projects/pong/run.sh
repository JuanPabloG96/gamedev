#!/bin/bash

set -e

bear -- cmake --build build

echo -e "Running program..\n"

./bin/main
