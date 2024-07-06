// artillery.h
#pragma once

class Artillery {
private:
    float x;
    float y;
    float rotationAngle; // Current rotation angle in degrees
    bool alive;

public:
    Artillery(float startX = 0.0f, float startY = 0.0f, bool startAlive = true);
    void drawArtillery() const;
    void rotateTowardsMouse(float mouseX, float mouseY); // Rotate towards mouse position
    float getX() const;
    void setX(float newX);
    float getY() const;
    void setY(float newY);
    bool isAlive() const;
    void setAlive(bool a);

private:
    void drawWheel(float radius, int numSpokes) const;
};