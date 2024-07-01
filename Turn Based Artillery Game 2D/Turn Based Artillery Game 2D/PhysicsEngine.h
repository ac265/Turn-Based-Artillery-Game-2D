#pragma once

#include "Artillery.h"

class PhysicsEngine {
private:
    const float GRAVITY = 9.81f;

public:
    PhysicsEngine();

    // At�� hareketini sim�le etme
    void simulateArtilleryMotion(Artillery& artillery, float angleDegrees, float power, float dt);
};