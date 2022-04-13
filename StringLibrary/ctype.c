#define IS_CAPITALLETTER(x)    ((x) >= 'A' && (x) <= 'Z')
#define IS_LOWERCASE(x)    ((x) >= 'a' && (x) <= 'z')

#define A_MINUSC(x)    ((x) >= 'a' && (x) <= 'z' ? (x) : ((x) + ('a' - 'A')))
#define A_MAYUSC(x)    ((x) >= 'A' && (x) <= 'Z' ? (x) : ((x) - ('a' - 'A')))

//////////////////////////////

int myTolower(int ch)
{
    return IS_CAPITALLETTER(ch)?   ch + 32 : ch;
}

///////

int myToupper(int ch)
{
    return IS_LOWERCASE(ch)?   ch - 32 : ch;
}

/////////////////////////////////// Another options

int to_lower(int ch)
{
    return A_MINUSC(ch);
}

/////////

int to_upper(int ch)
{
    return A_MAYUSC(ch);
}
