#pragma once

#include "Artillery.h" // Include the base class header

class LongRangeArtillery : public Artillery {
public:
    LongRangeArtillery(float startX = 0.0f, float startY = 0.0f, bool startAlive = true);

    // Override rapidFire method specific to long range artillery
    void rapidFire();
};