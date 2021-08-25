#define COL     50
#define ROWS     50

#define SPACES    5

void fillMatrix(int mat[][COL], int row, int col)
{
    int i,
        j;
  
    for(i = 0; i < row; i++)
        for(j = 0; j < col; j++)
            mat[i][j] = (i * 10) + j;
}

/*************************/
void showMatrix(int mat[][COL], int row, int col)
{
    int i,
        j;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
            printf("%*.2d", SPACES, mat[i][j]);

        printf("\n");
    }
}

/*************************/
/*************************/
/*
FORM:

      *
        *
          *
            *
              *
*/
void showPrimaryDiagonal(int mat[][COL], int row, int col)
{
    int i;
    int min = row < col?   row : col;

    for(i = 0; i < min; i++)
        printf("%*.02d\n", SPACES * (i + 1), mat[i][i]);
}

/*************************/
/*
FORM:
                    *
                *
            *
        *

*/
void showSecondaryDiagonal(int mat[][COL], int row, int col)
{
    int i;
    int min = col < row?   col : row;

    for(i = 0; i < min; i++, --col)
        printf("%*.02d\n", SPACES * col, mat[i][col - 1]);
}

/*************************/
/*
FORM:
        *
        **
        ***
        ****
        *****

*/
void displayLowerTriangleLEFT(int mat[][COL], int row, int col)
{
    int i,
        j,
        min = row < col?   row : col;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j <= i && j < min; j++)
            printf("%*.02d", SPACES, mat[i][j]);

        printf("\n");
    }
}

/*************************/

/*
FORM:
        *********
        *******
        *****
        ***
        *
*/
void displayUpperTriangleLEFT(int mat[][COL], int row, int col)
{
    int i,
        j,
        min = row < col?   row : col;

    for(i = 0; i < min; i++, col--)
    {
        for(j = 0; j < col; j++)
            printf("%*.02d", SPACES, mat[i][j]);

        printf("\n");
    }
}

/*************************/

/*
FORM:
        *********
          *******
            *****
              ***
                *
*/
void displayUpperTriangleRIGHT(int mat[][COL], int row, int col)
{
    int i,
        j,
        min = row < col?   row : col;

    for(i = 0; i < min; i++)
    {
        printf("%*s", SPACES * i, "");
        for(j = i; j < col; j++)
            printf("%*.02d", SPACES, mat[i][j]);

        printf("\n");
    }
}

/*************************/

/*
FORM:
        *********
         *******
          *****
           ***
            *
*/
void displayUpperTriangle(int mat[][COL], int row, int col)
{
    int i,
        j;

    for(i = 0; i <= col / 2; i++)
    {
        printf("%*s", SPACES * i, "");
        for(j = i; j < col - i; j++)
            printf("%*.02d", SPACES, mat[i][j]);

        printf("\n");
    }
}

/*************************/

/*
FORM:
            *
           ***
          *****
         *******
        *********
*/
void displayLowerTriangle(int mat[][COL], int row, int col)
{
    int i, j, cont = row - 1;

    for(i = 0; i < row; i++, cont--)
    {
        printf("%*s", SPACES * cont, "");

        for(j = cont; j < col - cont; j++)
            printf("%*d", SPACES, mat[i][j]);

        printf("\n");
    }
}

/*************************/

// BUG: Only works with square matrixs.
/*
  FORM:
                *
               **
              ***
            *****
              ***
               **
                *
*/
void mostrarTriangCentroDER(int mat[][COL], int fila, int col)
{
    int i,
        j;

    for(i = 0; i < fila / 2; i++)
    {
        printf("%*s", ESPACIOS * ((col - 1) - i), "");
        for(j = col - 1 - i; j < col; j++)
            printf("%*.02d", ESPACIOS, mat[i][j]);

        printf("\n");
    }

    for(; i < fila; i++)
    {
        printf("%*s", ESPACIOS * i, "");
        for(j = i; j < col; j++)
            printf("%*.02d", ESPACIOS, mat[i][j]);

        printf("\n");
    }
}

/*************************/
/*************************/
