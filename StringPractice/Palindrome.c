#define ERROR       0
#define TODO_OK     1
////////////////////

int isItPalindrome_1(const char *str)
{
    char *ptrTemp = (char*)str;

    while(*ptrTemp)
        ptrTemp++;

    ptrTemp--;

    while(str < ptrTemp)
    {
        if(*str != *ptrTemp)
            return ERROR;

        str++;
        ptrTemp--;
    }


    return *str != '\0';
}


int es_palindromo_2(const char *str)
{
    const char *aux = str;

    while(*aux)
        aux++;

    aux--;
    while(*str == *aux && str < aux)
    {
        str++;
        aux--;
    }
    
    return *str == *aux;
    //return (*cad == *aux)? OK: ERROR;
}
