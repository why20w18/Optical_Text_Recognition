#!/bin/bash
#unix compile and run scripts

if [ $# -ne 1 ]; then
	echo "SCRIPT KULLANIM:"
	echo "./cr-UNIX.sh ARGUMAN"
	echo "ARGUMANLAR:"
	echo "debug-compile veya dc"
	echo "compile veya c"
	echo "run veya r"


elif [ "$1" == "compile" ] || [ "$1" == "c" ]; then
	clear
	echo "::UNIX RELASE-COMPILE STARTED::"
	rm -rf build
	mkdir build
	cd build
	cmake -DCMAKE_BUILD_TYPE=Release ..
	make
	echo "::UNIX RELEASE-COMPILE FINISHED::"

elif [ "$1" == "dc" ] || [ "$1" == "debug-compile" ]; then
	clear
	echo "::UNIX DEBUG-COMPILE STARTED::"
	rm -rf build
	mkdir build
	cd build
	cmake -DCMAKE_BUILD_TYPE=Debug ..
	make
	echo "::UNIX DEBUG-COMPILE FINISHED::"



elif [ "$1" == "run" ] || [ "$1" == "r" ]; then
	echo "::UNIX RUN::"
	cd build
	./OPTICAL_TEXT_RECOGNITION

fi