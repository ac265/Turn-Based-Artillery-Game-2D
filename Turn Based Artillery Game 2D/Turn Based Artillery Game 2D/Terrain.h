#pragma once

#include <vector>
#include <GL/freeglut.h>

class Terrain {
private:
    const int WIDTH = 800;
    const int HEIGHT = 600;
    const float MAX_HEIGHT = 300.0f;
    const float MIN_HEIGHT = -50.0f;
    const float WATER_LEVEL = 0.0f;
    const float HILL_FREQUENCY = 0.01f;
    const float VALLEY_FREQUENCY = 0.015f;
    const int NUM_WATER_POINTS = 20;
    const float WATER_RADIUS = 20.0f;

    float heights[800][600];
    std::vector<std::pair<int, int>> waterPoints;

public:
    Terrain();
    void createTerrain();
    void drawTerrain() const;
    void drawWater() const;
};