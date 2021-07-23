#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

typedef struct Coluna coluna;

struct Coluna{
    int valor;
    int idColuna;
    coluna *proxCol;
};

typedef struct {
    int idLinha;
    int colunasOcupadas;
    coluna* colunas;
}linha;

typedef struct {
    int qtdLinhas;
    int qtdColunas;
    linha** linhas;
}matriz;


/* Linhas e colunas da matriz iniciam com 1 */

Matriz createMatrix(int qtdLinhas, int qtdColunas){

    matriz* mat = (matriz*) malloc(sizeof(matriz));

    mat->qtdLinhas = qtdLinhas;
    mat->qtdColunas = qtdColunas;
    
    mat->linhas = (linha**) malloc(qtdLinhas * sizeof(linha*));

    for(int i=0; i < qtdLinhas; i++){
        mat->linhas[i] = (linha*) malloc(sizeof(linha));
        mat->linhas[i]->colunas = NULL;
        mat->linhas[i]->idLinha = i+1;
        mat->linhas[i]->colunasOcupadas = 0;
    }

    return mat;
}


int insertNumber(Matriz Mat, int valor, int linhaDestino, int colunaDestino){
    if(Mat == NULL){
        printf("Falha ao inserir valor, matriz invalida\n");
        return 0;
    }

    matriz* mat = (matriz*) Mat;

    if(linhaDestino > mat->qtdLinhas || linhaDestino < 1 || colunaDestino > mat->qtdColunas || colunaDestino < 1){
        printf("\nFalha na insercao do valor %d. A matriz possui apenas %d linhas e %d colunas!\n", valor, mat->qtdLinhas, mat->qtdColunas);
        return 0;
    }
    
    linha* ponteiroLinhaDestino = mat->linhas[linhaDestino-1];
    coluna* primeiraColuna = ponteiroLinhaDestino->colunas;

    // Insercao na linha vazia
    if(primeiraColuna == NULL){
        coluna* novaColuna = (coluna*) malloc(sizeof(coluna));
        novaColuna->valor = valor;
        novaColuna->idColuna = colunaDestino;
        novaColuna->proxCol = NULL;
        ponteiroLinhaDestino->colunas = novaColuna;
        ponteiroLinhaDestino->colunasOcupadas++;
        return 1;
    }

    else{
        coluna* colunaAtual = primeiraColuna;

        // Insercao no inicio
        if(colunaAtual->idColuna > colunaDestino){   
            coluna* novaColuna = (coluna*) malloc(sizeof(coluna));
            novaColuna->valor = valor;
            novaColuna->idColuna = colunaDestino;
            novaColuna->proxCol = colunaAtual;
            ponteiroLinhaDestino->colunas = novaColuna;
            ponteiroLinhaDestino->colunasOcupadas++;
            return 1;
        }

        while(colunaAtual != NULL){

            // Insercao no final
            if(colunaAtual->proxCol == NULL){
                coluna* novaColuna = (coluna*) malloc(sizeof(coluna));
                novaColuna->valor = valor;
                novaColuna->idColuna = colunaDestino;
                novaColuna->proxCol = NULL;
                colunaAtual->proxCol = novaColuna;
                ponteiroLinhaDestino->colunasOcupadas++;
                return 1;
            }

            // Insercao no meio
            if(colunaAtual->idColuna < colunaDestino && colunaAtual->proxCol->idColuna > colunaDestino){
                coluna* novaColuna = (coluna*) malloc(sizeof(coluna));
                novaColuna->valor = valor;
                novaColuna->idColuna = colunaDestino;
                novaColuna->proxCol = colunaAtual->proxCol;
                colunaAtual->proxCol = novaColuna;
                ponteiroLinhaDestino->colunasOcupadas++;
                return 1;
            }

            colunaAtual = colunaAtual->proxCol;
        }
    }
}


