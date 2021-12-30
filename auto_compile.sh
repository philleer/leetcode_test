#!/bin/bash

time_begin=`date +%Y-%m-%d-%H:%M:%S`
echo [${time_begin}]

current_path=`pwd`
build_path=${current_path}/build
makefile_path=${build_path}/Makefile
cmake_cached_files="${build_path}/CMake* ${build_path}/Makefile ${build_path}/*.cmake"

cd ${build_path}
if [ ! -f "${makefile_path}" ]; then
# if Makefile does not exist
	echo "No makefile found!"
	if [ ! -d ${build_path}/CMakeFiles ]; then
		echo "Not build yet!"
	else
		if [ -n "${cmake_cached_files}" ]; then
			rm -rf ${cmake_cached_files}
		fi
	fi
else
# if Makefile exists, make clean
	echo "make clean..."
	make clean
	if [ -n "${cmake_cached_files}" ]; then
		rm -rf ${cmake_cached_files}
	fi
fi

# if cmakelists.txt does exist, use it to compile
# else exit safely
if [ ! -f ${current_path}/CMakeLists.txt ]; then
	echo "No CMakeLists.txt found!!"
	exit 0
else
	cmake .. && make -j
fi
cd ${current_path}

time_end=`date +%Y-%m-%d-%H:%M:%S`
echo [${time_end}]
