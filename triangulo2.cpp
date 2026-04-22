#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Comente/Descomente a linha abaixo para alternar entre preenchimento e linhas
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_TRIANGLES);
        // Vértice 1: Vermelho
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.8f, -0.8f);

        // Vértice 2: Verde
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.8f, -0.8f);

        // Vértice 3: Azul
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.8f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Interpolação de Cores - Gouraud Shading");
    glutDisplayFunc(display);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}