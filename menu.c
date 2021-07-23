#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

void menuPrincipal(){

    Matriz matriz = NULL;
    int numeroLinhas = 0;
    int numeroColunas = 0;
    int op = 0;

    do{
        system("clear");
        printf("***** MATRIZ ESPARSA *****\n");

        printf("1 - Criar nova matriz\n2 - Inserir valor na matriz\n3 - Remover valor da matriz\n4 - Visualizar a matriz\n5 - Quantidade de linhas da matriz\n6 - Quantidade de colunas da matriz\n7 - Numero em uma posicao dada\n8 - Sair\nDigite qual opcao deseja: ");

        scanf("%d", &op);

        switch (op){
        case 1:

            if(matriz != NULL){
                printf("A Matriz ja foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }

            printf("Informe as dimensoes da matriz:\n");
            printf("Numero de linhas: ");
            scanf("%d", &numeroLinhas);
            printf("Numero de colunas: ");
            scanf("%d", &numeroColunas);
            matriz = criarMatriz(numeroLinhas, numeroColunas);

            if(matriz != NULL)
                printf("\nMatriz criada com sucesso!\n");
            else
                printf("\nFalha ao criar matriz\n");

            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 2:

            if(matriz == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }

            int novoNumero, linha, col;
            printf("Numero a ser adicionado: ");
            scanf("%d", &novoNumero);
            printf("Linha: ");
            scanf("%d", &linha);
            printf("Coluna: ");
            scanf("%d", &col);

            if(inserirNumero(matriz, novoNumero, linha, col))
                printf("Numero inserido com sucesso!\n");
            
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 3:

            if(matriz == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }

            printf("Linha: ");
            scanf("%d", &linha);
            printf("Coluna: ");
            scanf("%d", &col);
            
            if(removerNumero(matriz, linha, col))
                printf("Numero removido com sucesso!\n");
            
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 4:
            if(matriz == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }

            printMatrizFormatada(matriz);
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 5:
            if(matriz == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }
            
            int qtdLinhas = getQuantidadeLinhas(matriz);
            
            if(qtdLinhas != ERROR_ID)
                printf("\nA matriz tem %d Linhas\n", qtdLinhas);
            
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 6:
            if(matriz == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }

            int qtdColunas = getQuantidadeColunas(matriz);
            
            if(qtdColunas != ERROR_ID)
                printf("\nA matriz tem %d colunas\n", qtdColunas);
            
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 7:
             if(matriz == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break; 
            }

            printf("Linha: ");
            scanf("%d", &linha);
            printf("Coluna: ");
            scanf("%d", &col);

            int valor = getNumeroNaPosicao(matriz, linha, col);
            
            if(valor != ERROR_ID)
                printf("\nO valor nessa posicao e: %d\n", valor);

            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;


        case 8: 
            printf("\nSaindo do programa...\n\n");
            freeMatriz(matriz);
            break;
        
        default:
            printf("\nOpcao invalida, tente novamente!\n");
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;
        }
    
    }while(op != 8);
}