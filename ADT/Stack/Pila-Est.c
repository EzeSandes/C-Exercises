#include"Pila-Est.h"
#include<string.h>

#define ERROR   0
#define TODO_OK 1

#define MIN(x,y)    ((x) < (y)?     (x) : (y))

///////////////////

void crearPilaEST(tPila *p)
{
    p->tope = TAM_PILA;
}

///////

int pilaLLenaEST(const tPila *p, unsigned cantBytes)
{
    return p->tope < cantBytes + sizeof(unsigned);
}

int pilaVaciaEST(const tPila *p)
{
    return p->tope == TAM_PILA;
}

///////

int ponerEnPilaEST(tPila *p, const void *d, unsigned cantBytes)
{
    if(p->tope < cantBytes + sizeof(unsigned))
        return ERROR;

    p->tope -= cantBytes;
    memcpy(p->pila + p->tope, d, cantBytes);

    p->tope -= sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));

    return TODO_OK;
}

///////

int verTopePilaEST(const tPila *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo;

    if(p->tope == TAM_PILA)
        return ERROR;

    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    memcpy(d, p->pila + p->tope + sizeof(unsigned), MIN(tamInfo, cantBytes));

    return TODO_OK;
}

///////

void vaciarPilaEST(tPila *p)
{
    p->tope = TAM_PILA;
}

///////

int sacarDePilaEST(tPila *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo;

    if(p->tope == TAM_PILA)
        return ERROR;

    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    p->tope += sizeof(unsigned);

    memcpy(d, p->pila + p->tope, MIN(tamInfo, cantBytes));
    p->tope += tamInfo

    return TODO_OK;
}
