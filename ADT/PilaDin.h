#ifndef PILADIN_H_INCLUDED
#define PILADIN_H_INCLUDED


typedef struct sNodo{
    void        *info;
    unsigned    tamInfo;
    struct  sNodo   *sig;
}tNodo;

typedef tNodo*  tPila;

///////////////////////

void crearPilaDIN(tPila *p);
int pilaLlenaDIN(const tPila *p, unsigned cantBytes);
int ponerEnPilaDIN(tPila *p, const void *d, unsigned cantBytes);
int verTope (const tPila *p, void *d, unsigned cantBytes);
int pilaVaciaDIN(const tPila *p);
void vaciarPilaDIN(tPila *p);
int sacarDePilaDIN(tPila *p, void *d, unsigned cantBytes);

///////////////////////

#endif // PILADIN_H_INCLUDED
