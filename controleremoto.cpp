#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(5.0f);
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);
    glBegin(GL_LINES);

    
    glVertex2f( 0.00f,  0.52f);
    glVertex2f(-0.10f,  0.55f);
    glVertex2f(-0.10f,  0.55f); 
    glVertex2f(-0.25f,  0.60f);
    glVertex2f(-0.25f,  0.60f); 
    glVertex2f(-0.35f,  0.60f);

    glVertex2f(-0.35f,  0.60f); 
    glVertex2f(-0.50f,  0.55f);
    glVertex2f(-0.50f,  0.55f); 
    glVertex2f(-0.65f,  0.45f);
    glVertex2f(-0.65f,  0.45f); 
    glVertex2f(-0.75f,  0.30f);

    glVertex2f(-0.75f,  0.30f); 
    glVertex2f(-0.80f,  0.10f);
    glVertex2f(-0.80f,  0.10f); 
    glVertex2f(-0.78f, -0.10f);
    glVertex2f(-0.78f, -0.10f); 
    glVertex2f(-0.73f, -0.25f);

    glVertex2f(-0.73f, -0.25f); 
    glVertex2f(-0.65f, -0.35f);
    glVertex2f(-0.65f, -0.35f); 
    glVertex2f(-0.50f, -0.40f);
    glVertex2f(-0.50f, -0.40f); 
    glVertex2f(-0.38f, -0.38f);

    glVertex2f(-0.38f, -0.38f); 
    glVertex2f(-0.25f, -0.30f);
    glVertex2f(-0.25f, -0.30f); 
    glVertex2f(-0.18f, -0.22f);

    glVertex2f(-0.18f, -0.22f); 
    glVertex2f(-0.10f, -0.18f);
    glVertex2f(-0.10f, -0.18f); 
    glVertex2f( 0.00f, -0.19f);
    glVertex2f( 0.00f, -0.19f); 
    glVertex2f( 0.10f, -0.18f);
    glVertex2f( 0.10f, -0.18f); 
    glVertex2f( 0.18f, -0.22f);

    glVertex2f( 0.18f, -0.22f); 
    glVertex2f( 0.25f, -0.30f);
    glVertex2f( 0.25f, -0.30f); 
    glVertex2f( 0.38f, -0.38f);

    glVertex2f( 0.38f, -0.38f); 
    glVertex2f( 0.50f, -0.40f);
    glVertex2f( 0.50f, -0.40f); 
    glVertex2f( 0.65f, -0.35f);
    glVertex2f( 0.65f, -0.35f); 
    glVertex2f( 0.73f, -0.25f);

    glVertex2f( 0.73f, -0.25f); 
    glVertex2f( 0.78f, -0.10f);
    glVertex2f( 0.78f, -0.10f); 
    glVertex2f( 0.80f,  0.10f);
    glVertex2f( 0.80f,  0.10f); 
    glVertex2f( 0.75f,  0.30f);

    glVertex2f( 0.75f,  0.30f);
    glVertex2f( 0.65f,  0.45f);
    glVertex2f( 0.65f,  0.45f); 
    glVertex2f( 0.50f,  0.55f);
    glVertex2f( 0.50f,  0.55f); 
    glVertex2f( 0.35f,  0.60f);

    glVertex2f( 0.35f,  0.60f); 
    glVertex2f( 0.25f,  0.60f);
    glVertex2f( 0.25f,  0.60f); 
    glVertex2f( 0.10f,  0.55f);
    glVertex2f( 0.10f,  0.55f); 
    glVertex2f( 0.00f,  0.52f);

    glEnd();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Controle de Videogame");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
