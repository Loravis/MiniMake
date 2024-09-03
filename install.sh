#!/bin/bash

if [ `id -u` != 0 ] ; then
    echo "ERROR: Installation requires superuser permissions!"
else
    echo "Building minimake..."
    g++ -std=c++2c -o minimake main.cpp init.cpp compile.cpp auto.cpp misc.cpp whereami.cpp || echo "ERROR: Missing g++ (dependency)"
    echo "Build complete! Setting up..." 

    cp ./minimake /usr/local/bin/minimake
    cp ./minimake.template.conf /usr/local/bin/minimake.template.conf
    cp ./main.template.cpp /usr/local/bin/main.template.cpp

    echo "Installation complete!"
fi