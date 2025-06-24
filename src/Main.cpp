#include "../lib/glfw3.h"
#include "ErrorManager.cpp"
#include "Game.cpp"
#include "Graphics.cpp"
#include "Controls.cpp"
using namespace std;

int main()
{
    if (!glfwInit())
    {
        ErrorSet 0x0001 CallError
    } // Вернуть ошибку 1 если glfw не инициализирован
    GLFWwindow *window = glfwCreateWindow(700, 700, "Sapper", NULL, NULL); // Создание окна glfw
    if (!window)
    {
        glfwTerminate();
        ErrorSet 0x0002 CallError
    } // Вернуть ошибку 2 если окно не создалось
    glfwMakeContextCurrent(window);                     // Выбрать контекст для glfw
    glfwSetMouseButtonCallback(window, MouseButton_CB); // Установка обратного вызова для нажатия кнопок мыши
    glfwSetCursorPosCallback(window, CursorSetPos_CB);  // Установка обратного вызова для движения курсора
    gameInit();                                         // Инициализация игры
    while (!glfwWindowShouldClose(window))
    { // Главный цикл
        glClear(GL_COLOR_BUFFER_BIT);
        checkWin();                                     // Проверка на победу
        for (int xTile = 0; xTile < MAP_WIGTH; xTile++) // Отрисовка поля
        {
            for (int yTile = 0; yTile < MAP_HEIGHT; yTile++)
            {
                tileRendController(xTile, yTile);
                glLoadIdentity();
            }
        }
        glfwSwapBuffers(window);
        glfwPollEvents(); // Стандартный режим событий
    }
    glfwTerminate();          // Уничтожить glfw
}