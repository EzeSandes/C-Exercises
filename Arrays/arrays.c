#define ESPACIOS    5

#define TODO_OK     1
#define ERROR       0

////////////////

void mostrarArray(int *arr, int cant)
{
    for(; cant > 0; cant--)
    {
        printf("%*d", ESPACIOS, *arr);
        arr++;
    }
}

////////////////

/*
Desarrollar una función que inserte un elemento en un arreglo de enteros, dada
la posición de inserción.
*/
void mostrarArrayIndex(int *arr, int cant)
{
    int i;
    for(i = 0; i < cant; i++)
    {
        printf("%d: %d %*c", i, *arr, ESPACIOS, ' ');
        arr++;
    }
}

///////////////

int insertarArrayINT(int *arr, int elem, int index, int cant)
{

//El indice no puede ser < 0 ni tampoco mayor a la cant de elementos actuales del array
    cant -= 1;
    if(index < 0 || index > cant)
        return ERROR;

//    index -= 1;
    arr += cant; //Me muevo al ultimo

    //Debe ser el ultimo repetido del array ya que no me puedo pasar de la cantidad que tengo
    while(cant != index)
    {
        *arr = *(arr - 1);
        arr--;
        cant--;
    }

    *arr = elem;

    return TODO_OK;
}

// Otra version al que si le insertamos en el ultimo lugar y el array no tiene suficiente espacio, ese ultimo
// elemento, lo pierdo.
int insertarEnVector_INT(int *vec, int dato, int pos, int *cantElem, int tam)
{
    int *pVec;

    // Si no hay lugar, continua pero el ultimo valor lo perdere.
    if(pos <= 0 || pos > *cantElem + 1)
        return ERROR;

    if(pos == tam && pos == *cantElem)
    {
        vec += pos - 1;
        *vec = dato;
        return TODO_OK;
    }

    pVec = vec + *cantElem;
    while(vec + pos - 1 < pVec)
    {
        *pVec = *(pVec - 1);
        pVec--;
    }

    *pVec = dato;
    (*cantElem)++;

    return TODO_OK;
}
/////////////////

void ordenarArrayINT(int *arr, int cantElem)
{
    int i, j;
    int *min_idx;
    int *ptrArr;

    for(i = 0; i < cantElem - 1; i++)
    {
        ptrArr = arr;
        min_idx = ptrArr;
        for(j = i + 1; j < cantElem; j++)
        {
            ptrArr++;

            if(*ptrArr < *min_idx)
                min_idx = ptrArr;

        }

        intercambio(min_idx, arr);
        arr++;
    }
}

////////////////////

void intercambio(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

////////////////////
/*
int* buscoMinINT(int *arr, int cantElem)
{
    int i;
    int *min = *arr;

    for(i = 1; i < cantElem; i++)
    {
        arr++;
        if(*arr < *min)
            min = arr;

    }

    return min;
}
*/

//////////////////////////

/*
Desarrollar una función que inserte un elemento en un arreglo de enteros, ordenado
en forma ascendente, de forma de no alterar el orden.
*/
void insertarEnArrayOrdenadoINT(int *arr, int elem, int cantElem)
{
    //Para usar la funcion del ejercicio anterior, debo declarar auxiliares de los mismos.
    int index = 0;
    int *ptrArr = arr;
    int cantElemTemp = cantElem;

    //cantElemTemp para que no inserte por fuera del array.
    while(*ptrArr < elem && cantElemTemp)
    {
        index++;
        ptrArr++;
        cantElemTemp--;
    }

    //Si cantElem == 0 => el elemento a insertar va por fuera del array, su ultimo elemento es < que
    // el elemento pasado => no lo inserta.
    if(cantElemTemp)
        insertarArrayINT(arr, elem, index, cantElem);
}

////////////////////////
/*
Desarrollar una función que elimine el elemento que ocupa una determinada posición
de un arreglo de enteros.
*/
int eliminarXindexINT(int *arr, int index, int *cantElem)
{
    int cantElemTemp = *cantElem - index - 1;

    if(index < 0 || index >= *cantElem)
        return ERROR;

    arr += index;
    while(cantElemTemp)
    {
        *arr = *(arr + 1);
        arr++;
        cantElemTemp--;
    }

    (*cantElem)--;

    return TODO_OK;
}

////////////////////////

/*
Desarrollar una función que elimine la primera aparición de un elemento determinado
de un arreglo de enteros.
*/
int eliminarPrimAparicionINT(int *arr, int elem, int *cantElem)
{
    int index = 0;
    int cantElemTemp = *cantElem;
    int *ptrArr = arr;

    while(elem != *ptrArr && cantElemTemp)
    {
        ptrArr++;
        index++;
        cantElemTemp--;
    }

    return cantElemTemp?    eliminarXindexINT(arr, index, cantElem) : ERROR;
}

////////////////////

/*
Desarrollar una función que elimine todas las apariciones de un determinado elemento
de un arreglo de enteros.
*/

//1ra Opcion: Ineficiente ya que estoy asignando en todo momento sin importar si el elemento se encuentra en el array o no.
//            Si es de 10 elementos a la performance no afecta pero si cuento con miles o incluso millones, no seria correcto.

int eliminarTodaAparicionINT(int *arr, int elem, int *cantElem)
{
    int *ptrEscritura = arr;
    int cantElemTemp = *cantElem;

    if(cantElemTemp <= 0)
        return ERROR;

    while(cantElemTemp)
    {
        if(*arr == elem)
        {
            arr++;
            (*cantElem)--;
        }else{
            arr++;
            ptrEscritura++;
        }

        *ptrEscritura = *arr;
        cantElemTemp--;
    }

    return TODO_OK;
}

// Segunda Opcion mas optima en mi opinion. Solo empiezo a mover elementos cuando se que se encuentra el dato que deseo eliminar
int eliminarTodasAparicionesDeVector_int_2(int *vec, int dato, int *cantElem)
{
    int     *pFin = vec + *cantElem,
             *pLectura,
             *pEscritura;

    while(vec < pFin)
    {
        while(*vec != dato && vec < pFin)
            vec++;

        if(vec == pFin)
            return ERROR; // Significa que se paso de rango permitido y no lo encontro

        (*cantElem)--;
        pLectura = vec + 1; // Si encontro  => apunto al siguiente.
        pEscritura = vec;

        while(pLectura < pFin)
        {
            if(*pLectura == dato)
            {
                (*cantElem)--;
            }
            else
            {
                *pEscritura = *pLectura;
                pEscritura++;
            }

            pLectura++;
        }

        vec = pLectura;
    }

    return TODO_OK;
}



