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
