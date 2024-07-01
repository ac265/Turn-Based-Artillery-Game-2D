#pragma once

#include "Artillery.h"

class PhysicsEngine {
private:
    const float GRAVITY = 9.81f;

public:
    PhysicsEngine();

    // Atýþ hareketini simüle etme
    void simulateArtilleryMotion(Artillery& artillery, float angleDegrees, float power, float dt);
};