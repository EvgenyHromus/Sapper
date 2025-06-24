#ifndef Graphics_CPP
#define Graphics_CPP

#include "../lib/glfw3.h"
#include "Game.cpp"
#include <cmath>

void numberRend(int xPos, int yPos, int num, float red, float green, float blue);
void flagRend(int xPos, int yPos);
void tileRend(int xPos, int yPos, float red, float green, float blue, bool mine);
void numberColorController(int xPos, int yPos);

void tileRendController(int xPos, int yPos) // Контроллер который определяет как рендерить ячейку
{
    Tile currentTile = Field[yPos][xPos];
    if (fail)
    {
        if (Field[yPos][xPos].open)
        {
            if (Field[yPos][xPos].mine)
            {
                tileRend(xPos, yPos, 0.7f, 2.0f, 2.0f, true);
            }
            else
            {
                tileRend(xPos, yPos, 0.7f, 2.0f, 2.0f, false);
                numberColorController(xPos, yPos);
            }
        }
        else if (Field[yPos][xPos].flag)
        {
            tileRend(xPos, yPos, 1.0f, 0.2f, 0.2f, false);
            flagRend(xPos, yPos);
        }
        else
        {
            tileRend(xPos, yPos, 1.0f, 0.2f, 0.2f, false);
        }
    }
    else if (win)
    {
        if (Field[yPos][xPos].open)
        {
            if (Field[yPos][xPos].mine)
            {
                tileRend(xPos, yPos, 0.2f, 0.7f, 0.2f, true);
            }
            else
            {
                tileRend(xPos, yPos, 0.2f, 0.7f, 0.2f, false);
                numberColorController(xPos, yPos);
            }
        }
        else if (Field[yPos][xPos].flag)
        {
            tileRend(xPos, yPos, 0.2f, 1.0f, 0.2f, false);
            flagRend(xPos, yPos);
        }
        else
        {
            tileRend(xPos, yPos, 0.2f, 1.0f, 0.2f, false);
        }
    }
    else
    {
        if (Field[yPos][xPos].open)
        {
            if (Field[yPos][xPos].mine)
            {
                tileRend(xPos, yPos, 0.7f, 0.7f, 0.7f, true);
            }
            else
            {
                tileRend(xPos, yPos, 0.7f, 0.7f, 0.7f, false);
                numberColorController(xPos, yPos);
            }
        }
        else if (Field[yPos][xPos].flag)
        {
            tileRend(xPos, yPos, 1.0f, 1.0f, 1.0f, false);
            flagRend(xPos, yPos);
        }
        else
        {
            tileRend(xPos, yPos, 1.0f, 1.0f, 1.0f, false);
        }
    }
}

void numberColorController(int xPos, int yPos)
{ // Контроллер который определяет как рендерить цвет числа
    int num = Field[yPos][xPos].minesNearby;
    switch (num)
    {
    case 1:
        numberRend(xPos, yPos, num, 0.0f, 0.0f, 0.7f);
        break;
    case 2:
        numberRend(xPos, yPos, num, 0.0f, 0.7f, 0.7f);
        break;
    case 3:
        numberRend(xPos, yPos, num, 0.0f, 0.7f, 0.0f);
        break;
    case 4:
        numberRend(xPos, yPos, num, 0.35f, 0.7f, 0.0f);
        break;
    case 5:
        numberRend(xPos, yPos, num, 0.7f, 0.7f, 0.0f);
        break;
    case 6:
        numberRend(xPos, yPos, num, 0.7f, 0.35f, 0.0f);
        break;
    case 7:
        numberRend(xPos, yPos, num, 0.7f, 0.0f, 0.0f);
        break;
    case 8:
        numberRend(xPos, yPos, num, 0.4f, 0.0f, 0.0f);
        break;
    }
}

