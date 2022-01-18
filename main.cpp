#include <iostream>
#include <windows.h>
#include "GLFW/glfw3.h"
#include "CTConfig.h"
#ifdef _MODERN_CMAKE
#include "users/fun.h"
#endif

// this function hide the console window
void Stealth()
{
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth, 0);
}

int main(int argc, char* argv[])
{
#ifdef _MODERN_CMAKE
    fun01();
#endif
    //Stealth();
    std::cout << argv[0] << " Version " << CT_VERSION_MAJOR << "." << CT_VERSION_MINOR << std::endl;

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "CMake Window", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}