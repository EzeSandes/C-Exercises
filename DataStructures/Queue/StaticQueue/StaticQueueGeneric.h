#ifndef COLAESTATICAGEN_H_INCLUDED
#define COLAESTATICAGEN_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>


#define ERROR   0
#define TODO_OK 1

#define TAM_COLA    100
//////////////////////////////

typedef struct
{
    char        cola[TAM_COLA]; // size
    unsigned    pri,
                ult,
                tamDisp;
}tCola;

void crearCola(tCola *p);
int colaVacia(const tCola *p);
int colaLlena(const tCola *p, unsigned tamInfo);
int ponerEnCola(tCola *p, const void *info, unsigned tamInfo);
int sacarDeCola(tCola *p, void *info, unsigned tamInfo);
int verPrimeroCola(const tCola *p, void *info, unsigned tamInfo);
void vaciarCola(tCola *p);

//////////////////////////////

#endif // COLAESTATICAGEN_H_INCLUDED
