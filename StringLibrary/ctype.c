#define IS_CAPITALLETTER(x)    ((x) >= 'A' && (x) <= 'Z')
#define IS_LOWERCASE(x)    ((x) >= 'a' && (x) <= 'z')
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

///////
