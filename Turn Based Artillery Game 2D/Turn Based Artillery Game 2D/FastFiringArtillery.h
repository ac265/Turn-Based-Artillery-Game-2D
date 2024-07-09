#pragma once

#include "Artillery.h"

class FastFiringArtillery : public Artillery {
public:
    FastFiringArtillery(float startX = 0.0f, float startY = 0.0f, bool startAlive = true);

    // Override fire method for fast firing artillery
    void fire(float angle, float power) override;
};