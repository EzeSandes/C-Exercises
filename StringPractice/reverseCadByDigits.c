/*
Example:
          ab3cdefg2hi => abedcfgih
*/

#define IS_DIGIT(x)        ((x) >= '0' && (x) <= '9')
#define DIGIT_TO_NUMBER(x)         ((x) - '0')

char* reverseCadByDigits(char *str)
{
    char    *pInit = str,
             *pReach,
             *pWriting;

    int reach,
        numDigitsFound = 0; // It is used to know how many less spaces the string will have. 

    ///////////
    // If there are no digits, it doesn't make sense all the code below => I check first if there is a digit
    while(!IS_DIGIT(*str) && *str)
        str++;

    if(!*str)
        return pInit;

    ///////////

    // Here => cad == Some Digit => I must go copying and moving the string.
    pWriting = str;
    while(*str)
    {
        reach = DIGIT_TO_NUMBER(*str);
        pReach = str;

        //I need this to know if the Digits is higher than the end of string
        while(*pReach && reach) // == while(*pReach && reach--) pReach++;
        {
            pReach++;
            reach--;
        }

        if(!*pReach)
            pReach--;

        intercambiarLetras(str + 1, pReach);
        str_cpy_mine(pWriting, str + 1, pReach);// where, since, until

        pWriting = pReach - numDigitsFound;
        str = pReach + 1;
        numDigitsFound++;

        while(!IS_DIGIT(*str) && *str)
        {
            *pWriting = *str;
            str++;
            pWriting++;
        }
    }

    *pWriting = '\0';

    return pInit;
}
