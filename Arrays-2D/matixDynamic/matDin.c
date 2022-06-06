#include "matDin.h"
#include <string.h>

#define SPACES    5

void freeMatrixByError(void *pStartOfRows, void *pActualPosRows);

//////////////////////////////////////////////////////
// sizeElements == sizeof(int), sizeof(float), sizeof(char) ...
// I cannot pass "**mat" as an argument since we don't know where the memory will be reserved for the row ptr.
void** createMatrix(size_t rows,
                  size_t cols, size_t sizeElements)
{
    int     i;
    void    *pRows,
            *pStartOfRows,
            *pAux;

    pRows = malloc(rows * sizeof(void *));
    if(!pRows)
        return NULL;

    pStartOfRows = pRows;

    for(i = 0; i < rows; i++)
    {
        pAux = malloc(cols * sizeElements);

        if(!pAux)
        {
            freeMatrixByError(pStartOfRows, pRows);
            free(pStartOfRows);
            return NULL;
        }

        memcpy(pRows, &pAux, sizeof(void *));
        pRows += sizeof(void *);
    }

    return pStartOfRows;
}

///////////////////////////////////////

void freeMatrixByError(void *pStartOfRows, void *pActualPosRows)
{
    void    *pAux;
    while(pStartOfRows != pActualPosRows)
    {
        pActualPosRows -= sizeof(void *);
        memcpy(&pAux, pActualPosRows, sizeof(void *));
        free(pAux);
    }
}

///////////////////////////////////////

void freeMatrix(void *mat, size_t numberOfRows)
{
    int     i;
    void    *pRows = mat,
            *pAux;

    for(i = 0; i < numberOfRows; i++)
    {
        memcpy(&pAux, pRows, sizeof(void *));
        free(pAux);
        pRows += sizeof(void *);
    }

    free(mat);
}

///////////////////////////////////////

void showMatrix_int(int **mat, int rows, int cols)
{
    int i,
        j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            printf("%*d ", SPACES, mat[i][j]);

        printf("\n");
    }
}

///////////////////////////////////////

void showMatrix(void **mat, int rows, int cols,
                   void (*show)(void *, int, int))
{
    int i,
        j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            show(mat[i], i, j);

        printf("\n");
    }
}

//////////////

void showArray_int(void *vec, int actualRow, int actualCol)
{
    printf("%*d ", SPACES, ((int *)vec)[actualCol]);
}

///////////////////////////////////////

void loadMatrix_int(int **mat, int rows, int cols)
{
    int i,
        j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            mat[i][j] = j + (i * 10);
    }
}

///////////////////////////////////////

void loadMatrix(void **mat, int rows, int cols,
                    void (*load)(void *, int, int))
{
    int i,
        j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            load(mat[i], i, cols);
    }
}

void loadArray_int(int *arr, int actualRow, int numberOfElemts)
{
    int i;

    for(i = 0; i < numberOfElemts; i++, arr++)
        *arr = i + (actualRow * 10);
}
