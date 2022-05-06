#include "miString.h"

#define ES_MINUSCULA(x)     ((x) >= 'a' && (x) <= 'z')
#define ES_MAYUSCULA(x)     ((x) >= 'A' && (x) <= 'Z')
#define ES_LETRA(x)         (ES_MINUSCULA(x) || ES_MAYUSCULA(x))

#define A_MINUSC(x)    ((x) >= 'a' && (x) <= 'z' ? (x) : ((x) + ('a' - 'A')))
#define A_MAYUSC(x)    ((x) >= 'A' && (x) <= 'Z' ? (x) : ((x) - ('a' - 'A')))

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
    char *pInicio = donde;

    while(*que && n)
    {
        *donde = *que;
        que++;
        donde++;
        n--;
    }

    if(!n)
        *donde = '\0';

    while(n && *donde)
    {
        *donde = '\0';
        donde++;
        n--;
    }

    return pInicio;
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

/* Opcion_2: Menos eficiente pero funciona igualmente.

char* strpbrk_mio(const char *donde, const char *que)
{
    char *pAux = (char *)donde,
            *pDonde;

    while(*pAux)
        pAux++;

    while(*que)
    {
        pDonde = (char *)donde;

        while(*que != *pDonde && *pDonde)
            pDonde++;

        // Ingresa => Significa que encontro uno igual.
        if(*pDonde && (int)(pDonde - pAux) < 0)
            pAux = pDonde;

        que++;
    }

    return *pAux ? pAux : NULL;
}

*/
////////////////////////////

char* str_lwr(char *cad)
{
    char *pInicio = cad;

    while(*cad)
    {
        if(ES_LETRA(*cad))
            *cad = A_MINUSC(*cad);

        cad++;
    }

    return pInicio;
}

//////////////////////////////

char* str_upr(char *cad)
{
    char *pInicio = cad;

    while(*cad)
    {
        if(ES_LETRA(*cad))
            *cad = A_MAYUSC(*cad);

        cad++;
    }

    return pInicio;
}

////////////////////////////

char* str_cpy_mine(char *where, const char *since, const char *until)
{
    char *pInit = where;

    while(since <= until)
    {
        *where = *since;
        where++;
        since++;
    }

    return pInit;
}

////////////////////////////

void mem_cpy(void *destino, const void *origen, size_t cantBytes)
{
    int i;
    destino = (char *)destino + (cantBytes - 1);
    origen = (char *)origen + (cantBytes - 1);

    for(i = 0; i < cantBytes; i++)
    {
        *(char *)destino = *(char *)origen;

        (char *)destino--;
        (char *)origen--;
    }
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