void tileRend(int xPos, int yPos, float red, float green, float blue, bool mine) // Рендер ячейки
{
    glLoadIdentity();
    glScalef(1.0f / MAP_WIGTH * 2, 1.0f / MAP_HEIGHT * 2, 1.0f);
    glTranslatef(xPos - MAP_WIGTH / 2, yPos - MAP_HEIGHT / 2, 1.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(red - 0.2f, green - 0.2f, blue - 0.2f);
    glVertex2f(-1.0f, -1.0f);
    glColor3f(red - 0.1f, green - 0.1f, blue - 0.1f);
    glVertex2f(-1.0f, 1.0f);
    glColor3f(red, green, blue);
    glVertex2f(1.0f, 1.0f);
    glColor3f(red - 0.2f, green - 0.2f, blue - 0.2f);
    glVertex2f(-1.0f, -1.0f);
    glColor3f(red - 0.1f, green - 0.1f, blue - 0.1f);
    glVertex2f(1.0f, -1.0f);
    glColor3f(red, green, blue);
    glVertex2f(1.0f, 1.0f);
    if (mine)
    {
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(-0.75f, -0.75f);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(-0.75f, 0.75f);
        glColor3f(0.3f, 0.3f, 0.3f);
        glVertex2f(0.75f, 0.75f);
        glColor3f(0.1f, 0.1f, 0.1f);
        glVertex2f(-0.75f, -0.75f);
        glColor3f(0.2f, 0.2f, 0.2f);
        glVertex2f(0.75f, -0.75f);
        glColor3f(0.3f, 0.3f, 0.3f);
        glVertex2f(0.75f, 0.75f);
    }
    glEnd();
}

void flagRend(int xPos, int yPos) // Рендер флага
{
    glLoadIdentity();
    glScalef(1.0f / MAP_WIGTH * 2, 1.0f / MAP_HEIGHT * 2, 1.0f);
    glTranslatef(xPos - MAP_WIGTH / 2, yPos - MAP_HEIGHT / 2, 1.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(-0.7f, -0.7f);
    glColor3f(0.65f, 0.35f, 0.0f);
    glVertex2f(-0.7f, 0.7f);
    glColor3f(0.7f, 0.4f, 0.0f);
    glVertex2f(-0.4f, 0.7f);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(-0.7f, -0.7f);
    glColor3f(0.65f, 0.35f, 0.0f);
    glVertex2f(-0.4f, -0.7f);
    glColor3f(0.7f, 0.4f, 0.0f);
    glVertex2f(-0.4f, 0.7f);

    glColor3f(0.9f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 0.0f);
    glColor3f(0.9f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 0.5f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.6f, 0.5f);
    glColor3f(0.9f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 1.0f);
    glColor3f(0.9f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 0.5f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.6f, 0.5f);
    glEnd();
}

void numberRend(int xPos, int yPos, int num, float red, float green, float blue) // Рендер числа
{
    glLoadIdentity();
    glScalef(1.0f / MAP_WIGTH * 2, 1.0f / MAP_HEIGHT * 2, 1.0f);
    glTranslatef(xPos - MAP_WIGTH / 2, yPos - MAP_HEIGHT / 2, 1.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    glBegin(GL_TRIANGLES);
    if (num != 1 && num != 0 && num != 7)
    {
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, -0.1f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, -0.1f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, 0.1f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, -0.1f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, 0.1f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, 0.1f);
    }
    if (num != 1 && num != 4 && num != 7)
    {
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, -0.7f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, -0.7f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, -0.9f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, -0.7f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, -0.9f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, -0.9f);
    }
    if (num != 1 && num != 4)
    {
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, 0.7f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, 0.7f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, 0.9f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, 0.7f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, 0.9f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, 0.9f);
    }
    if (num != 2)
    {
        glColor3f(red, green, blue);
        glVertex2f(0.3f, -0.9f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, -0.9f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, 0.1f);
        glColor3f(red, green, blue);
        glVertex2f(0.3f, -0.9f);
        glColor3f(red, green, blue);
        glVertex2f(0.3f, 0.1f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, 0.1f);
    }
    if (num == 2 || num == 6 || num == 8 || num == 0)
    {
        glColor3f(red, green, blue);
        glVertex2f(-0.3f, -0.9f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, -0.9f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, 0.1f);
        glColor3f(red, green, blue);
        glVertex2f(-0.3f, -0.9f);
        glColor3f(red, green, blue);
        glVertex2f(-0.3f, 0.1f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, 0.1f);
    }
    if (num != 5 && num != 6)
    {
        glColor3f(red, green, blue);
        glVertex2f(0.3f, 0.9f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, 0.9f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, -0.1f);
        glColor3f(red, green, blue);
        glVertex2f(0.3f, 0.9f);
        glColor3f(red, green, blue);
        glVertex2f(0.3f, -0.1f);
        glColor3f(red, green, blue);
        glVertex2f(0.5f, -0.1f);
    }
    if (num == 4 || num == 5 || num == 6 || num == 8 || num == 0)
    {
        glColor3f(red, green, blue);
        glVertex2f(-0.3f, 0.9f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, 0.9f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, -0.1f);
        glColor3f(red, green, blue);
        glVertex2f(-0.3f, 0.9f);
        glColor3f(red, green, blue);
        glVertex2f(-0.3f, -0.1f);
        glColor3f(red, green, blue);
        glVertex2f(-0.5f, -0.1f);
    }
    glEnd();
}

#endif