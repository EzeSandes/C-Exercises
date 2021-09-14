int isPrimeNumber(int num)
{
    int i;
    int cantLoops = num / 2;
  
    for(i = 2; i <= cantLoops; i++)
    {
        if(num % i == 0)
            return 0;
    }
    return 1;
}

///////////////

int intOfFloat(float num3)
{
    return num3;
}
