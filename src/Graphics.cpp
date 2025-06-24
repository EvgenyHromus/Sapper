#ifndef Graphics_CPP
#define Graphics_CPP

#include "../lib/glfw3.h"
#include "Game.cpp"
#include <cmath>

void tileRend(int xPos, int yPos, float red, float green, float blue)
{
    glScalef(1.0f / MAP_WIGTH, 1.0f / MAP_HEIGHT, 1.0f);
    glTranslatef(xPos - MAP_WIGTH / 2.0f, yPos - MAP_HEIGHT / 2.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, -1.0f);
    glColor3f(red - 0.2f, green - 0.2f, blue - 0.2f);
    glVertex2f(-1.0f, 1.0f);
    glColor3f(red - 0.1f, green - 0.1f, blue - 0.1f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(red, green, blue);
    glVertex2f(-1.0f, -1.0f);
    glColor3f(red - 0.2f, green - 0.2f, blue - 0.2f);
    glVertex2f(1.0f, -1.0f);
    glColor3f(red - 0.1f, green - 0.1f, blue - 0.1f);
    glVertex2f(1.0f, 1.0f);
    glColor3f(red, green, blue);
    glEnd();
}

void flagRend(int xPos, int yPos)
{
    glScalef(1.0f / MAP_WIGTH, 1.0f / MAP_HEIGHT, 1.0f);
    glTranslatef(xPos - MAP_WIGTH / 2.0f, yPos - MAP_HEIGHT / 2.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.7f, -0.7f);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(-0.7f, 0.7f);
    glColor3f(0.65f, 0.35f, 0.0f);
    glVertex2f(-0.4f, 0.7f);
    glColor3f(0.7f, 0.4f, 0.0f);
    glVertex2f(-0.7f, -0.7f);
    glColor3f(0.6f, 0.3f, 0.0f);
    glVertex2f(-0.4f, -0.7f);
    glColor3f(0.65f, 0.35f, 0.0f);
    glVertex2f(-0.4f, 0.7f);
    glColor3f(0.7f, 0.4f, 0.0f);

    glVertex2f(-0.4f, 0.0f);
    glColor3f(0.9f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 0.5f);
    glColor3f(0.9f, 0.0f, 0.0f);
    glVertex2f(0.6f, 0.5f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 1.0f);
    glColor3f(0.9f, 0.0f, 0.0f);
    glVertex2f(-0.4f, 0.5f);
    glColor3f(0.9f, 0.0f, 0.0f);
    glVertex2f(0.6f, 0.5f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glEnd();
}

void numberRend(int xPos, int yPos, int num, float red, float green, float blue)
{
    glBegin(GL_TRIANGLES);
    if (num != 1 && num != 0 && num != 7)
    {
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
        glColor3f(red, green, blue);
    }
    if (num != 1 && num != 4 && num != 7)
    {
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
        glColor3f(red, green, blue);
    }
    if (num != 1 && num != 4)
    {
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
        glColor3f(red, green, blue);
    }
    if (num != 2)
    {
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
        glColor3f(red, green, blue);
    }
    if (num == 2 || num == 6 || num == 8 || num == 0)
    {
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
        glColor3f(red, green, blue);
    }
    if (num != 5 && num != 6)
    {
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
        glColor3f(red, green, blue);
    }
    if (num == 4 || num == 5 || num == 6 || num == 8 || num == 0)
    {
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
        glColor3f(red, green, blue);
    }
    glEnd();
}

#endif