#include "FastFiringArtillery.h"
#include <iostream> // For debugging

FastFiringArtillery::FastFiringArtillery(float startX, float startY, bool startAlive)
    : Artillery(startX, startY, startAlive) {}

void FastFiringArtillery::fire(float angle, float power) {
    std::cout << "Fast firing artillery fires with angle: " << angle << ", power: " << power << std::endl;

    // Perform rapid fire behavior
    const int numShots = 5; // Example: fire 5 shots rapidly
    float angleIncrement = 10.0f; // Angle increment between shots

    for (int i = 0; i < numShots; ++i) {
        // Calculate adjusted angle for each shot
        float adjustedAngle = angle + i * angleIncrement;

        // Fire projectile with adjusted angle and power
        Artillery::fire(adjustedAngle, power);
    }
}