# Learn `CMakeLists.txt` From One Project
- Description:
This `CMakeLists.txt` is from a project about **Collect Data From Kinect**.
This project cannot be source-open, but I show the **directory structure** below.

## Commonly-Used Methods
1.  `cmake_minimum_required`
```
cmake_minimum_required(VERSION 2.8)
```
设置最小cmake版本号。

2. `project`
```
project(<project_name>)
```
设置工程名称，后面就可以用 `${PROJECT_NAME}` 来调用。 

3. `set`

举例：
```txt
set(CMAKE_CXX_FLAGS "-std=c++11 -g")
```
设置 `CMAKE_CXX_FLAGS`，比如可以加入C++11标准和gdb调试的支持。

4. `add_subdirectory` 

有多目录时，可以先将其他目录里的文件编译成静态库再由 main 函数调用。
根目录 `CMakeLists.txt` 中添加：
```txt
add_subdirectory(<sub_dir>)
```
`<sub_dir>` 不加引号。
然后子目录 `CMakeLists.txt` 中使用 `aux_source_dir` 和 `add_library`，见 5 和 6。

5. `add_library` 
```
add_library(<name> [STATIC | SHARED | MODULE]
            [EXCLUDE_FROM_ALL]
            [source1] [source2] [...])
```

`ADD_LIBRARY` creates an static library from the listed sources.
`STATIC`、`SHARED`和`MODULE`的作用是指定生成的库文件的类型。
- `STATIC`库是目标文件的归档文件，在链接其它目标的时候使用。**默认使用类型**。
- `SHARED`库会被动态链接（动态链接库），在运行时会被加载。
- `MODULE`库是一种不会被链接到其它目标中的插件，但是可能会在运行时使用dlopen-系列的函数。
默认状态下，库文件将会在于源文件目录树的构建目录树的位置被创建，该命令也会在这里被调用。

语法中的source1 source2分别表示各个源文件。

6. `aux_source_directory`
```txt
aux_source_directory(./ DIR_BPE_SRCS)
add_library(boxposeestimator ${DIR_BPE_SRCS})
```
查找当前目录下的所有源文件并将名称保存到 `DIR_BPE_SRCS` 变量

7. `include_directories`
指定头文件(\*.h, \*.hpp)所在路径('/path/to/include/')。

相当于 `g++ -I`。

8. `add_executable`
```txt
add_executable(wheel ${DIRSRCS})
```
将 `${DIRSRCS}` 下所有的源文件编译成一个名称为 wheel 的可执行文件。

9. `link_directories`
主要是指定要链接的库文件的路径('/path/to/lib/')，该指令有时候不一定需要。因为find_package和find_library指令可以得到库文件的绝对路径。
不过自己写的动态库文件放在自己新建的目录下时，可以用该指令指定该目录的路径以便工程能够找到。

相当于 `g++ -L`。

10. `target_link_libraries`
指定要链接的库文件(.so)。

相当于 `g++ -l`


---
## Directory Structure
这里展示我这个工程的文件树结构。
```bash
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


---
有两个 `CMakeLists.txt` 文件。
1. `wheel_data_acq_loc/CMakeLists.txt`
```txt
cmake_minimum_required(VERSION 2.8)
project(wheel)
# 设置debug模式
set(cmake_build_type debug)
# 设置支持C++11标准和支持gdb调试
set(CMAKE_CXX_FLAGS "-std=c++11 -g")

# 打印
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

2. `wheel_data_acq_loc/boxposeestimator/CMakeLists.txt`
```txt
aux_sourcedirectory(. DIR_BPE_SRCS)
add_library(boxposeestimator ${DIR_BPE_SRCS})
```
