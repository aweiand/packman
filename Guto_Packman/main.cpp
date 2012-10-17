#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "extern.h"
#include "mapa.c"
#include "packman.c"
#include "utilitarios.c"
#include "movimento.c"
#include "fantasma.c"

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	//Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	//Desenho a tela
    tela();

    //Desenho o mapa
    mapa();

    //Desenho as bolas
    desenhaBolas();

    //desenho o packman
    //packman();
    pacmanBola();

    fantasma();

    //função para debug de posição do packman
    //DesenhaTexto(texto);

	//Executa os comandos OpenGL
	glFlush();
}

// Programa Principal
int main(void)
{
    montaBolas();

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(430,250);
    glutInitWindowPosition(450,250);

	glutCreateWindow("Packman Guto");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
    glutSpecialFunc(andarPackman);
    glutTimerFunc(10,movimentar,1);
	Inicializa();
	glutMainLoop();
}
