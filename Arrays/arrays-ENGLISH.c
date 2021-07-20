#define SPACES      5

#define ALL_OK      1   
#define ERROR       0 

////////////////

void showArray(int *arr, int numOfElem)
{
    for(; numOfElem > 0; numOfElem--)
    {
        printf("%*d", SPACES, *arr);
        arr++;
    }
}

////////////////

/*
Develop a function that inserts an element into an array of integers, given the insertion position.
*/
void showArrayIndex(int *arr, int numOfElem)
{
    int i;
    for(i = 0; i < numOfElem; i++)
    {
        printf("%d: %d %*c", i, *arr, SPACES, ' ');
        arr++;
    }
}

///////////////

int insertArrayINT(int *arr, int elem, int index, int numOfElem)
{

// The index cannot be lower to 0 or higher than the number of elements in the array.
    numOfElem -= 1;
    if(index < 0 || index > numOfElem)
        return ERROR;

//    index -= 1;
    arr += numOfElem; //I move last.
  
    while(numOfElem != index)
    {
        *arr = *(arr - 1);
        arr--;
        numOfElem--;
    }

    *arr = elem;

    return ALL_OK;
}

/////////////////

void sortArrayINT(int *arr, int numOfElem)
{
    int i, j;
    int *min_idx;
    int *ptrArr;

    for(i = 0; i < numOfElem - 1; i++)
    {
        ptrArr = arr;
        min_idx = ptrArr;
        for(j = i + 1; j < numOfElem; j++)
        {
            ptrArr++;

            if(*ptrArr < *min_idx)
                min_idx = ptrArr;

        }

        swap(min_idx, arr);
        arr++;
    }
}

////////////////////

void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

////////////////////
/*
int* lookingForMinimumINT(int *arr, int numOfElem)
{
    int i;
    int *min = *arr;
    for(i = 1; i < numOfElem; i++)
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
Develop a function that inserts an element in an integer array, sorted in ascending form without altering the order.
*/
void insertInArraySortedINT(int *arr, int elem, int numOfElem)
{
    //To use the function from the previous exercise, I have to declare auxiliaries of the variables.
    int index = 0;
    int *ptrArr = arr;
    int numOfElemTemp = numOfElem;

    //numOfElemTemp to prevent inserts from outside of the array.
    while(*ptrArr < elem && numOfElemTemp)
    {
        index++;
        ptrArr++;
        numOfElemTemp--;
    }

    //If numOfElem is equal to zero, then the element to insert goes outside the array. Its last element is < than the element passed, then It doesn't insert.
    if(numOfElemTemp)
        insertarArrayINT(arr, elem, index, numOfElem);
}

////////////////////////
/*
Develop a function that deletes an element that occupies a certain position from an integer array
*/
int removeXindexINT(int *arr, int index, int *numOfElem)
{
    int numOfElemTemp = *numOfElem - index - 1;

    if(index < 0 || index >= *numOfElem)
        return ERROR;

    arr += index;
    while(numOfElemTemp)
    {
        *arr = *(arr + 1);
        arr++;
        numOfElemTemp--;
    }

    (*numOfElem)--;

    return ALL_OK;
}

////////////////////////

/*
Develop a function that deletes the first appear of a certain element from an integer array
*/
int removeFirstAppearINT(int *arr, int elem, int *nomOfElem)
{
    int index = 0;
    int nomOfElemTemp = *nomOfElem;
    int *ptrArr = arr;

    while(elem != *ptrArr && nomOfElemTemp)
    {
        ptrArr++;
        index++;
        nomOfElemTemp--;
    }

    return nomOfElemTemp?    eliminarXindexINT(arr, index, nomOfElem) : ERROR;
}

////////////////////

/*
Develop a function that deletes all occurrences of a particular element from an array of integers. 
*/
int removeEveryOcurrenceINT(int *arr, int elem, int *numOfElem)
{
    int *ptrWrite = arr;
    int numOfElemTemp = *numOfElem;

    if(numOfElemTemp <= 0)
        return ERROR;

    while(numOfElemTemp)
    {
        if(*arr == elem)
        {
            arr++;
            (*numOfElem)--;
        }else{
            arr++;
            ptrWrite++;
        }

        *ptrWrite = *arr;
        numOfElemTemp--;
    }

    return TODO_OK;
}
