cmake_minimum_required(VERSION 3.17)
project(c__primer)

set(CMAKE_CXX_STANDARD 20)

add_executable(lc844 stack/lc844.cpp)
## 遍历项目根目录下所有的 .cpp 文件
#file (GLOB files *.cpp)
#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    add_executable (${exe} ${file})
#    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
#endforeach ()
add_executable(lc1410 string/lc1410.cpp)
add_executable(lc1358 hash/lc1358.cpp)
add_executable(lc1411 dp/lc1411.cpp)
add_executable(lc907 Monotone-stack/lc907.cpp)