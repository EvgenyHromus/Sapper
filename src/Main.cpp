#include <iostream>
#include "../lib/glfw3.h"
#include "ErrorManager.cpp"
#include "Game.cpp"
#include "Graphics.cpp"
using namespace std;

int main() {
    if (!glfwInit()) { ErrorSet 0x0001 CallError } // Вернуть ошибку 1 если glfw не инициализирован
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello GLFW", NULL, NULL); // Создание окна glfw
    if (!window) { glfwTerminate(); ErrorSet 0x0002 CallError } // Вернуть ошибку 2 если окно не создалось
    glfwMakeContextCurrent(window); // Выбрать контекст для glfw
    while (!glfwWindowShouldClose(window)) { // Главный цикл
        glClearColor(0.0f,0.0f,0.0f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate(); // Уничтожить glfw
    ErrorSet 0x0000 CallError // Вернуть тестовую ошибку
}