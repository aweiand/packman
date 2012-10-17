//M�todos ### mapa.c

//M�todo respons�vel por desenhar a tela -> mapa.c
void tela();

//M�todo respons�vel por desenhar o mapa na tela -> mapa.c
void mapa();

// -> mapa.c
void montaBolas();

//M�todo respons�vel por desenhar as bolas na tela -> mapa.c
void desenhaBolas();

//##################




//M�todos ## utilitarios.c

//M�todo respons�vel por alterar o tamanho da janela -> utilitarios.c
void AlteraTamanhoJanela(GLsizei w, GLsizei h);

//M�todo respons�vel por inicializar o sistema -> utilitarios.c
void Inicializa (void);

//M�todo respons�vel por desenhar textos na tela -> utilitarios.c
void txtGanhou();

void DesenhaTexto(char *string);

// ######################




//M�todos ### movimento.c

//M�todo respons�vel por fazer o packman andar -> movimento.c
void andarPackman(int key, int x, int y);

void movimentar(int passo);

// ######################



//M�todos ### packman.c

//M�todo respons�vel por detectar colis�o nas barras -> packman.c
BOOL colisaoBarra(int Y, int X);

//M�todo respons�vel por comer as bolas da tela -> packman.c
void comeBolas();

//M�todo respons�vel por desenhar o packman na tela -> packman.c
void packman(void);

//M�todo para desenhar o packman no estilo bola -> packman.c
void pacmanBola();

// ######################




// M�todos ## fantasma.c

//M�todo para desenhar os fantasmas -> fantasma.c
void fantasma();

// ######################
