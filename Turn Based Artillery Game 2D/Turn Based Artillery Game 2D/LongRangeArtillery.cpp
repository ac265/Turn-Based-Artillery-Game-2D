// LongRangeArtillery.cpp
#include "LongRangeArtillery.h"
#include <iostream> // For debugging

LongRangeArtillery::LongRangeArtillery(float startX, float startY, bool startAlive)
    : Artillery(startX, startY, startAlive) {}

void LongRangeArtillery::rapidFire() {
    const float initialAngle = rotationAngle; // Save current angle
    const float shotInterval = 0.2f; // Time interval between shots (adjust as needed)
    const int numShots = 3; // Number of rapid shots

    for (int i = 0; i < numShots; ++i) {
        float angle = initialAngle + (i - numShots / 2.0f) * 10.0f; // Spread shots evenly
        fire(angle, 100.0f); // Example: fire with angle and power (adjust power as needed)
    }
}