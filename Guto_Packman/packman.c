#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

#include "extern.h"

void packman(void){
    glColor3f(1,1,0);
    glBegin(GL_QUADS);
        glVertex3f(pX, pY, 0);
        glVertex3f(pX, pY+10, 0);
        glVertex3f(pX+10, pY+10, 0);
        glVertex3f(pX+10, pY, 0);
	glEnd();
}

void pacmanBola(){
  double i, angle, PI = 3.1415926535;

  glColor3f(1,1,0);
  glBegin(GL_POLYGON);
  for (i = 0; i < 150; i++){
    angle = 2*PI*i/150;
    glVertex2f(6*cos(angle)+pX, 6*sin(angle)+pY);
  }
  glEnd();
}

BOOL colisaoBarra(int Y, int X){
    int i;

    for(i=0;i<tam;i++){
        if ( (Y >= barras[i][0][1]) && (X >= barras[i][0][0]) &&
             (X <= barras[i][2][0]) && (Y <= barras[i][2][1])
            )
        /*
        if ( (pY >= 20) && (pX >=20) && (pX <= 30) && (pY <= 220) )
        */ {
            return TRUE;
            }

    }
    return FALSE;
}

void comeBolas(){
    int i;

    for(i=0;i<numBolas;i++){
        if ( (pY+5 >= bolas[i][0][1]) && (pX+5 >= bolas[i][0][0]) &&
             (pX-5 <= bolas[i][2][0]) && (pY-5 <= bolas[i][2][1])
            ){
            bolas[i][0][0] = -10;
            bolas[i][1][0] = -10;
            bolas[i][2][0] = -10;
            bolas[i][3][0] = -10;

            bolas[i][0][1] = -10;
            bolas[i][1][1] = -10;
            bolas[i][2][1] = -10;
            bolas[i][3][1] = -10;
            bolasComidas++;
        }
    }
}
