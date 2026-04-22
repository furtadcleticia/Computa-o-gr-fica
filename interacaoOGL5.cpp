#include <GL/glut.h>
#include <stdlib.h> // Necessário para a função exit()

// --- Variáveis Globais ---
// Animação do triângulo
float anguloTriangulo = 0.0f;
float r = 1.0f;


// Posição do nosso quadrado controlado pelo jogador
float jogadorX1 = 0.0f;
float jogadorY1 = 0.0f;
float jogadorX2 = 0.0f;
float jogadorY2 = 0.0f;
float velocidade = 0.05f; // O quanto o quadrado anda a cada toque na tecla

// --- Função de Desenho ---
void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);


    // QUADRADO 1
glPushMatrix();
glTranslatef(jogadorX1, jogadorY1, 0.0f);

glColor3f(1.0f,0.0f,0.0f);
glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f( 0.1f, -0.1f);
    glVertex2f( 0.1f,  0.1f);
    glVertex2f(-0.1f,  0.1f);
glEnd();

glPopMatrix();


// QUADRADO 2
glPushMatrix();
glTranslatef(jogadorX2, jogadorY2, 0.0f);

glColor3f(0.0f,1.0f,0.0f);
glBegin(GL_QUADS);
    glVertex2f(0.3f, 0.2f);
    glVertex2f( 0.3f, 0.3f);
    glVertex2f( 0.2f,  0.3f);
    glVertex2f(0.2f,  0.2f);
glEnd();

glPopMatrix();

    glutSwapBuffers();
}

// --- Funções de Teclado ---

// Para teclas direcionais (Setas)
// teclado 

void tecladoEspecial(unsigned char key, int x, int y) {
    float velocidade = 0.05f;

   switch (key) {
    case 'w':
    case 'W':
        jogadorY1 += velocidade;
        break;

    case 's':
    case 'S':
        jogadorY1 -= velocidade;
        break;

    case 'a':
    case 'A':
        jogadorX1 -= velocidade;
        break;

    case 'd':
    case 'D':
        jogadorX1 += velocidade;
        break;
}
switch (key) {
    case 'i':
    case 'I':
        jogadorY2 += velocidade;
        break;

    case 'j':
    case 'J':
        jogadorY2 -= velocidade;
        break;

    case 'k':
    case 'K':
        jogadorX2 -= velocidade;
        break;

    case 'l':
    case 'L':
        jogadorX2 += velocidade;
        break;
}
    glutPostRedisplay();
}


// --- Função de Animação Contínua ---
void atualizaAnimacao(int valor) {
    anguloTriangulo += 2.0f;
    if (anguloTriangulo > 360.0f) {
        anguloTriangulo -= 360.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, atualizaAnimacao, 0);
}

// --- Função Principal ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Interacao com Teclado (Setas e ESC)");
    
    // Registrando os Callbacks
    glutDisplayFunc(desenhaCena);
    
    // NOSSOS NOVOS CALLBACKS DE TECLADO:
    glutKeyboardFunc(tecladoEspecial);

    
    glutTimerFunc(25, atualizaAnimacao, 0);
    
    glutMainLoop();
    return 0;
}