#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "extern.h"
#include "metodos.h"

void tela(){
    glBegin(GL_LINES);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(10.0f,10.0f);
        glVertex2f(10.0f,240.0f);
        glVertex2f(10.0f,240.0f);
        glVertex2f(420.0f,240.0f);
        glVertex2f(420.0f,240.0f);
        glVertex2f(420.0f,10.0f);
        glVertex2f(420.0f,10.0f);
        glVertex2f(10.0f,10.0f);
    glEnd();
}

void mapa(){
	int i;
    glColor3f(0.5,0.5,0.5);//COR DO BLOCO

    for (i=0;i<tam;i++){
        glBegin(GL_QUADS);
            glVertex3i(barras[i][0][0],barras[i][0][1],0);
            glVertex3i(barras[i][1][0],barras[i][1][1],0);
            glVertex3i(barras[i][2][0],barras[i][2][1],0);
            glVertex3i(barras[i][3][0],barras[i][3][1],0);
        glEnd();
    }
}

void montaBolas(){
    int n = 0,x,y;

    for(x=18;x<410;x+=espacoBola){
        for(y=18;y<230;y+=espacoBola){
            if (!colisaoBarra(y,x) && !colisaoBarra(y+5,x) && !colisaoBarra(y,x+5) && n<numBolas){
                bolas[n][0][0] = x;
                bolas[n][1][0] = x;
                bolas[n][2][0] = x+5;
                bolas[n][3][0] = x+5;

                bolas[n][0][1] = y;
                bolas[n][1][1] = y+5;
                bolas[n][2][1] = y+5;
                bolas[n][3][1] = y;
                n++;
            }
        }
    }

}

void desenhaBolas(){
    int n = 0;

    //verifica se as bolas foram comidas antes de redesenha-las
    comeBolas();

    for(n=0;n<numBolas;n++){
        glColor3f(1,1,0);
        glBegin(GL_QUADS);
            glVertex3f(bolas[n][0][0], bolas[n][0][1], 0);
            glVertex3f(bolas[n][1][0], bolas[n][1][1], 0);
            glVertex3f(bolas[n][2][0], bolas[n][2][1], 0);
            glVertex3f(bolas[n][3][0], bolas[n][3][1], 0);
        glEnd();
    }

    if(bolasComidas == numBolas){
        glClear(GL_COLOR_BUFFER_BIT);
        txtGanhou();
        glutSwapBuffers();
    }
}
