#define TRUE  1
#define FALSE 0

int perteneceAFibonacci(unsigned num)
{
    long int    auxTermAnt,
                terminoAnt = 1,
                termSig = 1;

    while(termSig <= num)
    {
        if(termSig == num)
            return TRUE;

        auxTermAnt = terminoAnt;
        terminoAnt = termSig;
        termSig += auxTermAnt;
    }

    return FALSE;
}
