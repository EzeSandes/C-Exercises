#include <stdio.h>
#include <stdlib.h>

#define COL_CHARS 50

#define IS_LOWERCASE(x)     ((x) >= 'a' && (x) <= 'z')
#define IS_UPPERCASE(x)     ((x) >= 'A' && (x) <= 'Z')
#define IS_LETER(x)         (IS_LOWERCASE(x) || IS_UPPERCASE(x))
#define IS_SPACE(x)       ((x) == ' ' || (x) == '\t')
#define IS_DIGIT(x)        ((x) >= '0' && (x) <= '9')
#define DIGIT_TO_NUMBER(x)         ((x) - '0')

void testerAtoi(char tests[][COL_CHARS], int rows);
int atoi_mine(const char *numPtr);

////////////////////////////////////////////////// MAIN

int main(){
  
  	char tests[][COL_CHARS] = {
                            "    123  565 l",
                            "    -123L",
                            "    LABV123",
                            "    LABV-123",
                            "    LABV+123",
                            "    123ABC",
                            "    123 ABC",
                            "    ABC",
                            "    ",
                            "    ?//123",
                            "    ?//+123",
                            "    ?//-123",
                            "-1234",
                            "+1234",
                            "",
                            "    +12345",
                            "    -12345",
                            "    12345",
                            "    12345   ABC",
                            "    -12345   ABC",
                            "    +12345   ABC",
                            "    +1234567890",
                            "    -1234567890",
                            "    +12345678900", // OVERFLOW in both functions (original atoi and mine)
                            "    -12345678900", // OVERFLOW in both functions (original atoi and mine)
                        };
  
	testerAtoi(tests, sizeof(tests) / COL_CHARS);
      
	return 0;
}

//////////////////////////////////////////////////

int atoi_mine(const char *numPtr)
{
    int sign = 1,
        number = 0;

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

    return number * sign;
}

void testerAtoi(char tests[][COL_CHARS], int rows)
{
    int i;

    for(i = 0; i < rows; i++)
    {
        printf("Atoi <stdlib.h> ( %s ): %d", tests[i], atoi(tests[i]));
        printf("\nAtoi <MINE> ( %s ): %d", tests[i], atoi_mio(tests[i]));

        printf("\n\n");
    }
}
