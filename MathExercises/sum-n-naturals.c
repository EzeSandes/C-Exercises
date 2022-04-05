/*
Construir un programa que lea un número natural N y calcule la suma de los primeros N números naturales.
*/

int sumaNumerosNaturales(int num)
{
    int suma = 0;
    for(; num > 0; num--)
        suma += num;

    return suma;
}
