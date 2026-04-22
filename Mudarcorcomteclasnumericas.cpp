#include <GL/glut.h>
#include <stdlib.h> // Necessário para a função exit()

// --- Variáveis Globais ---
// Animação do triângulo
float anguloTriangulo = 0.0f;
float r = 1.0f;
float g = 0.5f;
float b = 0.0f;

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
        glColor3f(r, g, b);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f( 0.1f, -0.1f);
        glVertex2f( 0.1f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

// --- Funções de Teclado ---

// Para teclas direcionais (Setas)
void tecladoEspecial(int key, int x, int y) {
    float limite = 0.1f; // metade do tamanho do quadrado

    switch (key) {
        case GLUT_KEY_UP:
            if (jogadorY  + limite <= 1.0f)
                jogadorY += velocidade;
            break;

        case GLUT_KEY_DOWN:
            if (jogadorY  - limite >= -1.0f)
                jogadorY -= velocidade;
            break;

        case GLUT_KEY_LEFT:
            if (jogadorX - limite >= -1.0f)
                jogadorX -= velocidade;
            break;

        case GLUT_KEY_RIGHT:
            if (jogadorX  + limite <= 1.0f)
                jogadorX += velocidade;
            break;
    }

    glutPostRedisplay();
}

// rgb

void tecladoNormal(unsigned char key, int x, int y) {

    switch (key) {
        case '1': // vermelho
            r = 1.0f; g = 0.0f; b = 0.0f;
            break;

        case '2': // verde
            r = 0.0f; g = 1.0f; b = 0.0f;
            break;

        case '3': // azul
            r = 0.0f; g = 0.0f; b = 1.0f;
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
    glutSpecialFunc(tecladoEspecial);
    glutKeyboardFunc(tecladoNormal);
    
    glutTimerFunc(25, atualizaAnimacao, 0);
    
    glutMainLoop();
    return 0;
}
