/*
A natural number is "perfect", "deficient" or "abundant" depending on whether the sum of its positive divisors less than it is equals to, less than or greater than it.
For example

NUMBER  Number-Positive-divisors-less-than-it  Sum-of-Divisors  CLASIFICATION
6           1, 2, 3                                   6            PERFECT
10          1, 2, 5                                   8            DEFICIENT
12          1, 2, 3, 4, 6                             16           ABUNDANT

Develop
*/

int calculateClasificationPDA(int num)
{
    int i, sum = 0;
    for(i = 1; i <= num / 2; i++)
    {
        if((num % i) == 0)
            sum += i;
    }
    return sum;
}

////

void clasificationPDA(int num)
{
    int value;

    if(num < 0)
    {
        printf("\nNum it's not a positive number");
        return;
    }

    value = calcularClasificacionPDA(num);
    num -= value;

    if(num == 0)
        printf("PERFECT");
    else
    (num > 0)? printf("DEFICIENT"): printf("ABUNDANT");
}


