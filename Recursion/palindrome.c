/// PALINDROME

#define TO_LOWERCASE(x) ((x) >= 'A' && (x) <= 'Z'? ((x) + ('a' - 'A')) : (x))
#define IS_UPPERCASE(x) ( (x) >= 'A' && (x) <= 'Z')
#define IS_LOWERCASE(x) ( (x) >= 'a' && (x) <= 'z')

#define IS_LETTER(x) (IS_UPPERCASE(x) || IS_LOWERCASE(x))


/////////////////////////////////////////////// MAIN.c
   
//    char cadena[] = "neuquen";
char cadena[] = "aRRIBA LA bIrRA";

printf("%s", rPalindromo(cadena) ? "ES PALINDROMO" : "NO ES PALINDROMO");

////////////////////////////////////////////// palindrome.c

#include <string.h>

int rPalindromo(const char *cad)
{
    char *pEndCad = (char *)cad + strlen(cad) - 1;

    if(*cad == '\0')
        return 0;

    return riPalindromo(cad, pEndCad);
}

//////////////////////////////////

int riPalindromo(const char *start, const char *end)
{
    if(start >= end)
        return 1;

    if(!IS_LETTER(*start))
        return riPalindromo(start + 1, end);

    if(!IS_LETTER(*end))
        return riPalindromo(start, end - 1);

    if(TO_LOWERCASE(*start) == TO_LOWERCASE(*end))
        return riPalindromo(start + 1, end - 1);

    return 0;
}
