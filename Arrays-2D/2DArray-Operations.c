#define SPACES  5

#define ROWS        5
#define COL         5

#define FALSE   0
#define TRUE    1

/*************************/

int sumAboveMainDiagonal(int mat[][COL], int rows, int col)
{
    int  sum = 0,
         i,
         j;

    for(i = 0; i < rows; i++)
        for(j = i + 1; j < col; j++)
            sum += mat[i][j];

    return sum;
}
/*************************/

int isDiagonalMatrix(int mat[][COL], int rows, int col)
{
    int i, j;

    for(i = 0; i < rows; i++)
    {
        for(j = i + 1; j < col; j++)
            if(mat[i][j] || mat[j][i])
                return FALSE;
    }

    return TRUE;
}

/*************************/

int isIdentityMatrix(int mat[][COL], int rows, int col)
{
    int i,
        j;

    if(rows != col)
        return FALSE;

    for(i = 0; i < rows; i++)
    {
        if(mat[i][i] != 1)
            return FALSE;

        for(j = i + 1; j < col; j++)
        {
            if(mat[i][j] || mat[j][i])
                return FALSE;
        }
    }

    return TRUE;
}

/*************************/
/*************************/

int isSymmetricMatrix(int mat[][COL], int rows, int col)
{
    int i,
        j;

    for(i = 0; i < rows; i++)
    {
        for(j = i + 1; j < col; j++)
            if(mat[i][j] != mat[j][i])
                return FALSE;
    }

    return TRUE;
}

/*************************/
/*************************/

// In-place matrix transposition
int inSituMatrixTransposition(int mat[][COL], int rows, int col)
{
    int i,
        j,
        aux;

    if(rows != col)
        return FALSE;

    for(i = 0; i < rows; i++)
    {
        for(j = i + 1; j < col; j++)
        {
            aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
    return TRUE;
}

/*************************/

int productOfMatrix(int mat1[][COL], int mat2[][COL], int matResult[][COL],
                      int rowsMat1, int columnsMat1, int rowsMat2, int columnsMat2)
{
    int i, 
        j, 
        k;

    if(columnsMat1 != rowsMat2)
        return FALSE;

    for(k = 0; k < columnsMat2; k++)
    {
        for(i = 0; i < rowsMat1; i++)
        {
            matResult[i][k] = 0;
            for(j = 0; j < rowsMat2; j++)
                matResult[i][k] += (mat1[i][j] * mat2[j][k]);
        }
    }

    return TRUE;
}

/*************************/
