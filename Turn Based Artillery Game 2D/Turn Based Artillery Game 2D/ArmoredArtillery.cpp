#include "ArmoredArtillery.h"
#include <iostream> // For debugging

ArmoredArtillery::ArmoredArtillery(float startX, float startY, bool startAlive)
    : Artillery(startX, startY, startAlive) {}

void ArmoredArtillery::fire(float angle, float power) {
    std::cout << "Armored artillery fires with angle: " << angle << ", power: " << power << std::endl;

    // Reduce damage for armored artillery
    float modifiedPower = power * 0.8f; // Example: reduce power by 20%

    // Modify projectile behavior or add special effects
    // For example, adjust projectile speed or add visual effects

    Artillery::fire(angle, modifiedPower); // Call base class fire method with modified power
}