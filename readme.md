# Introduction 

Here is a simple Material Point Method (MPM) project. The aim os to have a fist look at Thrust Library and Computational mechanics.

**Disclaimer** : Please note that thi project is a work in progress and may contain errors or programming bugs due to its experimental nature. 

# Compilation 

We use **CMake** to compile the project with the following commands :
```
mkdir build && cd build && cmake ..
make -j 
```
# Usage

You can launch the executable named `mpm` with the following command : 
```./mpm <optional_configuration_file>
```

# Prerequisities

The code use Thrust from NVIDIA. The, you must have to install it to compile this project. 

