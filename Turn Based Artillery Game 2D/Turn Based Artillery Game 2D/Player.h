#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    Player(const std::string& n = "", float a = 0.0f, float p = 0.0f, bool t = false);

    const std::string& getName() const;

    float getAngle() const;
    void setAngle(float a);

    float getPower() const;
    void setPower(float p);

    bool getTurn() const;
    void setTurn(bool t);

    void drawHuman(float x, float y, float r, float g, float b) const;
    void drawText(float x, float y) const;

private:
    std::string name;
    float angle;
    float power;
    bool turn;
};

#endif // PLAYER_H