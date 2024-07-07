#include "Player.h"
#include <GL/freeglut.h>
#include <cmath>

Player::Player(const std::string& n, float a, float p, bool t)
    : name(n), angle(a), power(p), turn(t) {}

const std::string& Player::getName() const {
    return name;
}

float Player::getAngle() const {
    return angle;
}

void Player::setAngle(float a) {
    angle = a;
}

float Player::getPower() const {
    return power;
}

void Player::setPower(float p) {
    power = p;
}

bool Player::getTurn() const {
    return turn;
}

void Player::setTurn(bool t) {
    turn = t;
}

void Player::drawHuman(float x, float y, float r, float g, float b) const {
    const float headRadius = 10.0f;
    const float bodyHeight = 40.0f;
    const float limbLength = 20.0f;

    glColor3f(r, g, b); // Renk

    // Baþ
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i += 10) {
        float angle = static_cast<float>(i) * 3.141592653589793 / 180.0f;
        float px = x + headRadius * cos(angle);
        float py = y + headRadius * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();

    // Vücut
    glBegin(GL_QUADS);
    glVertex2f(x - 5, y - headRadius);
    glVertex2f(x + 5, y - headRadius);
    glVertex2f(x + 5, y - headRadius - bodyHeight);
    glVertex2f(x - 5, y - headRadius - bodyHeight);
    glEnd();

    // Kol ve Bacaklar
    glBegin(GL_LINES);
    // Sol Kol
    glVertex2f(x - 5, y - headRadius - bodyHeight / 2);
    glVertex2f(x - 5 - limbLength * cos(45 * 3.141592653589793 / 180.0f),
        y - headRadius - bodyHeight / 2 - limbLength * sin(45 * 3.141592653589793 / 180.0f));
    // Sað Kol
    glVertex2f(x + 5, y - headRadius - bodyHeight / 2);
    glVertex2f(x + 5 + limbLength * cos(45 * 3.141592653589793 / 180.0f),
        y - headRadius - bodyHeight / 2 - limbLength * sin(45 * 3.141592653589793 / 180.0f));
    // Sol Bacak
    glVertex2f(x - 5, y - headRadius - bodyHeight);
    glVertex2f(x - 5 - limbLength * cos(45 * 3.141592653589793 / 180.0f),
        y - headRadius - bodyHeight - limbLength * sin(45 * 3.141592653589793 / 180.0f));
    // Sað Bacak
    glVertex2f(x + 5, y - headRadius - bodyHeight);
    glVertex2f(x + 5 + limbLength * cos(45 * 3.141592653589793 / 180.0f),
        y - headRadius - bodyHeight - limbLength * sin(45 * 3.141592653589793 / 180.0f));
    glEnd();

    //for (const auto& artillery : artilleryUnits) {
    //    artillery.drawArtillery();
    //}
}

void Player::drawText(float x, float y) const {
    glColor3f(0.0f, 0.0f, 0.0f); // Siyah renk
    glRasterPos2f(x, y);
    for (unsigned int i = 0; i < name.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name[i]);
    }
}

void Player::addArtillery(float startX, float startY) {
    artilleryUnits.emplace_back(startX, startY);
}

std::vector<Artillery>& Player::getArtilleryUnits() {
    return artilleryUnits;
}

int Player::getScore() const {
    // Return a placeholder value or implement score logic based on your game rules
    return score;
}

int Player::getArtilleryCount() const {
    return artilleryUnits.size();
}

void Player::fireCurrentArtillery(float angle, float power) {
    if (!artilleryUnits.empty()) {
        artilleryUnits.back().fire(angle, power);
    }
}