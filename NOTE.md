### 1, 最简单的 CMake 构建命令
>* CMake -S 源码位置 -B 构建位置,  例如 CMake -S ../main.cpp -B ./ ( 在上级目录里面找到 main.cpp ，构建在本级目录 )
>* 如果希望使用 MinGW 构建，使用命令 -G， 如 CMake -G "MinGW Makefiles" -S ../main.cpp -B ./ ( 与上句命令相同，使用 MinGW )

### 2, 添加从 git hub 上添加第三方库到 SubModule
>* 前提：一个 git 工程
>* 命令举例: git submodule add https://github.com/glfw/glfw.git thirdParty/glfw
>* 如果要移除这个库，需要在 .git 的 module 中删除
>* 一旦导入第三方库，可以查看 include 指令就能找到该库的文件

### 3, 连续添加三个 .bat 文件, build.bat, configure.bat, run.bat ( windows 系统上，出现了不识别 #! 和 找不到指定路径的错误 )
>* coinfigure.bat 的作用是用来配置 cmake -S -B 的命令, cmake -S ./ -B ./build ( 源码在本级目录，构建到 build 目录下 )
>* build.bat 的作用是用来配置 make 命令, cd ./build ; make ( 先将当前位置跳至 build 目录下，然后调用 make 命令, 这里有两句命令，中间用分号隔开 )
>* run.bat 的作用在构建完成后呼叫可执行的程序，直接运行, cd ./build ; ./CT ( 先将当前位置跳至 build 目录下，运行名为 CT 的可执行程序 )

### 4, 在构建 glfw 库时，可以看到其自带的 CMakeLists.txt 中有一些 option 选项，可以通过两个方法来控制 option 的开关
>* 首先需要在主函数的 CMakeLists.txt 中，通过 add_subdirectory 命令包含第三方库的目录， 这样才能参与构建，前提是第三方库都有自己的 CMakeLists.txt
>* 在 configure.bat 中使用命令 -D"option名称"="ON或者OFF"，例如 cmake -DGLFW_BUILD_DOCS=OFF -S ./ -B ./build ( 注意空格的使用 , 这种方法可以不使用 VSCODE 自动的 configure 来控制 cmake 配置
>* 如果仍然是使用 VSCODE 的 configure 控制，必须在第三方库自己的 CMakeLists.txt 中将对应的 option 关闭 （ 不推荐 ）
>* 构建完成后，会生成静态库 .a 或者 .lib 文件或者共享库 .so 或者 .dll 文件

### 5, 构建完成后, 如果要使用第三方库，需要首先将第三方库的头文件包含进来
>* 头文件通常在第三方库的 include 文件夹下，例如 #include "thirdParty/glfw/include/GLFW/glfw3.h"

