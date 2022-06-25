/*
    - Given an array of elements, check if their elements are all "true"(Condition of "true" given by the developer).
*/

/*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*/

int fcFalse_int(const void *d);

/////////////////////////////////////////////// MAIN.C

int vec[] = {1,1,1,0,1,1,1,1};

int cod = rIsTautology(vec, sizeof(int), sizeof(vec) / sizeof(vec[0]), fcFalse_int);

printf("\n%s", cod ? "Is Tautology\n" : "Is not Tautology\n");

//////////
// fcFalse_int: Returns true if the element of the array has the condition of false that I considered like false(in this case, "0")
int fcFalse_int(const void *d)
{
    return *(int *)d == 0;
}
//////////

/////////////////////////////////////////////// tautology.c

int rIsTautology(const void *vec, unsigned sizeElem, int numberOfElem, int (*fcFalse)(const void *dVec))
{
    if(numberOfElem == 0)
        return 1; // Xq si llega al final sin detectar el "falso" => retorna verdadero

    if(fcFalse(vec))
        return 0;

    return rIsTautology((char *)vec + sizeElem, sizeElem, numberOfElem - 1);
}

