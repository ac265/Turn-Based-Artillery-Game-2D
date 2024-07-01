#include <GL/freeglut.h>
#include "Terrain.h"
#include "Player.h"
#include "Artillery.h"
#include "PhysicsEngine.h"
#include <iostream>
#include <vector>

const int WIDTH = 800;
const int HEIGHT = 600;

Terrain terrain;
PhysicsEngine physicsEngine;

std::vector<Player> players;
Player* currentPlayer = nullptr;
int currentPlayerIndex = 0;

bool gameStarted = false;
bool gameEnded = false;

void initializePlayers(const std::string& playerName1, const std::string& playerName2) {
    players.clear();
    players.push_back(Player(playerName1));
    players.push_back(Player(playerName2));

    currentPlayerIndex = 0;
    currentPlayer = &players[currentPlayerIndex];
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(WIDTH / 2, 400, HEIGHT * 1.5, WIDTH / 2, 0, HEIGHT / 2, 0, 1, 0);

    // Draw terrain
    terrain.drawTerrain();

    // Draw water bodies
    terrain.drawWater();

    // Draw players if they exist in the vector
    if (!players.empty()) {
        // Draw Player 1's position and name
        players[0].drawHuman(100.0f, 100.0f, 1.0f, 0.0f, 0.0f);
        players[0].drawText(80.0f, 120.0f);

        // Draw Player 2's position and name if it exists
        if (players.size() > 1) {
            players[1].drawHuman(700.0f, 100.0f, 0.6f, 0.7f, 0.2f);
            players[1].drawText(680.0f, 120.0f);
        }
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / (double)h, 0.1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}

void init() {
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f); // Light blue background
    glEnable(GL_DEPTH_TEST); // Enable depth testing
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case ' ':
        if (!gameStarted) {
            gameStarted = true;
            initializePlayers("Player 1", "Player 2");
        }
        break;
    case 'a':
        // TODO: Decrease angle
        break;
    case 'd':
        // TODO: Increase angle
        break;
    case 'w':
        // TODO: Increase power
        break;
    case 's':
        // TODO: Decrease power
        break;
    case 'f':
        // TODO: Fire
        break;
    default:
        break;
    }
}

void update(int value) {
    // TODO: Perform physics updates here

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("2D Turn-Based Artillery Game");

    init(); // Initialize settings

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);

    glutMainLoop();

    return 0;
}