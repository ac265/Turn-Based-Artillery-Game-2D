#include "Artillery.h"

Artillery::Artillery(float startX, float startY, bool startAlive)
    : x(startX), y(startY), alive(startAlive) {}

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
