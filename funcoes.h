typedef struct lista Lista;

struct lista
{
    int valor;
    int linhas;
    int colunas;
    Lista *prox_linha;
    Lista *prox_coluna;
};

//Prototipo da função de menu principal
int menu(int opt, Lista **elem_linhas, Lista **elem_colunas, int linhas, int colunas);

//Prototipo da função de inserir elemento
int inserir_elemento(Lista **elem_linhas, Lista **elem_colunas);

//Prototipo da função de printar matriz
int imprime_lista(Lista **elem_linhas, int linhas, int colunas);

//Prototipo da função que libera memoria
int desaloca(Lista **elem_linhas, int linhas, int colunas);
