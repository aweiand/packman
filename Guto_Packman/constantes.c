#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "extern.h"

char texto[30];

//Posi��o do Packman
GLint pX=400;
GLint pY=30;

GLint moveFantX=15;
GLint moveFantY=3;

GLint direcao=1;
GLint vitoria=0;


//N�mero de bolas comidas
int bolasComidas = 0;

//N�mero de bolas a ser plotado
int numBolas   = 136;

//Espa�o entre as bolas
int espacoBola = 15;

//Tamanho da matriz de barras
int tam = 22;

//Velocidade do Packman
int vel = 5;

//Matriz de barras
GLint barras[][4][2] =
{
//Barra 1
        {   {0, 0},{0, 250},{20, 250},{20, 0}   },

//Barra 2
        {   {20, 230},{20, 250},{410, 250},{420, 230}   },

//Barra 3
        {   {410, 0},{410, 250},{430, 250},{430, 0}   },

//Barra 4
        {   {20, 0},{20, 20},{410, 20},{410, 0}   },

//Barra 5
        {   {40, 190},{40, 210},{90, 210},{90, 190}   },

//Barra 6
        {   {110, 190},{110, 210},{186, 210},{186, 190}   },

//Barra 7
        {   {206, 190},{206, 230},{226, 230},{226, 190}   },

//Barra 8
        {   {246, 190},{246, 210},{322, 210},{322, 190}   },

//Barra 9
        {   {342, 190},{342, 210},{390, 210},{390, 190}   },

//Barra 10
        {   {40, 150},{40, 170},{90, 170},{90, 150}   },

//Barra 11
        {   {110, 40},{110, 170},{130, 170},{130, 40}   },

//Barra 12
        {   {150, 150},{150, 170},{282, 170},{282, 150}   },

//Barra 13
        {   {302, 40},{302, 170},{322, 170},{322, 40}   },

//Barra 14
        {   {342, 150},{342, 170},{390, 170},{390, 150}   },

//Barra 15
        {   {20, 110},{20, 130},{90, 130},{90, 110}   },

//Barra 16
        {   {130, 110},{130, 130},{186, 130},{186, 110}   },

//Barra 17
        {   {206, 110},{206, 150},{226, 150},{226, 110}   },

//Barra 18
        {   {246, 110},{246, 130},{302, 130},{302, 110}   },

//Barra 19
        {   {342, 110},{342, 130},{410, 130},{410, 110}   },

//Barra 20
        {   {40, 40},{40, 90},{90, 90},{90, 40}   },

//Barra 21
        {   {150, 40},{150, 90},{282, 90},{282, 40}   },

//Barra 22
        {   {342, 40},{342, 90},{390, 90},{390, 40}   }

};

//Matriz de bolas
GLint bolas[][4][2];


//Matriz de fantasmas
GLint fantasmas[][11][2] =
{
//Fantasma 1
    {   {24, 36},{24, 18},{7, 18},{7, 36},{11, 32},{20, 32},{12, 27},{19, 27},{7, 18},{15, 22},{24, 18}   },

    {   {60, 30},{60, 50},{75, 50},{75, 30},{63, 43},{70, 43},{62, 38},{72, 38},{60, 30},{68, 35},{75, 30}   }
};
