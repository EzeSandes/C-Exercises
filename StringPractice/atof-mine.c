#define IS_LOWERCASE(x)     ((x) >= 'a' && (x) <= 'z')
#define IS_UPPERCASE(x)     ((x) >= 'A' && (x) <= 'Z')
#define IS_LETER(x)         (IS_LOWERCASE(x) || IS_UPPERCASE(x))
#define IS_SPACE(x)       ((x) == ' ' || (x) == '\t')
#define IS_DIGIT(x)        ((x) >= '0' && (x) <= '9')
#define DIGIT_TO_NUMBER(x)         ((x) - '0')

double atof_mio(const char *numPtr)
{
    int sign = 1;
    double number = 0,
           multiply;

    while(IS_SPACE(*numPtr))
        numPtr++;

    if(IS_LETER(*numPtr) || (*numPtr != '-' && *numPtr != '+' && !IS_DIGIT(*numPtr) ) || !*numPtr)
        return 0; // or => return number;
  
    if(*numPtr == '-')
    {
        sign *= -1;
        numPtr++;
    }

    if(*numPtr == '+')
        numPtr++;

    while(IS_DIGIT(*numPtr))
    {
        number = number * 10 + DIGIT_TO_NUMBER(*numPtr);
        numPtr++;
    }

    if(*numPtr != '.')
        return number * sign;

    numPtr++;

    multiply = (double)1 / 10;
    while(IS_DIGIT(*numPtr))
    {
        number += DIGIT_TO_NUMBER(*numPtr) * multiply;
        multiply /= 10;

        numPtr++;
    }

    return number * sign;
}
