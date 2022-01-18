cmake_minimum_required(VERSION 3.21.3)      #最小版本

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(fun fun.cpp) #使用 fun.cpp 这个文件生成一个名为 fun 的库

target_include_directories(fun
    INTERFACE   #使用这个库，必须包含指定的头文件(fun.h)，这个库的构建并不需要此头文件
        ${CMAKE_SOURCE_DIR}/include
)

message("glfw: " ${GLFW_SOURCE_DIR})
message("yuki: " ${YUKI})
message("extra libs: " ${EXTRA_LIBS})
message("prefix path: " ${CMAKE_SYSTEM_PREFIX_PATH})

target_include_directories(fun
    PUBLIC
        "$<BUILD_INTERFACE:${GLFW_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

INSTALL(TARGETS fun DESTINATION bin)    #安装时把这个库放到安装目录的 bin 目录下
INSTALL(FILES ${PROJECT_SOURCE_DIR}/include/users/fun.h DESTINATION include) #安装时把这个放在安装目录的 include 目录下