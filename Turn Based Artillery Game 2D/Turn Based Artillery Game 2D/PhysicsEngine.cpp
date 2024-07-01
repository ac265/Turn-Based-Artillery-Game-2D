#include "PhysicsEngine.h"
#include <cmath>

PhysicsEngine::PhysicsEngine() {}

void PhysicsEngine::simulateArtilleryMotion(Artillery& artillery, float angleDegrees, float power, float dt) {
    float vx = power * cos(angleDegrees * 3.141592653589793 / 180.0);
    float vy = power * sin(angleDegrees * 3.141592653589793 / 180.0);

    while (artillery.getY() >= 0.0f) {
        float ax = 0.0f; // Rüzgar veya diðer kuvvetler için eklenen ivme bileþeni
        float ay = -GRAVITY; // Yerçekimi ivmesi (örnek olarak 9.81 m/s²)

        artillery.setX(artillery.getX() + vx * dt + 0.5f * ax * dt * dt);
        artillery.setY(artillery.getY() + vy * dt + 0.5f * ay * dt * dt);

        vx += ax * dt;
        vy += ay * dt;
    }
}