/*
    Z           x       Y
multiplying         multiplier
*/
int productsBySum(int multiplying, int multiplier)
{
    int sum = 0;
    for(; multiplier > 0; multiplier--)
        sum += multiplying;

    return sum;
}
