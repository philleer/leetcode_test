## Project tree

```bash
.
├── 3rdparty
│   ├── gflags
│   ├── glog
│   └── googletest
├── CMakeLists.txt
├── Testing
│   └── Temporary
├── auto_compile.sh
├── bin
│   ├── myclass
│   ├── myclass_test
│   ├── playground
│   ├── simple_test
│   └── template
├── build
├── src
│   ├── myclass.cc
│   ├── myclass.h
│   ├── playground.c
│   ├── template.c
│   └── utils
└── test
    ├── CMakeLists.txt
    ├── myclass_test.cc
    └── simple_test.cc
```

- `3rdparty`: embeded submodule such as gflags/googletest/glog etc
- `CMakeLists.txt`: top level cmake file
- `Testing`: auto-created dir when use gtest
- `auto_compile.sh`: command line script to simplify input
- `bin/build`: dir to store executable files or temporary building cache files respective
- `src`: source files and include headers
- `test`: unit test files

## Dependencies required

- **system information**
	```bash
	macOS Monterey
	版本 12.1
	MacBook Pro (13-inch, 2016, Two Thunderbolt 3 ports)
	2 GHz 双核Intel Core i5
	8 GB 1867 MHz LPDDR3
	Intel Iris Graphics 540 1536 MB
	```

- **clang**
	```bash
	cv@my-MBP playground-test % clang --version
	Apple clang version 13.0.0 (clang-1300.0.29.30)
	Target: x86_64-apple-darwin21.2.0
	Thread model: posix
	InstalledDir: /Library/Developer/CommandLineTools/usr/bin
	```

- **cmake**
	```bash
	cv@my-MBP playground-test % cmake --version
	cmake version 3.22.1
	
	CMake suite maintained and supported by Kitware (kitware.com/cmake).
	```

- **make**
	```bash
	cv@my-MBP playground-test % make --version
	GNU Make 3.81
	Copyright (C) 2006  Free Software Foundation, Inc.
	This is free software; see the source for copying conditions.
	There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
	
	This program built for i386-apple-darwin11.3.0
	```

And the dependent extern libs are adopted as follows:

- **gflags**
	```bash
	git clone https://github.com/gflags/gflags.git
	
	cd gflags
	
	git checkout v2.2.2
	
	git checkout -b v2.2.2
	```

- **glog**
	```bash
	git clone https://github.com/google/glog.git
	
	cd glog
	
	git checkout v0.5.0
	
	git checkout -b v0.5.0
	```

- **googletest**
	```bash
	git clone https://github.com/google/googletest.git
	
	cd googletest
	
	git checkout release-1.11.0
	```


## How to use

- Execute cmake and then make

This is used when first cloned or need reconstruct program tree

```bash
./auto_compile.sh cmake
```

- Execute only make

When we already compile and link those dependencies, we need only make clean and make, and this is the `Default` operation

```bash
./auto_compile.sh
```


