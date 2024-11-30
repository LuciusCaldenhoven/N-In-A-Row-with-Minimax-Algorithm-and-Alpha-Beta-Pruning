#include <GLFW/glfw3.h>
#include <iostream>
#include "GameLogic.h"
#include "AI.h"
#include "Graphics.h"

int main() {
    std::cout << "Enter the size of N for the N-in-a-Row game: ";
    std::cin >> boardSize;
    initializeBoard(boardSize);

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Improved N-in-a-Row", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create the window\n";
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    setupGraphics();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawGame();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
