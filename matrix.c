#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"

typedef struct Column column;

struct Column{
    int data;
    int position;
    column *proxCol;
};

typedef struct {
    int linha;
    column* colunas;
}row;

typedef struct {
    int linhas;
    int colunas;
    int colunasOcupadas;
    row** primeiraLinha;
}matrix;


Matrix createMatrix(int rowNumber, int colNumber){

    matrix* mat = (matrix*) malloc(sizeof(matrix));

    mat->linhas = rowNumber;
    mat->colunas = colNumber;
    mat->colunasOcupadas = 0;
    
    mat->primeiraLinha = (row**) malloc(rowNumber * sizeof(row*));

    for(int i=0; i < rowNumber; i++){
        mat->primeiraLinha[i] = (row*) malloc(sizeof(row));
        mat->primeiraLinha[i]->colunas = NULL;
        mat->primeiraLinha[i]->linha = i+1;
    }

    return mat;
}




void insertNumber(Matrix Mat, int number, int rowPosition, int colPosition){
    if(Mat == NULL){
        printf("Matriz invalida\n");
        return;
    }

    matrix* mat = (matrix*) Mat;

    if(rowPosition > mat->linhas-1){
        printf("Linha nao existente na matriz, a quantidade maxima de linhas sao: %d\n", mat->linhas);
        return;
    }

    if(colPosition > mat->colunas-1){
        printf("Coluna nao existente na matriz, a quantidade maxima de colunas sao: %d\n", mat->colunas);
        return;
    }
 
    row* linha = mat->primeiraLinha[rowPosition];
    column* firstColumn = mat->primeiraLinha[rowPosition]->colunas;

    // Inserindo na lista vazia
    if(firstColumn == NULL){
        printf("A lista dessa linha esta vazia, portanto, inserindo a primeira coluna\n");

        linha->colunas = (column*) malloc(sizeof(column));
        linha->colunas->data = number;
        linha->colunas->position =colPosition;
        linha->colunas->proxCol = NULL;

        mat->colunasOcupadas++;
        printf("%d %d\n", mat->colunasOcupadas, linha->colunas->data);
        getchar();
    }

    else{

        column* currentColumn = firstColumn;

        while(currentColumn != NULL){

            if(currentColumn->proxCol == NULL || currentColumn->proxCol->position > colPosition){
                
                column* newColumn = (column*) malloc(sizeof(column));

                newColumn->data = number;
                newColumn->position = colPosition;
                newColumn->proxCol = currentColumn->proxCol;

                currentColumn->proxCol = newColumn;

                mat->colunasOcupadas++;
                printf("%d %d\n", mat->colunasOcupadas, newColumn->data);
                getchar();

                return;
            }

            currentColumn = currentColumn->proxCol;

        }
    }
}


void removeNumber(Matrix Mat, int rowPosition, int colPosition){

    if(Mat == NULL){
        printf("Matriz invalida\n");
        return;
    }

    matrix* mat = (matrix*) Mat;
    
    if(rowPosition > mat->linhas-1){
        printf("Linha nao existente na matriz, a quantidade maxima de linhas sao: %d\n", mat->linhas);
        return;
    }

    if(colPosition > mat->colunas-1){
        printf("Coluna nao existente na matriz, a quantidade maxima de colunas sao: %d\n", mat->colunas);
        return;
    }

    row* linha = mat->primeiraLinha[rowPosition];
    column* firstColumn = linha->colunas;
    
    column* currentColumn = firstColumn;

    while(currentColumn != NULL){

        if(currentColumn->proxCol->position == colPosition){
            
            currentColumn->proxCol = currentColumn->proxCol->proxCol;
            free(currentColumn->proxCol);
            mat->colunasOcupadas--;
            return;

        }

        currentColumn = currentColumn->proxCol;
    }

    printf("Nao ha valores nessa coluna\n");

}

int getQuantidadeColunas(Matrix Mat){

    if(Mat == NULL){
        printf("Matriz invalida\n");
        return -1;
    }

    matrix* mat = (matrix*) Mat;

    return mat->colunas;

}

