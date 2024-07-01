// Player.cpp

#include "Player.h"

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