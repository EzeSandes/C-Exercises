#include <stdio.h>
#include <stdlib.h>

////////////////////////////////

typedef struct sNodo
{
    void            *info;
    unsigned        tamInfo;
    struct  sNodo   *sig;
}tNodo;

typedef tNodo*  tLista;

////////////////////////////////

void crearLista(tLista *p);
int listaVacia(const tLista *p)
int listaLlena(const tLista *p, unsigned tamInfo);
void vaciarLista(tLista *p);
int ponerAlPrincipioLista(tLista *p, const void *d, unsigned cantBytes);
int sacarPrimeroLista(tLista *p, void *d, unsigned tamInfo);
int verPrimeroLista(const tLista *p, void *d, unsigned tamInfo);
int ponerFinalLista(tLista *p, const void *d, unsigned cantBytes);


////////////////////////////////
