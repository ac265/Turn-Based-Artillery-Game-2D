// artillery.cpp
#include "Artillery.h"
#include <GL/freeglut.h>
#include <cmath>

// Function declaration for drawCircle
void drawCircle(float radius, int numSegments);

Artillery::Artillery(float startX, float startY, bool startAlive)
    : x(startX), y(startY), alive(startAlive) {}

void Artillery::drawArtillery() const {
    // Draw the main body of the artillery
    glColor3f(0.5, 0.5, 0.5); // Gray color
    glBegin(GL_QUADS);
    glVertex2f(x - 20, y - 10);
    glVertex2f(x + 20, y - 10);
    glVertex2f(x + 20, y + 10);
    glVertex2f(x - 20, y + 10);
    glEnd();

    // Draw the cannon barrel
    glColor3f(0.3, 0.3, 0.3); // Dark gray color
    glBegin(GL_QUADS);
    glVertex2f(x - 10, y + 10);
    glVertex2f(x + 10, y + 10);
    glVertex2f(x + 10, y + 20);
    glVertex2f(x - 10, y + 20);
    glEnd();

    // Draw the wheels
    glColor3f(0.2, 0.2, 0.2); // Dark gray color
    glPushMatrix();
    glTranslatef(x - 15, y - 5, 0);
    drawCircle(5, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 15, y - 5, 0);
    drawCircle(5, 20);
    glPopMatrix();

    // Draw the tracks
    glColor3f(0.4, 0.4, 0.4); // Dark gray color
    glBegin(GL_QUADS);
    glVertex2f(x - 25, y - 5);
    glVertex2f(x - 25, y + 5);
    glVertex2f(x - 20, y + 5);
    glVertex2f(x - 20, y - 5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x + 25, y - 5);
    glVertex2f(x + 25, y + 5);
    glVertex2f(x + 20, y + 5);
    glVertex2f(x + 20, y - 5);
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

void drawCircle(float radius, int numSegments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; i++) {
        float angle = 2.0f * 3.1416f * i / numSegments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}