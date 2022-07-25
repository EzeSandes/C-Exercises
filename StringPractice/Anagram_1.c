#include <stdio.h>
#include <stdlib.h>

#define NUM_CHAR_ALLOWED  26
#define CHAR_TO_INDEX(x)     (int)((x) - 'a')

int areTheyAnagrams(const char *cad1, const char *cad2);

int main()
{
    printf("%d", areTheyAnagrams("roma", "amor"));

    return 0;
}


//////////////////////////////

int areTheyAnagrams(const char *cad1, const char *cad2)
{
    int i;
    int charsAllowed1[NUM_CHAR_ALLOWED] = {0};
    int charsAllowed2[NUM_CHAR_ALLOWED] = {0};

    int *pCharsAllowed1 = charsAllowed1;
    int *pCharsAllowed2 = charsAllowed2;

    while(*cad1 && *cad2)
    {
        (*(charsAllowed1 + CHAR_TO_INDEX(*cad1)))++;
        (*(charsAllowed2 + CHAR_TO_INDEX(*cad2)))++;

        cad1++;
        cad2++;
    }

    if(*cad1 || *cad2)
        return 0;

    for(i = 0; i < NUM_CHAR_ALLOWED; i++)
    {
        if(*pCharsAllowed1 != *pCharsAllowed2)
            return 0;

        pCharsAllowed1++;
        pCharsAllowed2++;
    }

    return 1;
}

//////////////////////////////