int removeNumber(Matriz Mat, int linhaID, int colunaID){

    if(Mat == NULL){
        printf("Falha ao remover valor, matriz invalida\n");
        return 0;
    }

    matriz* mat = (matriz*) Mat;
    
    if(linhaID > mat->qtdLinhas || linhaID < 1 || colunaID > mat->qtdColunas || colunaID < 1){
        printf("\nFalha na remocao. A matriz possui apenas %d linhas e %d colunas!\n", mat->qtdLinhas, mat->qtdColunas);
        return 0;
    }

    linha* linhaRemover = mat->linhas[linhaID-1];
    coluna* primeiraColuna = linhaRemover->colunas;
    
    coluna* colunaAtual = primeiraColuna;
    coluna* colunaAnterior = primeiraColuna;

    while(colunaAtual != NULL){
        
        if(colunaAtual->idColuna == colunaID){
            
            if(linhaRemover->colunasOcupadas == 1 || colunaID == 1)
                linhaRemover->colunas = colunaAtual->proxCol; 
            else
                colunaAnterior->proxCol = colunaAtual->proxCol;
            
            linhaRemover->colunasOcupadas--;
            free(colunaAtual);
            return 1;
        }

        colunaAnterior = colunaAtual;
        colunaAtual = colunaAtual->proxCol;
    }

    printf("Nao ha valores nessa coluna\n");
    return 0;
}


int getQuantidadeLinhas(Matriz Mat){

    if(Mat == NULL){
        printf("ErroGetLinhas: Matriz invalida\n");
        return ERROR_ID;
    }

    matriz* mat = (matriz*) Mat;
    return mat->qtdLinhas;
}


int getQuantidadeColunas(Matriz Mat){

    if(Mat == NULL){
        printf("Erro getColunas: Matriz invalida\n");
        return ERROR_ID;
    }

    matriz* mat = (matriz*) Mat;
    return mat->qtdColunas;
}


int getNumberInPosition(Matriz Mat, int linhaID, int colunaID){

    if(Mat == NULL){
        printf("Erro getNumberInPosition: Matriz invalida\n");
        return ERROR_ID;
    }

    matriz* mat = (matriz*) Mat;
    
    if(linhaID > mat->qtdLinhas || linhaID < 1 || colunaID > mat->qtdColunas || colunaID < 1){
        printf("\nFalha na remocao. A matriz possui apenas %d linhas e %d colunas!\n", mat->qtdLinhas, mat->qtdColunas);
        return ERROR_ID;
    }

    linha* linhaDestino = mat->linhas[linhaID-1];
    coluna* colunaAtual = linhaDestino->colunas;

    while(colunaAtual != NULL){

        if(colunaAtual->idColuna == colunaID)
            return colunaAtual->valor;

        colunaAtual = colunaAtual->proxCol;
    }

    printf("Nao ha valores nessa posicao\n");
    return ERROR_ID;
}


void printFormattedMatrix(Matriz Mat){

    if(Mat == NULL){
        printf("Erro print: Matriz invalida\n");
        return;
    }

    matriz* mat = (matriz*) Mat;

    printf("\n\n**** PRINT DA MATRIZ ****\n\n");

    for(int i = 0; i < mat->qtdLinhas; i++){
        
        linha* linhaAtual = mat->linhas[i];
        coluna* colunaAtual = linhaAtual->colunas;
        
        int contador = 1;

        while(contador <= mat->qtdColunas){
            
            if(colunaAtual != NULL){

                if(colunaAtual->idColuna == contador){
                    printf("%d ", colunaAtual->valor);
                    colunaAtual = colunaAtual->proxCol;
                }

                else{
                    printf("0 ");
                }
            }

            else{
                printf("0 ");
            }
            
            contador++;

            if(colunaAtual == NULL && contador == mat->qtdColunas){
                printf("0 ");
                break;
            }
        }

        printf("\n");
    }
}


void freeMatrix(Matriz Mat){
    
    if(Mat == NULL)
        return;

    matriz* mat = (matriz*) Mat;

    for (int i = 0; i < mat->qtdLinhas; i++){
        
        coluna* colunaAtual = mat->linhas[i]->colunas;
        coluna* prox;

        while(colunaAtual != NULL){
            prox = colunaAtual->proxCol; 
            free(colunaAtual);
            colunaAtual = prox;
        }

        free(mat->linhas[i]);
    }

    free(mat->linhas);
    free(mat);
}