// artillery.cpp
#include "Artillery.h"
#include <GL/freeglut.h>

Artillery::Artillery(float startX, float startY, bool startAlive)
    : x(startX), y(startY), alive(startAlive) {}  // Constructor definition

void Artillery::drawArtillery() const {
    // Draw artillery representation
    glColor3f(1.0f, 0.0f, 0.0f); // Red color

    // Draw a simple representation of the artillery unit
    glBegin(GL_POLYGON);
    glVertex2f(x - 5.0f, y + 10.0f); // Bottom left
    glVertex2f(x + 5.0f, y + 10.0f); // Bottom right
    glVertex2f(x + 5.0f, y - 10.0f); // Top right
    glVertex2f(x - 5.0f, y - 10.0f); // Top left
    glEnd();
}

float Artillery::getX() const {
    return x;
}

void Artillery::setX(float newX) {
    x = newX;
}

float Artillery::getY() const {
    return y;
}

void Artillery::setY(float newY) {
    y = newY;
}

bool Artillery::isAlive() const {
    return alive;
}

void Artillery::setAlive(bool a) {
    alive = a;
}