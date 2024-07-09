#pragma once

#include "Artillery.h" // Include the base class header

class ArmoredArtillery : public Artillery {
public:
    ArmoredArtillery(float startX = 0.0f, float startY = 0.0f, bool startAlive = true);

    // Override fire method for armored artillery
    void fire(float angle, float power) override;
};