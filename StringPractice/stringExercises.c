#define ERROR       0
#define TODO_OK     1
////////////////////

//isItAnagram()
int esAnagrama(const char *cad)
{
    char *ptrTemp = (char*)cad;

    while(*ptrTemp)
        ptrTemp++;

    ptrTemp--;

    while(cad < ptrTemp)
    {
        if(*cad != *ptrTemp)
            return ERROR;

        cad++;
        ptrTemp--;
    }


    return *cad != '\0';
}

//isItPalindrome()
int es_palindromo(const char *cad)
{
    const char *aux = cad;

    while(*aux)
        aux++;

    aux--; // Vuelvo una posicion atras al caracter nulo
    while(*cad == *aux && cad < aux)
    {
        cad++;
        aux--;
    }
    //Saldra del aux si no son iguales los caracteres o los punteros son iguales
    return *cad == *aux;
    //return (*cad == *aux)? OK: ERROR;
}
