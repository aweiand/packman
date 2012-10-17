//Métodos ### mapa.c

//Método responsável por desenhar a tela -> mapa.c
void tela();

//Método responsável por desenhar o mapa na tela -> mapa.c
void mapa();

// -> mapa.c
void montaBolas();

//Método responsável por desenhar as bolas na tela -> mapa.c
void desenhaBolas();

//##################




//Métodos ## utilitarios.c

//Método responsável por alterar o tamanho da janela -> utilitarios.c
void AlteraTamanhoJanela(GLsizei w, GLsizei h);

//Método responsável por inicializar o sistema -> utilitarios.c
void Inicializa (void);

//Método responsável por desenhar textos na tela -> utilitarios.c
void txtGanhou();

void DesenhaTexto(char *string);

// ######################




//Métodos ### movimento.c

//Método responsável por fazer o packman andar -> movimento.c
void andarPackman(int key, int x, int y);

void movimentar(int passo);

// ######################



//Métodos ### packman.c

//Método responsável por detectar colisão nas barras -> packman.c
BOOL colisaoBarra(int Y, int X);

//Método responsável por comer as bolas da tela -> packman.c
void comeBolas();

//Método responsável por desenhar o packman na tela -> packman.c
void packman(void);

//Método para desenhar o packman no estilo bola -> packman.c
void pacmanBola();

// ######################




// Métodos ## fantasma.c

//Método para desenhar os fantasmas -> fantasma.c
void fantasma();

// ######################
