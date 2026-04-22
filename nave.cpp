#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // 1. Alterando o estado do rasterizador: Espessura da linha
    glLineWidth(5.0f); 

    // 2. Alterando o estado do rasterizador: Modo tracejado (Stipple)
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF); // Padrão de repetição e máscara (0x00FF cria traços longos)

    glColor3f(0.0f, 1.0f, 1.0f); // Cor ciano para a nave

    glBegin(GL_LINES);
        // --- Corpo da Nave (Base Elíptica Simplificada) ---
        glVertex2f(-0.8f, 0.0f);  glVertex2f(0.8f, 0.0f);   // Linha central
        glVertex2f(-0.8f, 0.0f);  glVertex2f(-0.4f, -0.3f); // Curva inferior esquerda
        glVertex2f(-0.4f, -0.3f); glVertex2f(0.4f, -0.3f);  // Base inferior
        glVertex2f(0.4f, -0.3f);  glVertex2f(0.8f, 0.0f);   // Curva inferior direita
        
        glVertex2f(-0.8f, 0.0f);  glVertex2f(-0.5f, 0.2f);  // Curva superior esquerda
        glVertex2f(-0.5f, 0.2f);  glVertex2f(0.5f, 0.2f);   // Topo do corpo
        glVertex2f(0.5f, 0.2f);   glVertex2f(0.8f, 0.0f);   // Curva superior direita

        // --- Cúpula (Cabine) ---
        glVertex2f(-0.3f, 0.2f);  glVertex2f(0.0f, 0.6f);   // Lado esquerdo da cúpula
        glVertex2f(0.0f, 0.6f);   glVertex2f(0.3f, 0.2f);   // Lado direito da cúpula

        // --- Pés de Pouso ---
        glVertex2f(-0.4f, -0.3f); glVertex2f(-0.5f, -0.5f); // Pé esquerdo
        glVertex2f(0.4f, -0.3f);  glVertex2f(0.5f, -0.5f);  // Pé direito
    glEnd();

    glDisable(GL_LINE_STIPPLE); // Desativa para não afetar outros desenhos
    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fundo preto
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Sistema de coordenadas de -1 a 1
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Nave Espacial - Rasterizacao de Linhas");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}