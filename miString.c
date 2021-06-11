#include "miString.h"

/////////////////

int miStrlen(const char *cad)
{
    unsigned int contador = 0;

    while(*cad)
    {
        cad++;
        contador++;
    }

    return contador;
}

/*
int str_len(const char *cad)
{
    const char *ptrTemp = cad; //Como lo haria Lopez

    while(*cad)
        cad++;

    return (int)(cad - ptrTemp); // Para que haga la cuenta en INT no con punteros segun Lopez.
}

int str_lenRecursiva(const char *cad)
{
    if(*cad)
        return str_lenRecursiva(cad + 1) + 1;
    return 0;
}
*/

/////////////////

char* miStrcat(char *donde, const char *que)
{
    char *ptrTemp = donde;

    while(*donde)
        donde++;

    while(*que)
    {
        *donde = *que;
        donde++;
        que++;
    }

    *donde = '\0';

    return ptrTemp;
}

/////////////////////////

char* miStrncat(char *donde, const char *que, size_t n)
{
    char *ptrTemp = donde;

    while(*donde)
        donde++;

    while(*que && n)
    {
        *donde = *que;
        n--;
        donde++;
        que++;
    }

    *donde = '\0';

    return ptrTemp;
}

/////////////////////////

char* miStrchr(const char *donde, int que)
{
//    char *ptrAux = NULL;

    while(*donde != que && *donde)
        donde++;

    return *donde == que ?   (char *)donde : NULL;
}

/////////////////////////
char* miStrrchr(char *donde, int que)
{
    char *ptrTemp = NULL;
    while(*donde)
    {
        if(*donde == que)
            ptrTemp = donde;

        donde++;
    }

    return ptrTemp;
}

/////////////////////////

int miStrcmp(const char *donde, const char *que)
{
    while(*donde && *donde == *que)
    {
        donde++;
        que++;
    }

    //No importa el numero devuelto, solo si es +, -, 0
    return *(unsigned char*)donde - *(unsigned char*)que;
}

/////////////////////////

char* miStrcpy(char *donde, const char *que)
{
    char *ptrTemp = donde;

    while(*que)
    {
        *donde = *que;
        donde++;
        que++;
    }

    *donde = '\0';

    return ptrTemp;
}


////////////////////////////////

char* miStrncpy(char *donde, const char *que, size_t n)
{
    char *ptrTemp = donde;

    while(*que && n)
    {
        *donde = *que;
        n--;
        donde++;
        que++;
    }

    *donde = '\0';

    return ptrTemp;
}

////////////////////////////////

size_t miStrcspn(const char *donde, const char *que)
{
    size_t contador = 0;
    char *ptrQue;

    while(*donde)
    {
        ptrQue = (char*)que;
        while(*ptrQue && *ptrQue != *donde)
            ptrQue++;

        if(!*ptrQue)
            contador++;
        else
            return contador;

        donde++;
    }
    return contador;
}

//////////////////////////////
char* miStrstr(const char *donde, const char *que)
{
    char *d;
    char *q;

    while(*donde)
    {
        d = (char *)donde;
        q = (char *)que;

        while(*q == *d && *q && *d)
        {
            d++;
            q++;
        }

        if(!*q)
            return (char*)donde;

        donde++;
    }

    return NULL;
}

////////////////////////////

char* miStrpbrk(const char *donde, const char *que)
{
    char *ptrQue;

    while(*donde)
    {
        ptrQue = (char*)que;

        while(*donde != *ptrQue && *ptrQue)
            ptrQue++;

        if(*ptrQue)
            return (char*)donde;

        donde++;
    }
    return NULL;
}
