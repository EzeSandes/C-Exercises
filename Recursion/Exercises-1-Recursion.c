/*TAREA

    Given a string(ex. "hola"), print the string in every different way below using recursion.
    Note: The '*' are in the main only to know if the function print correctly.

Exerc:      1   2   3       4       5       6   7
            *   *   *       *       *       *   *
            h   a   hola    a       h       h   h
            o   l   ola     la      ho      o   o
            l   o   la      ola     hol     l   l
            a   h   a       hola    hola    a   a
            *    *  *       *       *       a   l
                                            l   o
                                            o   h
                                            h   *
                                            *
  */


/// SOLUTION

/**
*
*
*
*
*
*
*
*
*
*
*
*
*
*/
//////////////////////////

void exercise2(const char *cad)
{
    if(*cad == '\0')
        return;

    exercise2(cad + 1);
    printf("%c\n", *cad);
}

//////////////////////////

void exercise1(const char *cad)
{
    if(*cad == '\0')
        return;

    printf("%c\n", *cad);
    exercise1(cad + 1);
}

//////////////////////////

void exercise3(const char *cad)
{
    if(*cad == '\0')
        return;

    printf("%s\n", cad);
    exercise3(cad + 1);
}

//////////////////////////

void exercise4(const char *cad)
{
    if(*cad == '\0')
        return;

    exercise4(cad + 1);
    printf("%s\n", cad);

//      Another way
//    printf("%*s\n", exercise4(cad + 1) + 1, cad);
}

//////////////////////////
int exercise5(const char *cad)
{
    if(*cad == '\0')
        return 0;

    printf("%*s\n", exercise5(cad + 1) + 1, cad);
    
    return 1;
}

//////////////////////////

void exercise6(const char *cad)
{
    if(*cad == '\0')
        return;

    printf("%c\n", *cad);
    exercise6(cad + 1);
    printf("%c\n", *cad);
    return;
}

//////////////////////////

void exercise7(const char *cad)
{
    printf("%c\n", *cad);

    if(*(cad + 1) == '\0')
        return;

    exercise7(cad + 1);
    printf("%c\n", *cad);
    return;
}
