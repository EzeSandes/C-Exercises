int contarOcurrencias1(const char *cad, const char *sub)
{
    int   cant = 0;
    char *pWhat;
    char *pWhere;

    if(!*sub)
        return 1;

    while(*cad)
    {
        pWhat = (char *)sub;
        pWhere = (char *)cad;
        while(A_MINUSC(*pWhere) == A_MINUSC(*pWhat) && *pWhat)
        {
            pWhere++;
            pWhat++;
        }

        if(!*pWhat)
            cant++;

        cad++;
    }
    return cant;
}
