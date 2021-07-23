/* Interface da Matriz Dinâmica */

#define ERROR_ID -100000000

typedef void* Matriz;

/* Cria uma matriz vazia com a quatidade de linhas e colunas informadas nos parametros. */
Matriz createMatrix(int qtdLinhas, int qtdColunas);

/* Insere um novo valor em uma posicao especificada da matriz */
int insertNumber(Matriz Mat, int valor, int linha, int coluna);

/* Remove o valor de uma posicao da matriz */
int removeNumber(Matriz Mat, int linhaID, int colunaID);

/* Imprime na tela a matriz de forma formatada */
void printFormattedMatrix(Matriz Mat);

/* Retorna a quantidade de linhas que a matriz possui */ 
int getQuantidadeLinhas(Matriz Mat);

/* Retorna a quantidade de colunas que a matriz possui */
int getQuantidadeColunas(Matriz Mat);

/* Retorna o valor contido na posicao especificada */ 
int getNumberInPosition(Matriz Mat, int linhaID, int colunaID);

/* Libera toda a memoria utilizada pela matriz */
void freeMatrix(Matriz Mat);