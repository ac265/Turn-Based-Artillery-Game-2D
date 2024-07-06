// artillery.h
#pragma once

class Artillery {
private:
    float x;
    float y;
    bool alive;

public:
    Artillery(float startX = 0.0f, float startY = 0.0f, bool startAlive = true);  // Constructor declaration

    void drawArtillery() const;
    float getX() const;
    void setX(float newX);
    float getY() const;
    void setY(float newY);
    bool isAlive() const;
    void setAlive(bool a);
};