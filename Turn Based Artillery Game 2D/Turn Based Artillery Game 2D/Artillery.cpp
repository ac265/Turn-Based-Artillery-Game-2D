// artillery.cpp
#include "Artillery.h"
#include <GL/freeglut.h>
#include <cmath>

// Function declaration for drawCircle
void drawCircle(float radius, int numSegments);

Artillery::Artillery(float startX, float startY, bool startAlive)
    : x(startX), y(startY), rotationAngle(0.0f), alive(startAlive) {}

void Artillery::drawArtillery() const {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(rotationAngle, 0, 0, 1); // Apply rotation around the Z-axis

    // Draw the main body of the artillery
    glColor3f(0.5, 0.5, 0.5); // Gray color
    glBegin(GL_QUADS);
    glVertex2f(-20, -10);
    glVertex2f(20, -10);
    glVertex2f(20, 10);
    glVertex2f(-20, 10);
    glEnd();

    // Draw the cannon barrel
    glColor3f(0.3, 0.3, 0.3); // Dark gray color
    glBegin(GL_QUADS);
    glVertex2f(-10, 10);
    glVertex2f(10, 10);
    glVertex2f(10, 20);
    glVertex2f(-10, 20);
    glEnd();

    // Draw the wheels
    glColor3f(0.2, 0.2, 0.2); // Dark gray color
    const int numSpokes = 5;
    const float wheelRadius = 5.0f;

    for (int i = -1; i <= 1; i += 2) {
        glPushMatrix();
        glTranslatef(i * 15, -10, 0);
        drawWheel(wheelRadius, numSpokes);
        glPopMatrix();
    }

    // Draw the tracks
    glColor3f(0.4, 0.4, 0.4); // Dark gray color
    glBegin(GL_QUADS);
    glVertex2f(-25, -5);
    glVertex2f(-25, 5);
    glVertex2f(-20, 5);
    glVertex2f(-20, -5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(25, -5);
    glVertex2f(25, 5);
    glVertex2f(20, 5);
    glVertex2f(20, -5);
    glEnd();

    glPopMatrix();
}

void Artillery::rotateTowardsMouse(float mouseX, float mouseY) {
    // Calculate the angle using arctangent function
    float dx = mouseX - x;
    float dy = mouseY - y;
    rotationAngle = atan2(dy, dx) * 180.0f / 3.1416f;
}

void Artillery::drawWheel(float radius, int numSpokes) const {
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSpokes; ++i) {
        float angle = 2.0f * 3.1416f * i / numSpokes;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_LINES);
    for (int i = 0; i < numSpokes; ++i) {
        float angle = 2.0f * 3.1416f * i / numSpokes;
        float x1 = radius * cos(angle);
        float y1 = radius * sin(angle);
        float x2 = 1.2f * radius * cos(angle);
        float y2 = 1.2f * radius * sin(angle);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
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