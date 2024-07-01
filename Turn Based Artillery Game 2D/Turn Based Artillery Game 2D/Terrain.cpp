#include "Terrain.h"
#include <cstdlib>
#include <cmath>

Terrain::Terrain() {
    createTerrain();
}

void Terrain::createTerrain() {
    for (int x = 0; x < WIDTH; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            float xNormalized = static_cast<float>(x) / WIDTH;
            float yNormalized = static_cast<float>(y) / HEIGHT;

            float hillHeight = MAX_HEIGHT * sin(xNormalized * 2 * 3.141592653589793 * HILL_FREQUENCY) * cos(yNormalized * 2 * 3.141592653589793 * HILL_FREQUENCY);
            float valleyHeight = MIN_HEIGHT * sin(xNormalized * 2 * 3.141592653589793 * VALLEY_FREQUENCY) * cos(yNormalized * 2 * 3.141592653589793 * VALLEY_FREQUENCY);

            heights[x][y] = hillHeight + valleyHeight;

            // Su birikintisi ekleyelim
            for (int i = 0; i < NUM_WATER_POINTS; ++i) {
                int wx = rand() % WIDTH;
                int wy = rand() % HEIGHT;
                waterPoints.emplace_back(wx, wy);
            }
        }
    }
}

void Terrain::drawTerrain() const {
    glBegin(GL_TRIANGLE_STRIP);
    for (int x = 0; x < WIDTH - 1; ++x) {
        for (int y = 0; y < HEIGHT; ++y) {
            // Sol üst
            if (heights[x][y] <= WATER_LEVEL) {
                glColor3f(0.0f, 0.0f, 1.0f); // Mavi renk (su)
            }
            else if (heights[x][y] < MAX_HEIGHT / 3) {
                glColor3f(0.8f, 0.8f, 0.8f); // Gri renk (düþük tepeler)
            }
            else {
                glColor3f(0.0f, 1.0f, 0.0f); // Yeþil renk (yüksek tepeler)
            }
            glVertex3f(x, heights[x][y], y);

            // Sað alt
            if (heights[x + 1][y] <= WATER_LEVEL) {
                glColor3f(0.0f, 0.0f, 1.0f); // Mavi renk (su)
            }
            else if (heights[x + 1][y] < MAX_HEIGHT / 3) {
                glColor3f(0.8f, 0.8f, 0.8f); // Gri renk (düþük tepeler)
            }
            else {
                glColor3f(0.0f, 1.0f, 0.0f); // Yeþil renk (yüksek tepeler)
            }
            glVertex3f(x + 1, heights[x + 1][y], y);
        }
    }
    glEnd();
}

void Terrain::drawWater() const {
    for (const auto& point : waterPoints) {
        int wx = point.first;
        int wy = point.second;

        // Su birikintisi rengi ve çizimi
        glColor3f(0.0f, 0.0f, 1.0f); // Mavi renk (su)
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i <= 360; i += 10) {
            float angle = static_cast<float>(i) * 3.141592653589793 / 180.0f;
            float px = wx + WATER_RADIUS * cos(angle);
            float py = wy + WATER_RADIUS * sin(angle);
            glVertex3f(px, WATER_LEVEL, py);
        }
        glEnd();
    }
}