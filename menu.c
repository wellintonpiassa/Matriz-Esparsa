#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void mainMenu(){

    Matriz matrix = NULL;
    int rowNumber = 0;
    int colNumber = 0;
    int opt = 0;

    do{
        system("clear");
        printf("***** MATRIZ ESPARSA *****\n");

        printf("1 - Criar nova matriz\n2 - Inserir valor na matriz\n3 - Remover valor da matriz\n4 - Visualizar a matriz\n5 - Quantidade de linhas da matriz\n6 - Quantidade de colunas da matriz\n7 - Numero em uma posicao dada\n8 - Sair\nDigite qual opcao deseja: ");

        scanf("%d", &opt);

        switch (opt){
        case 1:

            if(matrix != NULL){
                printf("A Matriz ja foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }

            printf("Informe as dimensoes da matriz:\n");
            printf("Numero de linhas: ");
            scanf("%d", &rowNumber);
            printf("Numero de colunas: ");
            scanf("%d", &colNumber);
            matrix = createMatrix(rowNumber, colNumber);

            if(matrix != NULL)
                printf("\nMatriz criada com sucesso!\n");
            else
                printf("\nFalha ao criar matriz\n");

            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 2:

            if(matrix == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }

            int numberToAdd, line, col;
            printf("Numero a ser adicionado: ");
            scanf("%d", &numberToAdd);
            printf("Linha: ");
            scanf("%d", &line);
            printf("Coluna: ");
            scanf("%d", &col);

            if(insertNumber(matrix, numberToAdd, line, col))
                printf("Numero inserido com sucesso!\n");
            
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 3:

            if(matrix == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }

            printf("Linha: ");
            scanf("%d", &line);
            printf("Coluna: ");
            scanf("%d", &col);
            
            if(removeNumber(matrix, line, col))
                printf("Numero removido com sucesso!\n");
            
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 4:
            if(matrix == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }

            printFormattedMatrix(matrix);
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 5:
            if(matrix == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }
            
            int qtdLinhas = getQuantidadeLinhas(matrix);
            
            if(qtdLinhas != ERROR_ID)
                printf("\nA matriz tem %d Linhas\n", qtdLinhas);
            
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 6:
            if(matrix == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break;
            }

            int qtdColunas = getQuantidadeColunas(matrix);
            
            if(qtdColunas != ERROR_ID)
                printf("\nA matriz tem %d colunas\n", qtdColunas);
            
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;

        case 7:
             if(matrix == NULL){
                printf("A Matriz ainda nao foi criada!\nPressione Enter...");
                getchar(); getchar();
                break; 
            }

            printf("Linha: ");
            scanf("%d", &line);
            printf("Coluna: ");
            scanf("%d", &col);

            int valor = getNumberInPosition(matrix, line, col);
            
            if(valor != ERROR_ID)
                printf("\nO valor nessa posicao e: %d\n", valor);

            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;


        case 8: 
            printf("\nSaindo do programa...\n\n");
            freeMatrix(matrix);
            break;
        
        default:
            printf("\nOpcao invalida, tente novamente!\n");
            printf("\nPressione Enter para voltar ao menu...");
            getchar(); getchar();
            break;
        }
    
    }while(opt != 8);
}