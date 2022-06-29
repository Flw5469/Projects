#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    glfwInit();
    GLFWwindow* newwin = glfwCreateWindow(200, 600, "on9", NULL, NULL);

    if (!newwin)
    {

        std::cout << "cant open!" << std::endl;
        glfwTerminate();
        return -1;


    };
    glfwMakeContextCurrent(newwin);

    while (!glfwWindowShouldClose(newwin)) {
        glfwPollEvents();//respond

    }



    glfwDestroyWindow(newwin);
    glfwTerminate();
    return 0;
}