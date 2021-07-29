long int factorial(int num)
{
    long int resultado = 1;
    for(; num > 1; num--)
        resultado *= num;

    return resultado;
}


//////////
// int combinatorial_M_over_N
int combinatoriaMsobreN(int m, int n)
{
    return m >= n && n >= 0 ?  factorial(m) / (factorial(n) * factorial(m - n)) : 0;
}
