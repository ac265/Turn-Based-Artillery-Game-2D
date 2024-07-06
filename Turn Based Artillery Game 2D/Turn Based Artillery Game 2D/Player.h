#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector> // Include vector header
#include "Artillery.h" // Include Artillery header

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
    void addArtillery(float startX, float startY);
    int getScore() const;
    int getArtilleryCount() const;


    std::vector<Artillery>& getArtilleryUnits(); // Getter for artillery list


private:
    std::string name;
    float angle;
    float power;
    bool turn;
    int score;
    std::vector<Artillery> artilleryUnits; // List of artillery units
};

#endif // PLAYER_H