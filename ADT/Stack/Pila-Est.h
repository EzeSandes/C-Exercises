#ifndef PILA-EST_H_INCLUDED
#define PILA-EST_H_INCLUDED

#define TAM_PILA    200

typedef struct{
    char        pila[TAM_PILA];
    unsigned    tope;
}tPila;


void crearPilaEst(tPila *p);
int pilaLLenaEST(const tPila *p, unsigned cantBytes);
int ponerEnPilaEST(tPila *p, const void *d, unsigned cantBytes);

#endif // PILA-EST_H_INCLUDED
