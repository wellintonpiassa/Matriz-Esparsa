#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(){

    Matrix matrix = createMatrix(3,3);

    //printMatrixPointers(matrix);

    insertNumber(matrix, 100, 0, 0);
    insertNumber(matrix, 150, 0, 1);
    insertNumber(matrix, 175, 0, 2);

    insertNumber(matrix, 200, 1, 0);
    //insertNumber(matrix, 250, 1, 1);
    insertNumber(matrix, 275, 1, 2);

    insertNumber(matrix, 300, 2, 0);
    insertNumber(matrix, 350, 2, 1);
    //insertNumber(matrix, 375, 2, 2);
    
    //printMatrixRowAndColumns(matrix);

    printf("\n\nQuantidade de linhas: %d\n\n", getQuantidadeLinhas(matrix));
    printf("\n\nQuantidade de colunas: %d\n\n", getQuantidadeColunas(matrix));
    printf("\n\nQuantidade de colunas ocupadas: %d\n\n", getQuantidadeColunasOcupadas(matrix));


    printFormattedMatrix(matrix);

    int number = 0;
    number = getNumberInPosition(matrix, 2, 2);

    printf("Numero na posicao [2][2] = %d\n\n", number);

    freeMatrix(matrix);

    return 0;
}