#include<string.h>

#define     ERROR   0
#define     TODO_OK 1

#define     MIN(x,y)    ((x) > (y)?     (y)   :   (x))

///////////////////////////////

void crearLista(tLista *p)
{
    *p = NULL;
}

///////////////////////////////

int listaVacia(const tLista *p)
{
    return *p == NULL;
}

///////////////////////////////

int listaLlena(const tLista *p, unsigned tamInfo)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    void *info = malloc(tamInfo);

    free(info);
    free(aux);

    return aux == NULL || info == NULL;
}

//////////////////////////////////

void vaciarLista(tLista *p)
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

//////////////////////////////////

int ponerAlPrincipioLista(tLista *p, const void *d, unsigned cantBytes)
{
    tNodo *nuevo = (tNodo*) malloc(sizeof(tNodo));
    nuevo->info = malloc(tamBytes);

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

///////////////////////////////////

int sacarPrimeroLista(tLista *p, void *d, unsigned tamInfo)
{
    tNodo *aux = *p;

    if(!*p)
        return ERROR;

    *p = aux->sig;

    memcpy(d, aux->info, MIN(tamInfo, aux->tamInfo));
    free(aux->info);
    free(aux);

    return TODO_OK;
}

////////////////////////////////////

int verPrimeroLista(const tLista *p, void *d, unsigned tamInfo)
{
    if(!*p)
        return ERROR;

    memcpy(d, (*p)->info, MIN(tamInfo, (*p)->tamInfo));
    return TODO_OK;
}

////////////////////////////////////

int ponerFinalLista(tLista *p, const void *d, unsigned cantBytes)
{
    tNodo *aux;
    tNodo *nuevo = (tNodo*) malloc(sizeof(tNodo))
    nuevo->info = malloc(cantBytes);

    if(!nuevo || !nuevo->info)
        {
            free(nuevo);
            return ERROR;
        }

    while(aux->sig)
        aux = aux->sig;

    memcpy(nuevo->info, d, cantBytes));
    nuevo->tamInfo = cantBytes;

    nuevo->sig = aux->sig;//o lo igualo directamente: = NULL
    aux->sig = nuevo;

    return TODO_OK;
}

///////////////////////////////////

int verFinalLista(const tLista *p, void *d, unsigned cantBytes)
{
    tNodo *aux = *p;

    if(!*p)
        return ERROR;

    while(aux->sig)
        aux = aux->sig;

    memcpy(d, aux->info, MIN(cantBytes, aux->tamInfo));
    return TODO_OK;
}

///////////////////////////////////

int sacarUltimoLista(tLista *p, void *d, unsigned cantBytes)
{
    tNodo *aux = *p;

    if(*p == NULL)
        return ERROR;

    while(aux->sig)
        aux = aux->sig;


}

///////////////////////////////////
