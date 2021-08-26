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
/*************************/