int getQuantidadeColunasOcupadas(Matrix Mat){

    if(Mat == NULL){
        printf("Matriz invalida\n");
        return -1;
    }

    matrix* mat = (matrix*) Mat;

    return mat->colunasOcupadas;

}

int getQuantidadeLinhas(Matrix Mat){

    if(Mat == NULL){
        printf("Matriz invalida\n");
        return -1;
    }

    matrix* mat = (matrix*) Mat;

    return mat->linhas;

}


int getNumberInPosition(Matrix Mat, int rowPosition, int colPosition){

    if(Mat == NULL){
        printf("Matriz invalida\n");
        return -1;
    }

    matrix* mat = (matrix*) Mat;
    
    if(rowPosition > mat->linhas-1){
        printf("Linha nao existente na matriz, a quantidade maxima de linhas sao: %d\n", mat->linhas);
        return -1;
    }

    if(colPosition > mat->colunas-1){
        printf("Coluna nao existente na matriz, a quantidade maxima de colunas sao: %d\n", mat->colunas);
        return -1;
    }

    row* linha = mat->primeiraLinha[rowPosition];
    column* firstColumn = linha->colunas;

    column* currentColumn = firstColumn;

    while(currentColumn != NULL){

        if(currentColumn->position == colPosition)
            return currentColumn->data;

        currentColumn = currentColumn->proxCol;
    }

    printf("Nao ha valores nessa posicao\n");
    return -1;
}

void printFormattedMatrix(Matrix Mat){

    if(Mat == NULL){
        printf("Matriz invalida\n");
        return;
    }

    matrix* mat = (matrix*) Mat;

    printf("**** PRINT DA MATRIZ ****\n\n");

    for (int i = 0; i < mat->linhas; i++){
        
        column* currentColumn = mat->primeiraLinha[i]->colunas;
        int count = 0;

        while(count < mat->colunas){
            
            if(currentColumn != NULL){

                if(currentColumn->position == count){
                    printf("%d ", currentColumn->data);
                    currentColumn = currentColumn->proxCol;

                }

                else{
                    printf("0 ");
                }
            }

            else{
                printf("0 ");
            }
            
            count++;

            if(currentColumn == NULL && count == mat->colunas-1){
                printf("0 ");
                break;
            }
        }

        printf("\n");
    }
}


void printMatrixPointers(Matrix Mat){

    if(Mat == NULL){
        printf("Matriz invalida\n");
        return;
    }

    matrix* mat = (matrix*) Mat;

    for (int i = 0; i < mat->linhas; i++){
        printf("Linha: %d\n", mat->primeiraLinha[i]->linha);
        printf("Coluna: %p\n",mat->primeiraLinha[i]->colunas);
    }
}

void printMatrixRowAndColumns(Matrix Mat){
    if(Mat == NULL){
        printf("Matriz invalida\n");
        return;
    }

    matrix* mat = (matrix*) Mat;

    for (int i = 0; i < mat->linhas; i++){
        
        column* currentColumn = mat->primeiraLinha[i]->colunas;
        
        printf("Linha %d:\n", i);
        
        if(currentColumn == NULL)
            printf("Nao ha colunas nessa linha\n\n");

        else{
            while(currentColumn != NULL){
                
                printf("coluna %d: \nDados: %d\nProx: %p\n\n", currentColumn->position, currentColumn->data, currentColumn->proxCol);
                currentColumn = currentColumn->proxCol;
            }
        }
    }
}


void freeMatrix(Matrix Mat){
    
    if(Mat == NULL){
        printf("Matriz invalida\n");
        return;
    }

    matrix* mat = (matrix*) Mat;

    for (int i = 0; i < mat->linhas; i++){
        
        column* currentColumn = mat->primeiraLinha[i]->colunas;

        column* prox;

        while(currentColumn != NULL){
            prox = currentColumn->proxCol; 
            free(currentColumn);
            currentColumn = prox;
        }

        free(mat->primeiraLinha[i]);
    }

    free(mat->primeiraLinha);
    free(mat);
}