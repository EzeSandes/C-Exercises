#include"ColaEstaticaGen.h"
#include <string.h>

#define MINIMO(x,y)     ( ( x ) < ( y )?    ( x ):( y ) )

/////////////////////////////////

void crearCola(tCola *p)
{
    p->pri = 0; // O TAM_COLA - nro
    p->ult = 0;
    p->tamDisp = TAM_COLA;
}

/////////////////////////////////

int colaVacia(const tCola *p)
{
    return p->tamDisp == TAM_COLA;
}

/////////////////////////////////

int colaLlena(const tCola *p, unsigned tamInfo)
{
    return p->tamDisp < tamInfo + sizeof(unsigned);
}

/////////////////////////////////

int ponerEnCola(tCola *p, const void *info, unsigned tamInfo)
{
    unsigned cantByIni, // cantBytesIni
             cantByFin;

    if(p->tamDisp < tamInfo + sizeof(unsigned))
        return ERROR;

    p->tamDisp -= tamInfo + sizeof(unsigned);

    // Se que hay lugar => debo colocar el unsigned en la cola
    /// PRIMERO PASO LA CANTBYTES DEL UNSIGNED
    /*Hago el TAM - ult => voy a ver cuantos bytes puedo colocar al final.
        Yo necesito el MIN entre esos para saber si coloco una parte o todo completo el unsigned.
        Si no entra todo, coloco la resta.
    */
    cantByIni = MINIMO(TAM_COLA - p->ult, sizeof(unsigned));
    //Si tiene valor => debo colocar al final de la cola
    if(cantByIni) /// SE PODRIA SACAR EL IF xq TAM - ULT siempre va a dar 1 minimo ya que ult llega 1 menos a Tam por ser un vector
        memcpy(p->cola + p->ult, &tamInfo, cantByIni); // Copie la primera parte de o todo, de nuestro unsigned
    // Debo calcular si tengo una segunda parte que copiar o no.

    cantByFin = sizeof(unsigned) - cantByIni; // Lo que quiero colocar - lo que ya ingreso

    if(cantByFin)
        memcpy(p->cola, ((char*)&tamInfo) + cantByIni, cantByFin); // Le suma los BYTES por eso debo castearlo a puntero char
    // Puntero a char lo converti, por eso ese lugar. Sin los (), castea el result de la suma

    p->ult = (p->ult + sizeof(unsigned)) % TAM_COLA; // El resto da entre 0 y (TAM -1)

    /// SEGUNDO PASO LA CANTBYTES DE LA INFORMACION

    cantByIni = MINIMO(TAM_COLA - p->ult, tamInfo);

    if(cantByIni)
        memcpy(p->cola + p->ult, info, cantByIni);

    cantByFin = tamInfo - cantByIni; // QUE DE 0, es la situacion ideal

    if(cantByFin)
        memcpy(p->cola, ((char*)info) + cantByIni, cantByFin);

    p->ult = (p->ult + tamInfo) % TAM_COLA;

    return TODO_OK;
}

/////////////////////////////////

int sacarDeCola(tCola *p, void *info, unsigned tamInfo)
{
    unsigned    tamDato, cantByIni, cantByFin, tamMin;

    if(p->tamDisp == TAM_COLA)
        return ERROR;

    if((cantByIni = MINIMO(sizeof(unsigned), TAM_COLA - p->ult)));
        memcpy(&tamDato, p->cola + p->pri, cantByIni);

    cantByFin = sizeof(unsigned) - cantByIni;
    if(cantByFin)
        memcpy(((char*)&tamDato) + cantByIni, p->cola + p->pri, cantByFin);

    p->pri = (p->pri + sizeof(unsigned)) % TAM_COLA;

    p->tamDisp += sizeof(unsigned) + tamDato;
    /// COPIA DE INFO

    tamMin = MINIMO(tamInfo, tamDato);

    cantByIni = MINIMO(tamMin, TAM_COLA - p->pri);
    if(cantByIni)
        memcpy(info, p->cola + p->pri, cantByIni);

    cantByFin = tamMin - cantByIni;
    if(cantByFin)
        memcpy(((char*)info) + cantByIni, p->cola, cantByFin);

    p->pri = (p->pri + tamDato) % TAM_COLA;

    return TODO_OK;
}

/////////////////////////////////

//int verPrimeroCola(const tCola *p, void *info, unsigned tamInfo)
//{
//	unsigned tamDato,
//			ini,
//			fin,
//			pos = p->pri; // xq No puedo modificar el primero ahora a diferencia de SACAR
//
//	if(p->tamDisp == TAM_COLA)
//	return ERROR;
//
//	if((ini = MINIMO(sizeof(unsigned), TAM_COLA - pos)))
//		memcpy(&tamDato, p->cola + pos, ini);
//
//	if((fin = sizeof(unsigned) - ini))
//		memcpy(((char*)&tamDato) + ini, p->cola, fin);
//
//	pos = (fin)? fin : pos + ini;
//	tamDato = MINIMO(tamDato, tamInfo);
//
//	if((ini = MINIMO(tamDato, tamInfo)));
//		memcpy(info, p->cola + pos, ini);
//
//	if((fin = tamDato - ini))
//		memcpy(((char*)info) + ini, p->cola, fin);
//
//	return TODO_OK;
//}

int verPrimeroCola(const tCola *p, void *info, unsigned tamInfo)
{
	unsigned cantByIni,
            cantByFin,
            posInicial = p->pri,
            tamDato;

    if(p->tamDisp == TAM_COLA) // Si Esta vacia
        return ERROR;

    if((cantByIni = MINIMO(sizeof(unsigned), TAM_COLA - posInicial)))
        memcpy(&tamDato, p->cola + posInicial, cantByIni);

    if((cantByFin = sizeof(unsigned) - cantByIni))
        memcpy(((char*)&tamDato)+ cantByIni, p->cola, cantByFin);

    posInicial = (posInicial + sizeof(unsigned)) % TAM_COLA; // Por si estaba partido, debo volverla abajo
    /// AHORA EL DATO

    tamDato = MINIMO(tamInfo, tamDato);
    if((cantByIni = MINIMO(tamDato, TAM_COLA - posInicial)))
        memcpy(info, p->cola + posInicial, cantByIni);

    if((cantByFin = tamDato - cantByIni))
        memcpy(((char*)info) + cantByIni, p->cola, cantByFin);

    return TODO_OK;
}
/////////////////////////////////

void vaciarCola(tCola *p)
{
    p->pri = 0;
    p->ult = 0;
    p->tamDisp = TAM_COLA;
}

/////////////////////////////////
