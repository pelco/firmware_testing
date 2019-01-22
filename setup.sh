#!/usr/bin/env bash

# Exit on error
set -e

# Remove tools folder
rm -rf tools

# Create folder to store/build tools
mkdir tools

# Get CppUTest Framework
git clone https://github.com/cpputest/cpputest.git tools/cpputest
# Build latest (v3.8) release
cd tools/cpputest
git checkout tags/v3.8
./autogen.sh
./configure
make
cd -

# Get LCOV tool
git clone https://github.com/linux-test-project/lcov.git tools/lcov
cd tools/lcov
git checkout tags/v1.13

cd -
