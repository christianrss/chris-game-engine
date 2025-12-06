#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    if (!glfwInit())
    {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1280, 720, "Chris Game Engine", nullptr, nullptr);

    if (window == nullptr)
    {
        std::cout << "Error creating window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //glfwSetWindowPos(window, 2000, 150);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}