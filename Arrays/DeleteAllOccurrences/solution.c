int removeAllOcurrences_int(int *vec, int data, int *numOfElem)
{
    int     *pEnd = vec + *numOfElem,
             *pRead,
             *pWrite;

    int     numItemsDeleted = 0;

    while(vec < pEnd)
    {
        while(*vec != data && vec < pEnd)
            vec++;

        if(vec == pEnd)
            return numItemsDeleted; // It passed the allowed range y it did not find it => return zero

        (*numOfElem)--;
        pRead = vec + 1; // if found it  => point to the next one.
        pWrite = vec;

        while(pRead < pEnd)
        {
            if(*pRead == data)
            {
                (*numOfElem)--;
                numItemsDeleted++;
            }
            else
            {
                *pWrite = *pRead;
                pWrite++;
            }

            pRead++;
        }

        vec = pRead;
    }

    return numItemsDeleted;
}
