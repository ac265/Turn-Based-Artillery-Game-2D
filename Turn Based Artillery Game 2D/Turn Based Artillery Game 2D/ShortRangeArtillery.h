// ShortRangeArtillery.cpp
#include "ShortRangeArtillery.h"
#include <iostream> // For debugging

ShortRangeArtillery::ShortRangeArtillery(float startX, float startY, bool startAlive)
    : Artillery(startX, startY, startAlive) {}

void ShortRangeArtillery::rapidFire() {
    const float initialAngle = rotationAngle; // Save current angle
    const float shotInterval = 0.1f; // Time interval between shots (adjust as needed)
    const int numShots = 5; // Number of rapid shots

    for (int i = 0; i < numShots; ++i) {
        float angle = initialAngle + (i - numShots / 2.0f) * 5.0f; // Spread shots evenly
        fire(angle, 50.0f); // Example: fire with angle and power (adjust power as needed)
    }
}