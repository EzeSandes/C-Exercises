double pow_MIO(double base, double exponente)
{
    double resultado = 1;

    if(exponente == 0)
        return 1;

    if(base == 0)
        return 0;

    for(; exponente > 0; exponente--)
        resultado *= base;
  
    return resultado;
}
