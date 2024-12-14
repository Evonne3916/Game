#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{

    /* инициализация glfw */
    if (!glfwInit())
    {
        std::cout << "glfw init failed" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* создание окна */
    GLFWwindow*  pWindow = glfwCreateWindow(640, 480, "Game", nullptr, nullptr);
    if (!pWindow)
    {
        glfwTerminate();
        std::cout << "glfwCreateWindow failed" << std::endl;
        return -1;
    }

    /* контекст opengl для этого окна */
    glfwMakeContextCurrent(pWindow);


    /* инициализация glad */
    if (!gladLoadGL())
    {
        std::cout<< "error" << std::endl;
        return -1;
    }


    /* вывод информации */
    std::cout << "render:" << glGetString(GL_RENDERER) << std::endl;
    std::cout << "opengl ver:" << glGetString(GL_VERSION) << std::endl;


    
    glClearColor(0, 1, 0, 1);

    /* Цикл пока окно открыто */
    while (!glfwWindowShouldClose(pWindow))
    {
        /* очистка буфера цвета */
        glClear(GL_COLOR_BUFFER_BIT);

        /* свап буферов (вертикальная синхронизация) */
        glfwSwapBuffers(pWindow);

        /* позволяет glfw получить данные */
        /* нажатие клавиш, изменение размера окна */
        glfwPollEvents();
    }

    /* освобождение ресурсов */
    glfwTerminate();
    return 0;
}