#pragma once

#include <string>

class Player {
private:
    std::string name;
    float angle;    // Atýþ açýsý (derece cinsinden)
    float power;    // Atýþ gücü
    bool turn;      // Sýra kontrolü

public:
    // Constructor
    Player(const std::string& n, float a = 45.0f, float p = 50.0f, bool t = false);

    // Getter methods
    const std::string& getName() const;
    float getAngle() const;
    float getPower() const;
    bool getTurn() const;

    // Setter methods
    void setAngle(float a);
    void setPower(float p);
    void setTurn(bool t);
};
