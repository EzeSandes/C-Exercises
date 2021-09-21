#include<string.h>
#include<stdlib.h>
#include "CircularStack.h"

#define ERROR       0
#define ALL_OK     1

#define MIN(x, y)   ((x) < (y)?    (x) : (y))


//////////////////

void createCircularStack(tPila *p)
{
    *p = NULL;
}

//////////////////

int isFull(const tPila *p, unsigned cantBytes)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    void *info = malloc(cantBytes);

    free(aux);
    free(info);

    return aux == NULL || info == NULL;
}

//////////////////

int push(tPila *p, const void *d, unsigned cantBytes)
{
    tNodo *newNode = (tNodo *)malloc(sizeof(tNodo));

    if(!newNode || !(newNode->info = malloc(cantBytes)))
    {
        free(newNode);
        return ERROR;
    }

    newNode->tamInfo = cantBytes;
    memcpy(newNode->info, d, cantBytes);

    if(*p)
    {
        newNode->sig = (*p)->sig;
        (*p)->sig = newNode;
    }else
    {
        newNode->sig = newNode;
        *p = newNode;
    }

    return ALL_OK;
}

//////////////////

int viewTop(const tPila *p, void *d, unsigned cantBytes)
{
    if(*p == NULL)
        return ERROR;

    memcpy(d, (*p)->sig->info, MIN(cantBytes, (*p)->sig->tamInfo));

    return ALL_OK;
}

//////////////////

int isEmpty(const tPila *p)
{
    return *p == NULL;
}

//////////////////

void emptyCircularStack(tPila *p)
{
    if(!(*p))
        return;

    tNodo *aux;

    do{
        aux = (*p)->sig;
        (*p)->sig = aux->sig;
        free(aux->info);
        free(aux);

    } while(*p != aux);

    *p = NULL;
}

//////////////////
int pop(tPila *p, void *d, unsigned cantBytes)
{
    if(!(*p))
        return ERROR;

    tNodo *aux = (*p)->sig;

    if(aux == *p) // It's the last
        *p = NULL;
    else
        (*p)->sig = aux->sig;

    memcpy(d, aux->info, MIN(aux->tamInfo, cantBytes));

    free(aux->info);
    free(aux);

    return ALL_OK;
}
