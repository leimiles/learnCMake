cmake_minimum_required(VERSION 3.10.0)      #最小版本
project(CT)     #项目名称
add_executable(${PROJECT_NAME} main.cpp) #本CMakeLists 负责生成一个可执行文件名称与项目名称相同，其源文件是 main.cpp
add_subdirectory(src)       #构建时包含指定的名为 src 文件夹 
target_link_libraries(${PROJECT_NAME} fun)      #链接一个名为 fun 的库，到 PROJECT_NAME 这个目标