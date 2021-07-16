#ifndef COLADIN_H_INCLUDED
#define COLADIN_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct sNodo
{
    void        *info;
    unsigned    tamInfo;
    struct sNodo    *sig;
}tNodo;

typedef struct
{
    tNodo   *pri,
            *ult;
}tCola;

/////////////////////////////

void CrearCola_din(tCola *c);
int ColaLlena_din(const tCola *c, unsigned cantBytes);
void VaciarCola_din(tCola *c);
int PonerEnCola_din(tCola *c, const void *d, unsigned cantBytes);
int SacarDeCola(tCola *c, void *d, unsigned tamBytes);
int ColaVacia_din(const tCola *c);

/////////////////////////////

#endif // COLADIN_H_INCLUDED
