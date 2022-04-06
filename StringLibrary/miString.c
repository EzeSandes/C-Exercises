#include "miString.h"

/////////////////

int str_len(const char *cad)
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

char* str_cat(char *donde, const char *que)
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

char* str_ncat(char *donde, const char *que, size_t n)
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

char* str_chr(const char *donde, int que)
{
//    char *ptrAux = NULL;

    while(*donde != que && *donde)
        donde++;

    return *donde == que ?   (char *)donde : NULL;
}

// Opcion_2
char* str_chr(const char *cad, int c)
{
    while(*cad)
    {
        if(*cad == c)
            return (char*)cad;

        cad++;
    }

    return *cad == '\0' ? (char*)cad : NULL;
}


/////////////////////////
char* str_rchr(char *donde, int que)
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

int str_cmp(const char *donde, const char *que)
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

char* str_cpy(char *donde, const char *que)
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

char* str_ncpy(char *donde, const char *que, size_t n)
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

size_t str_cspn(const char *donde, const char *que)
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
char* str_str(const char *donde, const char *que)
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

char* str_pbrk(const char *donde, const char *que)
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

////////////////////////////

void* mem_cpy(void *dest, const void *origen, size_t cantBytes)
{
    void *aux = dest;

    for(; cantBytes > 0; cantBytes--)
    {
        *(char *)dest = *(char *)origen;
        (char *)dest++;
        (char *)origen++;
    }

    return aux;
}

////////////////////////////

void* mem_move(void *donde, const void *que, size_t n)
{
    int     i;
    char    *d = (char *)donde;

    char    *auxBuffer;
    char    *buffer = (char *)malloc(sizeof(char) * n);
    if(!buffer)
        return NULL;

    auxBuffer = buffer;

    for(i = 0; i < n; i++)
    {
        *buffer = *(char *)que;
        (char *)que++;
        buffer++;
    }

    for(i = 0; i < n; i++)
    {
        *d = *auxBuffer;
        auxBuffer++;
        d++;
    }

    free(buffer);
    return donde;
}
