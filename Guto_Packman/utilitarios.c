#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extern.h"

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Estabelece a janela de seleção (left, right, bottom, top)
    if (w <= h)
           gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
    else
           gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void txtGanhou() {
	glColor3f(1,1,1);
	glRasterPos2f(11, 21.0);
	char* p = (char*) "Voce Ganhou!";
	while (*p != '\0'){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
	}
}

// Desenha um texto na janela GLUT
void DesenhaTexto(char *string){
    sprintf(texto, "Pack (%d,%d) | Fant (%d,%d)", pX, pY, moveFantX+fantasmas[0][1][0], moveFantY+fantasmas[0][1][1]);
  	glColor3f(1,1,1);
    // Posição no universo onde o texto será colocado
    glRasterPos2f(155,50);
    // Exibe caracter a caracter
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,*string++);
}
