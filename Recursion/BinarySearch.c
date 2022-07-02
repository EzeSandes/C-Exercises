#include <stdio.h>
#include <stdlib.h>

void* bSearch(const void *vec, const void *key, unsigned numberOfElem, unsigned sizeElem,
              int (*cmp)(const void *, const void *));
void* _bSearch(const void *vec, const void *key, unsigned sizeElem, int ini, int fin,
               int (*cmp)(const void *, const void *));

int cmp_int(const void *elem1, const void *elem2);

int main()
{
    int vec[] = {0,1,2,3,4,5,6,7,8,9};
    int num = 0;

    int *pos = (int *)bSearch(vec, &num, sizeof(vec) / sizeof(int), sizeof(int), cmp_int);

    if(pos)
        printf("Element found: %d", *pos);
    else
        printf("NULL!\n");

    return 0;
}

///////////////////////////////

void* bSearch(const void *vec, const void *key, unsigned numberOfElem, unsigned sizeElem,
              int (*cmp)(const void *, const void *))
{
    return _bSearch(vec, key, sizeElem, 0, numberOfElem - 1, cmp);
}

///////////////////////////////

void* _bSearch(const void *vec, const void *key, unsigned sizeElem, int ini, int end,
               int (*cmp)(const void *, const void *))
{
    int     half = (ini + end) / 2;
    int     comp;

    if(fin < ini)
        return NULL;

    comp = cmp(key, (char *)vec + (half * sizeElem));

    if(comp == 0)
        return (char *)vec + (half * sizeElem);

    if(comp < 0)
        return _bSearch(vec, key, sizeElem, ini, half - 1, cmp);

    return _bSearch(vec, key, sizeElem, half + 1, end, cmp);
}

///////////////////////////////

int cmp_int(const void *elem1, const void *elem2)
{
    return *(int *)elem1 - *(int *)elem2;
}

///////////////////////////////
///////////////////////////////
