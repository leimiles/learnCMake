cmake_minimum_required(VERSION 3.10.0)      #最小版本
project(CT VERSION 0.1)     #项目名称 项目版本

configure_file(CTConfig.h.in CTConfig.h)        # 配置程序版本文件

add_executable(${PROJECT_NAME} main.cpp) #本CMakeLists 负责生成一个可执行文件名称与项目名称相同，其源文件是 main.cpp

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})        #执行程序需要包含二进制文件目录

add_subdirectory(src)       #构建时包含指定的名为 src 文件夹 


# DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMODE_RESULT}, please check")
        endif()
    endif()
endif()

# CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/thirdParty/glfw/CMakeLists.txt")
    message(FATAL_ERROR "the glfw submodules was not downloaded!")
endif()

add_subdirectory(thirdParty/glfw)       # 构建
# target_include.. 和 target_link_directories 不需要手动添加
target_link_libraries(${PROJECT_NAME} fun glfw) #链接一个名为 fun 的库，到 PROJECT_NAME 这个目标  
