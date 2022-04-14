#define IS_LOWERCASE(x)     ((x) >= 'a' && (x) <= 'z')
#define IS_UPPERCASE(x)     ((x) >= 'A' && (x) <= 'Z')
#define IS_LETTER(x)         (IS_LOWERCASE(x) || IS_UPPERCASE(x))
#define IS_VOWEL(x)         ((x) == 'a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u' \
                             || (x) == 'A' || (x) == 'E' || (x) == 'I' || (x) == 'O' || (x) == 'U')

unsigned numberOfVowels(const char *str)
{
    unsigned sum = 0;
    while(*str)
    {
        if(IS_LETTER(*str) && IS_VOWEL(*str))
            sum++;

        str++;
    }

    return sum;
}
