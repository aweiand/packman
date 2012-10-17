#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

#include "extern.h"

//MOVER O PACKMAN
void andarPackman(int key, int x, int y) {
    if(key == GLUT_KEY_UP)
        pY += vel;

    //Testando de o packman bateu em uma barra
    if (colisaoBarra(pY+vel,pX))
        pY -= vel;

    if(key == GLUT_KEY_DOWN)
        pY -= vel;

    //Testando de o packman bateu em uma barra
    if (colisaoBarra(pY-vel,pX))
        pY += vel;

    if(key == GLUT_KEY_LEFT)
        pX -= vel;

    //Testando de o packman bateu em uma barra
    if (colisaoBarra(pY,pX-vel))
        pX += vel;

    if(key == GLUT_KEY_RIGHT)
        pX += vel;

    //Testando de o packman bateu em uma barra
    if (colisaoBarra(pY,pX+vel))
        pX -= vel;

    //DEIXANDO O PACKMAN NO LIMITE DA TELA
    if (pY < 20)
        pY = 20;

    if (pY > 230)
        pY = 230;

    if (pX < 20)
        pX = 20;

    if (pX > 410)
        pX = 410;

    //Desenha as bolas retirando as comidas
    desenhaBolas();

    glutPostRedisplay();
}


void movimentar(int passo){
    int i = 0;

    if (moveFantY+fantasmas[i][0][1] <= 20)
        direcao = 0;

    if (moveFantX+fantasmas[i][3][0] >= 410)
        direcao = 1;

    if (moveFantX+fantasmas[i][0][0] <= 20)
        direcao = 2;

    if (moveFantY+fantasmas[i][1][1] >= 230)
        direcao = 3;

    if(!colisaoBarra(moveFantY+fantasmas[i][3][1], moveFantX+fantasmas[i][3][0]) && direcao == 1){
        moveFantX += vel;
        direcao = 1;
        if (colisaoBarra(moveFantY+fantasmas[i][3][1], moveFantX+21+fantasmas[i][3][0]))
            direcao = 0;
    }


    if(!colisaoBarra(moveFantY+fantasmas[i][1][1], moveFantX-fantasmas[i][1][0]) && direcao == 2){
        moveFantX -= vel;
        direcao = 2;
        if (colisaoBarra(moveFantY+fantasmas[i][1][1], fantasmas[i][1][0]-moveFantX-vel-2))
            direcao = 3;
    }

    if(!colisaoBarra(moveFantY+fantasmas[i][2][1], moveFantX+fantasmas[i][1][0]) && direcao == 0){
        moveFantY += vel;
        direcao = 0;
        if (colisaoBarra(moveFantY+22+fantasmas[i][2][1], moveFantX+fantasmas[i][1][0]))
            direcao = 2;
    }

    if(!colisaoBarra(moveFantY-fantasmas[i][0][1], moveFantX+fantasmas[i][0][0]) && direcao == 3){
        moveFantY -= vel;
        direcao = 3;
        if (colisaoBarra(fantasmas[i][0][1]-moveFantY-vel-2, moveFantX+fantasmas[i][0][0]))
            direcao = 2;
    }

    if ( (pX >= moveFantX+fantasmas[i][0][0]-19) &&
         (pX <= moveFantX+fantasmas[i][3][0]+19) &&
         (pY >= moveFantY+fantasmas[i][0][1]-19) &&
         (pY <= moveFantY+fantasmas[i][1][1]+19) )
         {
            pX = 20;
            pY = 20;
         }

    glutPostRedisplay();
    glutTimerFunc(60,movimentar, 1);
}
