/**//*  *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/


/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
#include <string.h>
#include <stdlib.h>
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/

#define NRO_CUENTA_CORRIENTE    "002"


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarMovim_MIO(const void *d, FILE *fp)
{
    const tMovi   *mov = (const tMovi*)d;

    fprintf(fp, "%-16s %9.2lf\n", mov->ctaCte, mov->saldo);
}

int compararMovim_MIO(const void *d1, const void *d2)
{
    tMovi   *mov1 = (tMovi *)d1;
    tMovi   *mov2 = (tMovi *)d2;

    return strcmp(mov1->ctaCte, mov2->ctaCte);
}

int esCtaCte002_MIO(const void *d)
{
    tMovi   *mov = (tMovi *)d;
    char    *pAux = strrchr(mov->ctaCte, '-');

    return strcmp(pAux + 1, NRO_CUENTA_CORRIENTE) == 0;
}


int acumularMoviSaldo_MIO(void **dest, unsigned *tamDest,
                      const void *ori, unsigned tamOri)
{
    tMovi   *acumulador = (tMovi*)*dest;
    tMovi   *movi = (tMovi *)ori;

    acumulador->saldo += movi->saldo;

    return 1;
}


void mostrarTotal_MIO(const void *d, FILE *fp)
{
    tMovi   *acum = (tMovi *)d;

    fprintf(fp, "Total cliente: %9.2lf\n\n", acum->saldo);
}

/**//* para el TDA LISTA                                                  *//**/

int mostrarLista_MIO(const tLista *p,
                     void (*mostrar)(const void *, FILE *), FILE *fp)
{
    int     cantNodos = 0;

    if(!*p)
        return 0;

    fprintf(fp,"Nro Cuenta Banc   Importe\n");
    while(*p)
    {
        mostrar((*p)->info, fp);
        p = &(*p)->sig;
        cantNodos++;
    }

    return cantNodos;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    tLista  *lectura,
            *minimo;

    tNodo   *aux;

    int huboIntercambio;

    while(*p)
    {
        huboIntercambio = 0;
        minimo = p;
        lectura = &(*p)->sig;
        while(*lectura)
        {
            // podria cambiar en el comparacion para hacerlo como los genericos SIEMPRE < 0 tienen dentro
            if(comparar((*lectura)->info, (*minimo)->info) < 0) // ASCENDENTE => >0 || Cambio el orden(Lo que hice aca)
                minimo = lectura;

            lectura = &(*lectura)->sig;
        }

        if(*minimo != *p)
        {
            huboIntercambio = 1;
            aux = *minimo;
            *minimo = aux->sig;

            aux->sig = *p; // 1) Hago que el nodo desprendido apunte al primero de la lista
            *p = aux; // 2) Tiene sentido en la segunda insercion. Hago que el "SIG" del anterior apunte al insertado nuevo
            p = &aux->sig; // 3) Hago que la lista ahora sea desde el insertado SIG => *p sera el mismo nodo primero de antes ya que en 1) apuntaba a ese
        }

        if(!huboIntercambio)
            p = &(*p)->sig;
    }
}


int eliminarMostrarYMostrarSubTot_MIO(tLista *p, FILE *fpPant,
                                      int comparar(const void *, const void *), //compararMovim
                                      int comparar2(const void *d),//esCtaCte002
                                      int acumular(void **, unsigned *,//acumularMoviSaldo
                                                   const void *, unsigned),
                                      void mostrar(const void *, FILE *),//mostrarMovim
                                      void mostrar2(const void *, FILE *))//mostrarTotal
{
    int cantEliminada = 0;
    tLista  *p2;
    tMovi   acumulador;

    while(*p)
    {
        if(comparar2((*p)->info))
        {
            cantEliminada++;

            fprintf(fpPant, "Nro Cuenta Banc   Importe\n");
            mostrar((*p)->info, fpPant);

            p = &(*p)->sig;
            acumular(&(*p)->info, &(*p)->tamInfo, (*p)->info, (*p)->tamInfo);
            while(*p && comparar((*p)->info, (*p2)->info))
            {
                if(comparar2((*p2)->info))
                {
                    //
                }
            }
        }


//        p2 = &(*p)->sig;
//
//        if(*p2 && comparar((*p)->info, (*p2)->info) == 0)
//        {
//            //
//        }else if(comparar2((*p)->info)) //Aun asi si es "002" lo debo eliminar
//        {
//            //
//        }else
//            p = &(*p)->sig;
    }
}


int  vaciarListaYMostrar_MIO(tLista *p,
                             void (*mostrar)(const void *, FILE *), FILE *fp)
{
    tNodo   *eliminar;
    int     cantEliminada = 0;

    if(!*p)
        return 0;

    while(*p)
    {
        eliminar = *p;

        mostrar(eliminar->info, fp);
        *p = eliminar->sig;

        free(eliminar->info);
        free(eliminar);

        cantEliminada++;
    }
    return cantEliminada;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
