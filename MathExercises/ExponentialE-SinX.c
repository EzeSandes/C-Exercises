// tol = tolerance
double exponentialE(int num, float tol)
{
    double result = 1;
    double resTerm = 0;
    int count = 1;

    do{
        result += resTerm;
        resTerm = pow(num, count) / factorial(count);
        count++;
    }while(resTerm > tol);

    return result;
}

//////////////
// tol = tolerance
double sinX(int num, float tol)
{
    int sign = -1;
    int count = 3;
    double resTerm = 0;
    double resTotal = num;
    
    do{
        resTotal += resTerm;
        resTerm = (double)pow(num, count) / (factorialLong(count));
        resTerm *= sign;
        sign *= -1;
        count += 2;
    }while(fabs(resTerm) > tol);

    return resTotal;
}
