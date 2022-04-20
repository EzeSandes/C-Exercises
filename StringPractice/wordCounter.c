#define ERROR      0 
#define TODO_OK    1

#define IS_LOWERCASE(x)     ((x) >= 'a' && (x) <= 'z')
#define IS_UPPERCASE(x)     ((x) >= 'A' && (x) <= 'Z')
#define IS_LETER(x)         (IS_LOWERCASE(x) || IS_UPPERCASE(x))

int wordCounter(const char *str)
{
    int count = 0;

    while(*str)
    {
        while(!IS_LETER(*str) && *str)
            str++;

        if(!*str)
            return count;

        while(IS_LETER(*str))
            str++;

        if(!IS_LETER(*str))
            count++;
    }

    return count;
}
