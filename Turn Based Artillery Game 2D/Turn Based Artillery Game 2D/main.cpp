#include <GL/freeglut.h>
#include "Terrain.h"
#include "Player.h"
#include "Artillery.h"
#include "PhysicsEngine.h"
#include <iostream>
#include <vector>
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 600;

Terrain terrain;
PhysicsEngine physicsEngine;

std::vector<Player> players;
std::vector<Artillery> player1Artilleries;
std::vector<Artillery> player2Artilleries;

Player* currentPlayer;
int currentPlayerIndex = 0;

bool gameStarted = false;
bool gameEnded = false;

void initializePlayers() {
    players.push_back(Player("Player 1"));
    players.push_back(Player("Player 2"));

    currentPlayer = &players[currentPlayerIndex];
}

void drawHuman(float x, float y, float r, float g, float b) {
    const float headRadius = 10.0f;
    const float bodyHeight = 40.0f;
    const float limbLength = 20.0f;

    glColor3f(r, g, b); // Renk

    // Baþ
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i += 10) {
        float angle = static_cast<float>(i) * 3.141592653589793 / 180.0f;
        float px = x + headRadius * cos(angle);
        float py = y + headRadius * sin(angle);
        glVertex2f(px, py);
    }
    glEnd();

    // Vücut
    glBegin(GL_QUADS);
    glVertex2f(x - 5, y - headRadius);
    glVertex2f(x + 5, y - headRadius);
    glVertex2f(x + 5, y - headRadius - bodyHeight);
    glVertex2f(x - 5, y - headRadius - bodyHeight);
    glEnd();

    // Kol ve Bacaklar
    glBegin(GL_LINES);
    // Sol Kol
    glVertex2f(x - 5, y - headRadius - bodyHeight / 2);
    glVertex2f(x - 5 - limbLength * cos(45 * 3.141592653589793 / 180.0f),
        y - headRadius - bodyHeight / 2 - limbLength * sin(45 * 3.141592653589793 / 180.0f));
    // Sað Kol
    glVertex2f(x + 5, y - headRadius - bodyHeight / 2);
    glVertex2f(x + 5 + limbLength * cos(45 * 3.141592653589793 / 180.0f),
        y - headRadius - bodyHeight / 2 - limbLength * sin(45 * 3.141592653589793 / 180.0f));
    // Sol Bacak
    glVertex2f(x - 5, y - headRadius - bodyHeight);
    glVertex2f(x - 5 - limbLength * cos(45 * 3.141592653589793 / 180.0f),
        y - headRadius - bodyHeight - limbLength * sin(45 * 3.141592653589793 / 180.0f));
    // Sað Bacak
    glVertex2f(x + 5, y - headRadius - bodyHeight);
    glVertex2f(x + 5 + limbLength * cos(45 * 3.141592653589793 / 180.0f),
        y - headRadius - bodyHeight - limbLength * sin(45 * 3.141592653589793 / 180.0f));
    glEnd();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(WIDTH / 2, 400, HEIGHT * 1.5, WIDTH / 2, 0, HEIGHT / 2, 0, 1, 0);

    // Tepeleri ve vadileri çiz
    terrain.drawTerrain();

    // Su birikintilerini çiz
    terrain.drawWater();

    // Player 1'in pozisyonunu çiz
    drawHuman(100.0f, 100.0f, 1.0f, 0.0f, 0.0f); // Kýrmýzý renk, örnek koordinatlar

    // Player 2'nin pozisyonunu çiz
    drawHuman(700.0f, 500.0f, 0.0f, 1.0f, 0.0f); // Yeþil renk, örnek koordinatlar

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
    glClearColor(0.7f, 0.9f, 1.0f, 1.0f); // Açýk mavi arka plan
    glEnable(GL_DEPTH_TEST); // Derinlik testini etkinleþtir
}

void switchTurn() {
    currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    currentPlayer = &players[currentPlayerIndex];
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case ' ':
        if (!gameStarted) {
            gameStarted = true;
            initializePlayers();
        }
        break;
    case 'a':
        // TODO: Açýyý azalt
        break;
    case 'd':
        // TODO: Açýyý arttýr
        break;
    case 'w':
        // TODO: Gücü arttýr
        break;
    case 's':
        // TODO: Gücü azalt
        break;
    case 'f':
        // TODO: Ateþ et
        break;
    default:
        break;
    }
}

void update(int value) {
    // TODO: Fizik güncellemeleri burada yapýlacak

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("2D Turn-Based Artillery Game");

    init(); // Baþlangýç ayarlarý

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(16, update, 0);

    glutMainLoop();

    return 0;
}