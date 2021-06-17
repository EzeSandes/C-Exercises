#include"ColaDin.h"
#include<string.h>

#define ERROR   0
#define TODO_OK 1
///////////////////////////

void CrearCola_din(tCola *c)
{
    c->pri = NULL;
    c->ult = NULL;
}

//////////////////////////

int ColaLlena_din(const tCola *c, unsigned cantBytes)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);

    free(info);
    free(aux);

    return info == NULL || aux == NULL;
}

//////////////////////////

void VaciarCola_din(tCola *c)
{
    while(c->pri)
    {
        tNodo *aux = c->pri;
        c->pri = aux->sig;
        free(aux->info);
        free(aux);
    }
    c->ult = NULL;
}

//////////////////////////

int PonerEnCola_din(tCola *c, const void *d, unsigned cantBytes)
{
    tNodo *nuevo = (tNodo *)malloc(sizeof(tNodo));
    nuevo->info = malloc(cantBytes);

    if(!nuevo || !info)
        return ERROR;

    memcpy(nuevo->info, d, cantBytes);
    nuevo->tamInfo = cantBytes;

    nuevo->sig = NULL;

    if(c->ult)
        c->ult->sig = nuevo;
    else
        c->pri = nuevo;

    c->ult = nuevo;

    return TODO_OK;
}

//////////////////////////

int SacarDeCola(tCola *c, void *d, unsigned tamBytes)
{
    tNodo *aux;
    if(!c->pri)
        return ERROR;

    aux = c->pri;
    c->pri = aux->sig;

    memcpy(d,aux->info, ((tamBytes < aux->tamInfo)?  tamBytes : aux->tamInfo));

    free(aux->info);
    free(aux);

    if(!c->pri)// Porque si es el ultimo nodo que saque, sera NULL
        c->ult = NULL;
    return  TODO_OK;
}

//////////////////////////

int ColaVacia_din(const tCola *c)
{
    return c->pri == NULL;
}

///////////////////////////

int verPrimeroCola(const tCola *c, void *d, unsigned cantBytes)
{
	if(c->pri == NULL)
		return ERROR;
		
	memcpy(d, p->pri->info, ((cantBytes < c->pri->tamInfo)?  cantBytes : c->pri->tamInfo));
	return TODO_OK;
}
