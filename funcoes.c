#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

//Função de menu principal
int menu(int opt, Lista **elem_linhas, Lista **elem_colunas, int linhas, int colunas)
{
    system("clear");
    printf("------------------\n");
    printf("  MATRIZ ESPARCA \n");
    printf("------------------\n");
    printf("Tamanho da matriz: [%d][%d]\n", linhas, colunas);
    printf("Selecione a opcao desejada: \n");
    printf("1 - Inserir elemento na matriz\n");
    printf("2 - Imprimir elementos\n");
    printf("3 - Sair do programa\n");
    printf("\nOpcao: ");
    scanf("%d", &opt);
    return opt;
}

//Função de inserção de elementos
int inserir_elemento(Lista **elem_linhas, Lista **elem_colunas)
{
    //Alocando memória dinâmicamente
    Lista *no;
    no = (Lista*)malloc(sizeof(Lista));

    //Verificando se memoria foi alocada
    if(no == NULL){
        printf("Erro ao alocar memoria\nPressione enter para voltar ao menu...\n");
        getchar();
        getchar();
        return 0;
    }

    //Colocando prox linha prox coluna apontando para NULL
    no->prox_linha = NULL;
    no->prox_coluna = NULL;

    //Recebendo informações do usuario (Valor que deseja inserir, e a linha junto com a coluna)
    system("clear");
    printf("Qual valor deseja inserir: ");
    scanf("%d", &(no->valor));
    printf("Em qual linha: ");
    scanf("%d", &(no->linhas));
    printf("Em qual coluna: ");
    scanf("%d", &(no->colunas));

    //Insere no começo
    //Linha
    if(elem_linhas[no->linhas] == NULL && elem_colunas[no->colunas] == NULL)
    {
        elem_linhas[no->linhas] = no;
        elem_colunas[no->colunas] = no;
    }

    else if(elem_linhas[no->linhas] == NULL && elem_colunas[no->colunas] != NULL)
    {
        Lista *ptr;
        ptr = elem_colunas[no->colunas];

        while(ptr->prox_linha != NULL)
        {
            ptr = ptr->prox_linha;
        }

        ptr->prox_linha = no;
        elem_linhas[no->linhas] = no;
    }

    else if(elem_linhas[no->linhas] != NULL && elem_colunas[no->colunas] == NULL)
    {
        Lista *ptr;
        ptr = elem_linhas[no->linhas];

        while(ptr->prox_linha != NULL)
        {
            ptr = ptr->prox_coluna;
        }

        ptr->prox_coluna = no;
        elem_linhas[no->linhas] = no;
    }

    else{
        Lista *ant;
        Lista *atual;
        atual = elem_linhas[no->linhas];
        ant = atual;

        while(atual->colunas < no->colunas)
        {
            ant = atual;
            atual = atual->prox_coluna;
        }

        ant->prox_coluna = no;
        no->prox_coluna = atual;

        atual = elem_colunas[no->colunas];
        ant = atual;

        while (atual->linhas < no->linhas)
        {
            ant = atual;
            atual = atual->prox_linha;
        }

        ant->prox_linha = no;
        no->prox_linha = atual;
    }
    return 0;
}

int imprime_lista(Lista **elem_linhas, int linhas, int colunas)
{
    Lista *ptr;
    int i,j;

    for(i = 0; i < linhas; i++)
    {
        if(elem_linhas[i] != NULL){
            ptr = elem_linhas[i];

            for(j = 0; j < colunas; j++)
            {
                if(j == ptr->colunas)
                {
                    printf("%d ", ptr->valor);

                    if(ptr->prox_coluna != NULL)
                        ptr = ptr->prox_coluna;
                }

                else
                    printf("0 ");
            }
            printf("\n");
        }

        else
            printf("0 ");
    }
}

int desaloca(Lista **elem_linhas, int linhas, int colunas)
{
    for(int i = 0; i < linhas; i++)
    {
        if(elem_linhas[i] != NULL)
        {
            Lista *ptr;

            while(elem_linhas[i] != NULL)
            {
                ptr = elem_linhas[i];
                elem_linhas[i] = elem_linhas[i]->prox_linha;
                free(ptr);
            }
        }

    }

    return 0;
}