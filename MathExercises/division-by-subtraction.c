/*
Dados dos números naturales A y B, desarrollar una función para obtener el cociente entero A/B y el resto. (A puede ser 0; B, no).
*/

int cocienteEntero(int dividendo, int divisor)
{
    int i;

    if(divisor == 0)
        return -1; // No se puede dividir por cero

    if(dividendo < divisor)
        return 0;

    i = 1;
    while(divisor * i <= dividendo)
        i++;

    dividendo -= divisor * (i - 1);

    return i - 1;
}
