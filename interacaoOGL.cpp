#include <GL/glut.h>
#include <stdlib.h> // Necessário para a função exit()
#include <math.h> //mat

// --- Variáveis Globais ---
// Animação do triângulo
float anguloTriangulo = 0.0f;

// Posição do nosso quadrado controlado pelo jogador
float jogadorX = 0.0f;
float jogadorY = 0.0f;
float velocidade = 0.05f; // O quanto o quadrado anda a cada toque na tecla

// --- Função de Desenho ---
void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);


    // 2. Quadrado Controlado pelo Jogador
    glPushMatrix();
    // Usamos as variáveis que o teclado vai modificar
    glTranslatef(jogadorX, jogadorY, 0.0f); 
    
glBegin(GL_TRIANGLE_FAN);
glColor3f(1.0f, 0.5f, 0.0f);

float raio = 0.1f;
glVertex2f(0.0f, 0.0f);
for (int i = 0; i <=100; i++) {
    float ang = i * (2 * 3.14159f / 100);
    glVertex2f(cos(ang) * raio, sin(ang) * raio);
}

glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

// --- Funções de Teclado ---

void tecladoNormal(unsigned char key, int x, int y) {
    

    switch (key) {
        case 'w':
        case 'W':
            jogadorY += velocidade;
            break;
        case 's':
        case 'S':
            jogadorY -= velocidade;
            break;
        case 'a':
        case 'A':
            jogadorX -= velocidade;
            break;
        case 'd':
        case 'D':
            jogadorX += velocidade;
            break;
        case 27: // ESC
            exit(0);
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
    glutKeyboardFunc(tecladoNormal);
    
    glutTimerFunc(25, atualizaAnimacao, 0);
    
    glutMainLoop();
    return 0;
}