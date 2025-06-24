#ifndef Game_CPP
#define Game_CPP

#include <fstream>
#include <string>
#include <random>
#include <time.h>

#define MAP_HEIGHT 15
#define MAP_WIGTH 15
#define MAP_MINE_PERCENTAGE 10

typedef struct
{
    bool mine = false;
    bool flag = false;
    bool open = false;
    int minesNearby = 0;
} Tile;

Tile Field[MAP_HEIGHT][MAP_WIGTH];
int mines = 0;
int allMines = std::round((MAP_HEIGHT * MAP_WIGTH * 1.0) / 100 * MAP_MINE_PERCENTAGE);
bool fail = false;

int getRandNum(int min, int max)
{
    return min + std::rand() % (max - min + 1);
}

void gameInit()
{
    srand(time(0));
    while (mines < allMines)
    {
        int xPos = getRandNum(0, MAP_HEIGHT - 1);
        int yPos = getRandNum(0, MAP_WIGTH - 1);
        if (!Field[yPos][xPos].mine)
        {
            mines++;
            Field[yPos][xPos].mine = true;
        }
    }
    for (int xTile = 0; xTile < MAP_WIGTH; xTile++)
    {
        for (int yTile = 0; yTile < MAP_HEIGHT; yTile++)
        {
            if (!Field[yTile][xTile].mine) {
                Field[yTile][xTile].minesNearby = minesNearby(xTile, yTile);
            }
        }
    }
    mines = 0;
}

void tileOpen(int xPos, int yPos)
{
    if (!Field[yPos][xPos].open)
    {
        Field[yPos][xPos].open = true;
        if (Field[yPos][xPos].mine)
        {
            fail = true;
        }
        else
        {
            if (Field[yPos][xPos].minesNearby == 0)
            {
                for (int xOffset = -1; xOffset < 2; xOffset++)
                {
                    for (int yOffset = -1; yOffset < 2; yOffset++)
                    {
                        if (tileOnField(xPos + xOffset, yPos + yOffset))
                        {
                            tileOpen(xPos, yPos);
                        }
                    }
                }
            }
        }
    }
}

void tileFlagChange(int xPos, int yPos)
{
    if (!Field[yPos][xPos].open)
    {
        Field[yPos][xPos].flag = !Field[yPos][xPos].flag;
    }
}

int minesNearby(int xPos, int yPos)
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
bool tileOnField(int xPos, int yPos)
{
    if (xPos > -1 && yPos > -1 && yPos < MAP_HEIGHT && xPos < MAP_WIGTH)
    {
        return true;
    }
    return false;
}

#endif