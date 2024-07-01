#include <GL/freeglut.h>
#include "Terrain.h"

const int WIDTH = 800;
const int HEIGHT = 600;

Terrain terrain;

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(WIDTH / 2, 400, HEIGHT * 1.5, WIDTH / 2, 0, HEIGHT / 2, 0, 1, 0);

    // Tepeleri ve vadileri çiz
    terrain.drawTerrain();

    // Su birikintilerini çiz
    terrain.drawWater();

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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Realistic Terrain");

    init(); // Baþlangýç ayarlarý

    glutDisplayFunc(drawScene);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}