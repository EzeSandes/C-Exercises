#include <stdio.h>
#include <stdlib.h>
#include "matDin.h"

#define ROW_MAIN    5
#define COL_MAIN    5


int main()
{
    void **mat;

    mat = createMatrix(ROW_MAIN, COL_MAIN, sizeof(int));
    loadMatrix(mat, ROW_MAIN, COL_MAIN, loadArray_int);
    showMatrix(mat, ROW_MAIN, COL_MAIN, showArray_int);
    freeMatrix(mat, ROW_MAIN);

    /////////////////////////////////////////////////////
    printf("\n\n");
    return 0;
}
