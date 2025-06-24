#ifndef Game_CPP
#define Game_CPP

#include <fstream>
#include <string>
#include <random>
#include <time.h>

int getRandNum(int min, int max);
void checkWin();
void gameInit();
void failGame();
bool tileOnField(int xPos, int yPos);
int minesNearby(int xPos, int yPos);
void tileFlagChange(int xPos, int yPos);
void tileOpen(int xPos, int yPos);

// Общие значения (Хотите меняйте)
#define WINDOW_HEIGHT 700
#define WINDOW_WIGTH 700
#define MAP_HEIGHT 15
#define MAP_WIGTH 15
#define MAP_MINE_PERCENTAGE 10

typedef struct // Структура для ячейки
{
    bool mine = false;
    bool flag = false;
    bool open = false;
    int minesNearby = 0;
} Tile;

Tile Field[MAP_HEIGHT][MAP_WIGTH]; // Игровое поле из ячеек

// Другие переменные
int allMines = std::round((MAP_HEIGHT * MAP_WIGTH * 1.0) / 100 * MAP_MINE_PERCENTAGE);
bool fail = false;
bool win = false;

int getRandNum(int min, int max) // Рандомное число в деапозоне
{
    return min + std::rand() % (max - min + 1);
}

void checkWin() // Проверка победы
{
    int openTiles = 0;
    for (int xTile = 0; xTile < MAP_WIGTH; xTile++) // Перебор ячеек на подсчёт свободных
    {
        for (int yTile = 0; yTile < MAP_HEIGHT; yTile++)
        {
            if (Field[yTile][xTile].open)
            {
                openTiles++;
            }
        }
    }
    if (openTiles == MAP_HEIGHT * MAP_WIGTH - allMines) // Проверка того что кол-во открытых ячеек совпадает с кол-вом ячеек карты - мины
    {
        win = true;
    }
}

void gameInit() // Инициализация игры
{
    srand(time(0)); // Установка сида рандома по времени
    fail = false;
    win = false;
    for (int xTile = 0; xTile < MAP_WIGTH; xTile++) // Очистка поля
    {
        for (int yTile = 0; yTile < MAP_HEIGHT; yTile++)
        {
            Field[yTile][xTile].minesNearby = 0;
            Field[yTile][xTile].mine = false;
            Field[yTile][xTile].flag = false;
            Field[yTile][xTile].open = false;
        }
    }
    int mines = 0; 
    while (mines < allMines) // Установка мин
    {
        int xPos = getRandNum(0, MAP_HEIGHT - 1);
        int yPos = getRandNum(0, MAP_WIGTH - 1);
        if (!Field[yPos][xPos].mine)
        {
            mines++;
            Field[yPos][xPos].mine = true;
        }
    }
    for (int xTile = 0; xTile < MAP_WIGTH; xTile++) // Установка чисел соприкосающихся мин
    {
        for (int yTile = 0; yTile < MAP_HEIGHT; yTile++)
        {
            if (!Field[yTile][xTile].mine)
            {
                Field[yTile][xTile].minesNearby = minesNearby(xTile, yTile);
            }
        }
    }
}

void failGame() // Проигрыш
{
    fail = true;
    for (int xTile = 0; xTile < MAP_WIGTH; xTile++)
    {
        for (int yTile = 0; yTile < MAP_HEIGHT; yTile++)
        {
            Field[yTile][xTile].open = true;
        }
    }
}

void tileOpen(int xPos, int yPos) // Функция открытия ячейки
{
    if (!Field[yPos][xPos].open)
    {
        Field[yPos][xPos].open = true;
        if (Field[yPos][xPos].mine)
        {
            failGame();
        }
        else // Рекурсия чтобы открыть все соприкосающиеся ячейки если на этой ячейке 0
        {
            if (Field[yPos][xPos].minesNearby == 0)
            {
                for (int xOffset = -1; xOffset < 2; xOffset++)
                {
                    for (int yOffset = -1; yOffset < 2; yOffset++)
                    {
                        if (tileOnField(xPos + xOffset, yPos + yOffset))
                        {
                            tileOpen(xPos + xOffset, yPos + yOffset);
                        }
                    }
                }
            }
        }
    }
}

void tileFlagChange(int xPos, int yPos) // Функция установки/убирания флага
{
    if (!Field[yPos][xPos].open)
    {
        Field[yPos][xPos].flag = !Field[yPos][xPos].flag;
    }
}

int minesNearby(int xPos, int yPos) // Функция подсчёта кол-ва мин вокруг ячейки
{
    int minesFinded = 0;
    for (int xOffset = -1; xOffset < 2; xOffset++)
    {
        for (int yOffset = -1; yOffset < 2; yOffset++)
        {
            if (tileOnField(xPos + xOffset, yPos + yOffset))
            {
                if (Field[yPos + yOffset][xPos + xOffset].mine)
                {
                    minesFinded++;
                }
            }
        }
    }
    return minesFinded;
}
bool tileOnField(int xPos, int yPos) // Функция проверки что ячейка на поле
{
    if (xPos > -1 && yPos > -1 && yPos < MAP_HEIGHT && xPos < MAP_WIGTH)
    {
        return true;
    }
    return false;
}

#endif