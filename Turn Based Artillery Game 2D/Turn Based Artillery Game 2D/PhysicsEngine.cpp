#include "PhysicsEngine.h"
#include <cmath>

PhysicsEngine::PhysicsEngine() {}

void PhysicsEngine::simulateArtilleryMotion(Artillery& artillery, float angleDegrees, float power, float dt) {
    float vx = power * cos(angleDegrees * 3.141592653589793 / 180.0);
    float vy = power * sin(angleDegrees * 3.141592653589793 / 180.0);

    while (artillery.getY() >= 0.0f) {
        float ax = 0.0f; // R�zgar veya di�er kuvvetler i�in eklenen ivme bile�eni
        float ay = -GRAVITY; // Yer�ekimi ivmesi (�rnek olarak 9.81 m/s�)

        artillery.setX(artillery.getX() + vx * dt + 0.5f * ax * dt * dt);
        artillery.setY(artillery.getY() + vy * dt + 0.5f * ay * dt * dt);

        vx += ax * dt;
        vy += ay * dt;
    }
}