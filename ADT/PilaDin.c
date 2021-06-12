#include"PilaDin.h"
#include<string.h>
#include<stdlib.h>

#define ERROR       0
#define TODO_OK     1

#define MIN(x, y)   ((x) < (y)?    (x) : (y))

////////////////

void crearPilaDIN(tPila *p)
{
    *p = NULL;
}

////////////////

int pilaLlenaDIN(const tPila *p, unsigned cantBytes)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

////////////////

int ponerEnPilaDIN(tPila *p, const void *d, unsigned cantBytes)
{
    tNodo *nuevo = (tNodo *)malloc(sizeof(tNodo));
    nuevo->info = malloc(cantBytes);

    if(!nuevo || !nuevo->info)
    {
        free(nuevo);
        return ERROR;
    }

    nuevo->tamInfo = cantBytes;

    memcpy(nuevo->info, d, cantBytes);

    nuevo->sig = *p;
    *p = nuevo;

    return TODO_OK;
}

/////////////////////////////

int verTope (const tPila *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
        return ERROR;

    //Por precedencia de operadores se debe colocar el () ya que p-> info == (*p)->info
    memcpy(d, (*p)->info, MIN(cantBytes, (*p)->tamInfo));
    return TODO_OK;

    //En realidad creo que pasa porque coloca **p->info porque en realidad p es doble ptr
    //=> quera desreferenciar al puntero generico

    //CREO QUE NO. AL DEBUGEAR ES LO MISMO P->INFO Y (*P)->INFO
    //Hacerlo en papel. Acordarse que el p->info es un PTR VOID pero lo que quiero
    //es ir a lo que apunta ese puntero, desreferenciar lo que tiene dentro.
    // => (*p)->info == (*(*p)).info (Lo que contiene INFO)

    // Si p->info se guarda en la posic 100 pero lo que contiene es la pos 30. Necesito ese num
    // p->info == 100
}

int pilaVaciaDIN(const tPila *p)
{
    return *p == NULL;
}

////////////////////

void vaciarPilaDIN(tPila *p)
{
    tNodo *aux;

    while(*p)
    {
        aux = *p;
        *p = aux->sig;
        free(aux->info);
        free(aux);
    }
}

////////////////////

int sacarDePilaDIN(tPila *p, void *d, unsigned cantBytes)
{
    tNodo *aux = *p;

    if(*p == NULL)
        return ERROR;

    *p = aux->sig;

    memcpy(d, aux->info, MIN(cantBytes, aux->tamInfo));
    free(aux->info);
    free(aux);

    return TODO_OK;
}

/////////////////////

