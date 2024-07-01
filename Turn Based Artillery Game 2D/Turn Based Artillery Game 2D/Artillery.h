#pragma once

class Artillery {
private:
    float x;
    float y;
    bool alive;

public:
    Artillery(float startX, float startY, bool startAlive);
    float getX() const;
    void setX(float newX);
    float getY() const;
    void setY(float newY);
    bool isAlive() const;
    void setAlive(bool a);
};
