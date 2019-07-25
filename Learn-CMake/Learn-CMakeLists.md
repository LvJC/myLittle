# Learn `CMakeLists.txt` From One Project
- Description:
This `CMakeLists.txt` is from a project about **Collect Data From Kinect**.
This project cannot be source-open, but I show the **directory structure** below.


---
#### Directory Structure

```
wheel_data_acq_loc/
├── boxposeestimator
│   ├── boxposeestimator.cpp
│   ├── boxposeestimator.h
│   ├── CMakeLists.txt
│   └── README.md
├── build
│   ├── boxposeestimator
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   ├── cmake_install.cmake
│   ├── Makefile
│   └── wheel
├── camera3dData.cpp
├── camera3dData.h
├── camera3dDataKinectV2IRLinux.cpp
├── camera3dDataKinectV2IRLinux.h
├── CMakeLists.txt
├── ConfigCameraKinectV2.yaml
└── main_demo_Linux.cpp
```

#### CMakeLists.txt
```txt
cmake_minimum_required(VERSION 2.8)
project(wheel)
set(cmake_build_type debug)
set(CMAKE_CXX_FLAGS "-std=c++11 -g")

message(STATUS "Project: WHEEL")
message(STATUS "Project Directory: ${PROJECT_SOURCE_DIR}")

find_package(OpenCV REQUIRED)
find_package(PCL REQUIRED)
find_package(freenect2 REQUIRED)

# Add the source in project root directory
#aux_source_directory(<dir> <variable>)
aux_source_directory(. DIRSRCS)


# Add header file (.h, .hpp, etc) include directories
###g++ -I### ('../include/')
include_directories(./ ./boxposeestimator)
include_directories(${OpenCV_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS} ${freenect2_INCLUDE_DIRS})
#add_definitions(${OpenCV_DEFINITIONS} ${PCL_DEFINITIONS} ${freenect2_DEFINITIONS})

# Add block directories
add_subdirectory(boxposeestimator)

# Target
add_executable(wheel ${DIRSRCS})
###g++ -L### ('../lib/')
link_directories(${OpenCV_LIBRARY_DIRS} ${PCL_LIBRARY_DIRS} ${freenect2_LIBRARY_DIRS}) 
###g++ -l### (.so)
target_link_libraries(wheel ${PCL_LIBRARIES} 
   ${OpenCV_LIBS}
   ${freenect2_LIBRARIES} 
   boxposeestimator)
```
