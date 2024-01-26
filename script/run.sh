#!/bin/bash

# replace with path to this script (type pwd and copy the path)
cd 

# run cmake
cmake ..

# run make
make

if [ -f "GitCliContributions" ]; then
    ./GitCliContributions
else
    echo "Build failed or executable not found."
fi
