#include <GL/glut.h>

bool useSmooth = false;

void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Fundo cinza escuro para contraste
    glEnable(GL_DEPTH_TEST);
    
    // Configuração de Luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    GLfloat light_pos[] = { 5.0, 5.0, 5.0, 1.0 };
    GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Câmera: Afastada em 5 unidades no eixo Z
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Alternar sombreamento
    if (useSmooth) glShadeModel(GL_SMOOTH);
    else glShadeModel(GL_FLAT);

    // Definir cor do material (DIFUSA)
    GLfloat mat_color[] = { 0.7, 0.2, 0.2, 1.0 }; // Vermelho
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_color);

    // Desenha a esfera (tamanho 1.5, baixa resolução)
    glutSolidSphere(1.5, 16, 16);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 's') useSmooth = true;
    if (key == 'f') useSmooth = false;
    glutPostRedisplay();
}

// Caso a janela seja redimensionada
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exercicio Interpolacao");
    
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}