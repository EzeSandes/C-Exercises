///  EXERCISE 1

/*
  Given a number, return the Fibonacci number in that position.
  
  Eg: number = 6 => rFibonacciOf(6) == 8
*/

// SOLUTION
/*
*
*
*
*
*
*
*
*/


int rFibonacciOf(int elemN)
{
    if(elemN == 0 || elemN == 1)
        return elemN;

    return rFibonacciOf(elemN - 1) + rFibonacciOf(elemN - 2);
}


/// EXERCISE 2

/*
  Given a number, return the Fibonacci numbers until that position.
  
  Eg: number = 6 => rFibonacciUntil(6) == 0 1 1 2 3 5 8
*/

// SOLUTION
/*
*
*
*
*
*
*
*
*/
void rFibonacciUntil(int elemN)
{
    int i;

    for(i = 0; i < elemN; i++)
    {
        printf(" %d ", rFibonacciUntil(i));
    }
}

/// EXERCISE 3

/*
  Return the Fibonacci numbers of a position given without re-calculating all the previous fibonacci numbers at execution time.
  
  Eg: 
  
  Loop 0
    number = 6 => fc(6) == 8
  
  Loop: 1
    number = 7 => fc(7) == 13
    
  Loop: 2
    number = 6 => fc(6) == 8 (without re-calculating because it was calculated in loop 0)
    
  HELP: Maybe you need to pass more that one argument(the numer given) to the function.
*/

// SOLUTION
/*
*
*
*
*
*
*
*
*
*
*
*
*/
int rFibonacciMemo(int n, int *vecMemo)
{
    if(n == 0 || n == 1)
        return n;
    else if(*(vecMemo + n) != -1) // -1 == Value not generated
        return *(vecMemo + n);
    else
    {
        *(vecMemo + n) = rFibonacciMemo(n - 1, vecMemo) + rFibonacciMemo(n - 2, vecMemo);
        return *(vecMemo + n);
    }
}

/////// main

 int vec[21],
        *pVec = vec;
    int i;
    for(i = 0; i < sizeof(vec) / sizeof(vec[0]); i++, pVec++)
        *pVec = -1;

    int num;

    printf("\nNum: ");
    scanf("%d", &num);

    while(num != -1)
    {
        printf("\nFibonacci of %d: %d", num, rFibonacciMemo(num, vec));
        printf("\n\n");

        printf("\nNum: ");
        scanf("%d", &num);
    };

    printf("\n\n");
    return 0;
