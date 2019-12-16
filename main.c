#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    system("clear");
    int opt, linhas, colunas;

    printf("Digite o tamanho da matriz: \n");
    printf("Linhas: ");
    scanf("%d", &linhas);
    printf("Colunas: ");
    scanf("%d", &colunas);

    Lista* elem_linhas[linhas];
    Lista* elem_colunas[colunas];

    //Colocando todas
    for(int i = 0; i < linhas; i++){
        elem_linhas[i] = NULL;
    }

    for(int i = 0; i < colunas; i++){
        elem_colunas[i] = NULL;
    }

    while (1)
    {
        opt = menu(opt, elem_linhas, elem_colunas, linhas, colunas);

        switch (opt)
        {
        case 1:
            inserir_elemento(elem_linhas, elem_colunas);
            break;

        case 2:
            imprime_lista(elem_linhas, linhas, colunas);
            printf("\nPressione enter para voltar...");
            getchar();
            getchar();
            break;

        case 3:
            desaloca(elem_linhas, linhas, colunas);
            return 0;
            break;

        default:
            printf("Opcao invalida, por favor digite novamente...\n");
            getchar();
            getchar();
            break;
        }
    }

    return 0;
}