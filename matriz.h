/* Interface da Matriz Dinâmica */

#define ERROR_ID -100000000

typedef void* Matriz;

/* Cria uma matriz vazia com a quatidade de linhas e colunas informadas nos parametros. */
Matriz criarMatriz(int qtdLinhas, int qtdColunas);

/* Insere um novo valor em uma posicao especificada da matriz */
int inserirNumero(Matriz Mat, int valor, int linha, int coluna);

/* Remove o valor de uma posicao da matriz */
int removerNumero(Matriz Mat, int linhaID, int colunaID);

/* Imprime na tela a matriz de forma formatada */
void printMatrizFormatada(Matriz Mat);

/* Retorna a quantidade de linhas que a matriz possui */ 
int getQuantidadeLinhas(Matriz Mat);

/* Retorna a quantidade de colunas que a matriz possui */
int getQuantidadeColunas(Matriz Mat);

/* Retorna o valor contido na posicao especificada */ 
int getNumeroNaPosicao(Matriz Mat, int linhaID, int colunaID);

/* Libera toda a memoria utilizada pela matriz */
void freeMatriz(Matriz Mat);