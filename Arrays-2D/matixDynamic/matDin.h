#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////

void** createMatrix(size_t rows,
                  size_t cols, size_t sizeElements);

void freeMatrix(void *mat, size_t numberOfRows);

//////////////////////////////////

void showMatrix(void **mat, int rows, int cols,
                   void (*show)(void *, int, int));
void showMatrix_int(int **mat, int rows, int cols);
void loadMatrix_int(int **mat, int rows, int cols);

//////////////////////////////////

void showArray_int(void *vec, int actualRow, int actualCol);

void loadMatrix(void **mat, int rows, int cols,
                    void (*load)(void *, int, int));

void loadArray_int(int *arr, int actualRow, int numberOfElemts);

//////////////////////////////////
