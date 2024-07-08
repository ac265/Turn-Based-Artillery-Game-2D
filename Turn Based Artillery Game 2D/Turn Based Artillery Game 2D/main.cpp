#include <GL/freeglut.h>
#include "Terrain.h"
#include "Player.h"
#include "Artillery.h"
#include "PhysicsEngine.h"
#include <iostream>
#include <vector>
#include <thread>

const int WIDTH = 800;
const int HEIGHT = 600;

Terrain terrain;
PhysicsEngine physicsEngine;

std::vector<Player> players;
Player* currentPlayer = nullptr;
int currentPlayerIndex = 0;

bool gameStarted = false;
bool gameEnded = false;
std::vector<Artillery> artilleryUnits;

void initializePlayers(const std::string& playerName1, const std::string& playerName2) {
    players.clear();

    //Player1
    players.push_back(Player(playerName1));
    //std::vector<Artillery>& player1Artilleries = players[0].getArtilleryUnits();
    //player1Artilleries.push_back(Artillery(100.0f, 100.0f, true)); // Example artillery units
    //player1Artilleries.push_back(Artillery(120.0f, 120.0f, true)); // Example artillery units

    //Player2
    players.push_back(Player(playerName2));
    //std::vector<Artillery>& player2Artilleries = players[1].getArtilleryUnits();
    //player2Artilleries.push_back(Artillery(700.0f, 100.0f, true)); // Example artillery units
    //player2Artilleries.push_back(Artillery(680.0f, 120.0f, true)); // Example artillery units

    //currentPlayerIndex = 0;
    //currentPlayer = &players[currentPlayerIndex];
}

void drawScene() {
    // Draw terrain, water, and players
    terrain.drawTerrain();
    terrain.drawWater();

    // Draw players
    if (!players.empty()) {
        // Draw Player 1 (top-left corner)
        players[0].drawHuman(100.0f, 100.0f, 1.0f, 0.0f, 0.0f);
        players[0].drawText(80.0f, 120.0f);

        // Display Player 1 score and artillery count
        std::string player1Info = "Score: " + std::to_string(players[0].getScore()) + "\nArtillery: " + std::to_string(players[0].getArtilleryCount());
        glColor3f(0.0f, 0.0f, 0.0f); // Black color
        glRasterPos2f(60.0f, 140.0f); // Adjust position as needed
        for (unsigned int i = 0; i < player1Info.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, player1Info[i]);
        }

        const auto& artilleryUnits = players[0].getArtilleryUnits();
        for (const auto& artillery : artilleryUnits) {
            artillery.drawArtillery(); // Draw each artillery unit
        }

        // Draw Player 2 (top-right corner)
        if (players.size() > 1) {
            players[1].drawHuman(700.0f, 100.0f, 0.6f, 0.7f, 0.2f);
            players[1].drawText(680.0f, 120.0f);

            // Display Player 2 score and artillery count
            std::string player2Info = "Score: " + std::to_string(players[1].getScore()) + "\nArtillery: " + std::to_string(players[1].getArtilleryCount());
            glColor3f(0.0f, 0.0f, 0.0f); // Black color
            glRasterPos2f(660.0f, 140.0f); // Adjust position as needed
            for (unsigned int i = 0; i < player2Info.length(); ++i) {
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, player2Info[i]);
            }

            const auto& artilleryUnits = players[1].getArtilleryUnits();
            for (const auto& artillery : artilleryUnits) {
                artillery.drawArtillery(); // Draw each artillery unit
            }
        }

    }
}

void drawStartButton() {
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw button text
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(WIDTH / 2 - 25 , HEIGHT - 75); // Adjust text position
    std::string buttonText = gameStarted ? "Game Started" : "Start Game";
    for (char c : buttonText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    // Draw start button
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex2f(WIDTH / 2 - 50, HEIGHT - 50);   // Top left corner
    glVertex2f(WIDTH / 2 + 50, HEIGHT - 50);   // Top right corner
    glVertex2f(WIDTH / 2 + 50, HEIGHT - 100);  // Bottom right corner
    glVertex2f(WIDTH / 2 - 50, HEIGHT - 100);  // Bottom left corner
    glEnd();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
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
    case '1':
        currentPlayerIndex = 0; // Player 1'i seç
        currentPlayer = &players[currentPlayerIndex];
        break;
    case '2':
        currentPlayerIndex = 1; // Player 2'yi seç
        currentPlayer = &players[currentPlayerIndex];
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
        // Oyun baþladýysa ve mevcut oyuncu varsa
        if (currentPlayer) {
            float angle = currentPlayer->getAngle();
            float power = currentPlayer->getPower();
            currentPlayer->fireCurrentArtillery(angle, power);
        }
        break;
    case 'q':
    case 27: // Escape tuþu
        exit(0); // Uygulamadan çýkýþ
        break;
    default:
        break;
    }
}

void mouse(int button, int state, int x, int y) {
    // Calculate scale factors based on current window size
    float scaleX = static_cast<float>(WIDTH) / glutGet(GLUT_WINDOW_WIDTH);
    float scaleY = static_cast<float>(HEIGHT) / glutGet(GLUT_WINDOW_HEIGHT);

    // OpenGL coordinates of mouse position
    float glX = static_cast<float>(x) * scaleX;
    float glY = static_cast<float>(HEIGHT - y) * scaleY; // Invert Y coordinate and scale

    // Button coordinates (scaled accordingly)
    float buttonLeft = WIDTH / 2.0f - 50.0f * scaleX;
    float buttonRight = WIDTH / 2.0f + 50.0f * scaleX;
    float buttonBottom = HEIGHT - 100.0f * scaleY;
    float buttonTop = HEIGHT - 50.0f * scaleY;

    // Mouse click events
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Right click: create new artillery unit
        if (gameStarted && currentPlayer != nullptr) {
            currentPlayer->addArtillery(glX, glY);
            glutPostRedisplay(); // Request redraw
        }
    }
    else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Left click: check start button or rotate artillery
        if (!gameStarted && glX >= buttonLeft && glX <= buttonRight && glY >= buttonBottom && glY <= buttonTop) {
            gameStarted = true;
            initializePlayers("Player 1", "Player 2");
        }
        else if (gameStarted && currentPlayer != nullptr) {
            // Rotate artillery towards mouse position
            std::vector<Artillery>& playerArtilleries = currentPlayer->getArtilleryUnits();
            for (auto& artillery : playerArtilleries) {
                artillery.rotateTowardsMouse(glX, glY);
            }
            glutPostRedisplay();
        }
    }
}

void motion(int x, int y) {
    // Fare hareketine göre iþlemler
}

void update(int value) {
    // TODO: Perform physics updates here
        // Artillery birimlerini güncelle
    for (auto& artillery : artilleryUnits) {
        artillery.update();
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(WIDTH / 2, 400, HEIGHT * 1.5, WIDTH / 2, 0, HEIGHT / 2, 0, 1, 0);

    // Draw game elements
    drawScene();

    // Draw start button on top
    drawStartButton();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("2D Turn-Based Artillery Game");

    init(); // Initialize settings

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutTimerFunc(0, update, 0);

    // Fizik güncellemeleri için yeni bir thread oluþtur
    std::thread physicsThread(update, 0);

    glutMainLoop();

    // Thread'in sonlanmasýný bekleyin
    physicsThread.join();

    return 0;
}