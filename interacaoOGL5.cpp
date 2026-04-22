#include <GL/glut.h>
#include <stdlib.h> // Necessário para a função exit()

float r=0.0f;
float g= 1.0f;
float b=0.0f;
float x=0.0f;
float y=0.0f;
float multiplicador= 1.0f;
float velocidade = 0.05f; // O quanto o quadrado anda a cada toque na tecla

// --- Função de Desenho ---
void desenhaQuadrado(float x, float y, float r, float g, float b){
    float size=0.1f;
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(x-size*multiplicador, y-size*multiplicador);
    glVertex2f(x+size*multiplicador, y-size*multiplicador);
    glVertex2f(x+size*multiplicador, y+size*multiplicador);
    glVertex2f(x-size*multiplicador, y+size*multiplicador);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    desenhaQuadrado(x,y,r,g,b);

    glFlush();
}


// --- Funções de Teclado ---

// Para teclas direcionais (Setas)
// teclado 


void tecladonormal (unsigned char key, int xinutil, int yinutil) { 
    float velocidade = 0.05f;
    

   switch (key) { //opção
    case 'w': //caso apertar no W do teclado
        y += velocidade; //incrementa 0.05f no eixo y 
        break;

    case 's': //caso apertar a tecla s no mouse
        y -= velocidade; // decrementa 0.05f no eixo y
        break;

    case 'a': //caso apertar a letra a maiscula ou minuscula
        x -= velocidade; //decrementa 0.05 do eixo x
        break;

    case 'd': //caso apertar na tecla d maicula ou minuscula pelo teclado
        x += velocidade; //incrementa 0.05 no eixo x
        break;

    case 43:
        multiplicador+=0.1f;
        break;

    case 45:
        multiplicador-=0.1f;
        break;


}

    glutPostRedisplay();
}

void mouse(int button, int state, int xinutil, int yinutil) {
  

    switch (button) { //opcao com botao 
        case GLUT_LEFT_BUTTON: //caso apertar no botao esquerdo
            r=1.0f; g=0.0f; b=0.0f; //vermelho
            break;

        case GLUT_RIGHT_BUTTON: //caso apertar no botao direito
        r=0.0f; g=0.0f;b= 1.0f; //blue
            break;

        case GLUT_MIDDLE_BUTTON:
        x=0.0f, y=0.0f;
        break;

    }

    glutPostRedisplay();
}


// --- Função Principal ---
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Interacao com Teclado (Setas e ESC)");
    
    glClearColor(0.0,0.0,0.0,1.0);
    // Registrando os Callbacks
    glutDisplayFunc(display);
    
    // NOSSOS NOVOS CALLBACKS DE TECLADO:

    glutKeyboardFunc(tecladonormal); 
    glutMouseFunc(mouse);

    
    glutMainLoop();
    return 0;
}