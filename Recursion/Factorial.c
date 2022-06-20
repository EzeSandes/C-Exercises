unsigned rFactorial(unsigned n)
{
    if(n == 0)
        return 1;

    return n * rFactorial(n - 1);
}
