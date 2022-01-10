# learnCMake

### 1, 最简单的 CMake 构建命令
>* CMake -S 源码位置 -B 构建位置,  例如 CMake -S ../main.cpp -B ./ ( 在上级目录里面找到 main.cpp ，构建在本级目录 )
>* 如果希望使用 MinGW 构建，使用命令 -G， 如 CMake -G "MinGW Makefiles" -S ../main.cpp -B ./ ( 与上句命令相同，使用 MinGW )

### 2, 添加从 git hub 上添加第三方库到 SubModule
>* 前提：一个 git 工程
>* 命令举例: git submodule add https://github.com/glfw/glfw.git thirdParty/glfw
>* 如果要移除这个库，需要在 .git 的 module 中删除