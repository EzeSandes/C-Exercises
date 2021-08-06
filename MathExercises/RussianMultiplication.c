int multiplicacionRusa(int multiplicand, int multiplicator)
{
    int sum = 0;

    if(!multiplicand || !multiplicator)
        return 0;

    while(multiplicand >= 1)
    {
        if(multiplicand % 2 != 0)
            sum += multiplicator;

        multiplicand /= 2;
        multiplicator *= 2;
    }
    return sum;
}
