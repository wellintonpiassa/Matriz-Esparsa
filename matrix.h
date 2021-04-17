/* Interface da Matriz Dinâmica */

typedef void* Matrix;

Matrix createMatrix(int rowNumber, int colNumber);
void printMatrixPointers(Matrix Mat);
void insertNumber(Matrix Mat, int number, int rowPosition, int colPosition);
void removeNumber(Matrix Mat, int rowPosition, int colPosition);
void printMatrixRowAndColumns(Matrix Mat);
void freeMatrix(Matrix Mat);
void printFormattedMatrix(Matrix Mat);
int getQuantidadeLinhas(Matrix Mat);
int getQuantidadeColunas(Matrix Mat);
int getQuantidadeColunasOcupadas(Matrix Mat);
int getNumberInPosition(Matrix Mat, int rowPosition, int colPosition);