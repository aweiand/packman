#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "extern.h"


void fantasma(){
    int i = 0;

        glColor3f(1,1,1);//COR DO CORPO DO FANTASMA BRANCA
    // DESENHO DO CORPO DO FANTASMA
        glBegin(GL_QUADS);
            glVertex3f(moveFantX+fantasmas[i][0][0], moveFantY+fantasmas[i][0][1], 0);
            glVertex3f(moveFantX+fantasmas[i][1][0], moveFantY+fantasmas[i][1][1], 0);
            glVertex3f(moveFantX+fantasmas[i][2][0], moveFantY+fantasmas[i][2][1], 0);
            glVertex3f(moveFantX+fantasmas[i][3][0], moveFantY+fantasmas[i][3][1], 0);
        glEnd();

    //OLHOS DO FANTASMA
        glColor3f(0,0,0);//OLHO DO FANTASMA PRETO ESQUERDO
        glPointSize(3.0);//TAMANHO DO PONTO
        glBegin(GL_POINTS);
            glVertex3f(moveFantX+fantasmas[i][4][0], moveFantY+fantasmas[i][4][1], 0);
        glEnd();

        glColor3f(0,0,0);//OLHO DO FANTASMA PRETO DIREITO
        glPointSize(3.0);//TAMANHO DO PONTO
        glBegin(GL_POINTS);
            glVertex3f(moveFantX+fantasmas[i][5][0], moveFantY+fantasmas[i][5][1], 0);
        glEnd();

    //BOCA DO FANTASMA
        glColor3f(0,0,0);//BOCA DO FANTASMA PRETO
        glLineWidth(2.0);//TAMANHO DO BOCA
        glBegin(GL_LINES);
            glVertex3f(moveFantX+fantasmas[i][6][0], moveFantY+fantasmas[i][6][1], 0);
            glVertex3f(moveFantX+fantasmas[i][7][0], moveFantY+fantasmas[i][7][1], 0);
        glEnd();

    //PÉ DO FANTASMA
        glColor3f(0,0,0);//BOCA DO FANTASMA PRETO
        glBegin(GL_TRIANGLES);
            glVertex3f(moveFantX+fantasmas[i][8][0], moveFantY+fantasmas[i][8][1], 0);
            glVertex3f(moveFantX+fantasmas[i][9][0], moveFantY+fantasmas[i][9][1], 0);
            glVertex3f(moveFantX+fantasmas[i][10][0], moveFantY+fantasmas[i][10][1], 0);
        glEnd();
}
