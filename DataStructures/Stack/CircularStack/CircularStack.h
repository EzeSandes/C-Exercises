/*
The stack pointer points to the base, not the top unlike normal stack
So if I want to see the top I have to go from the base to the next.

The only thing different is PUSH ON STACK. Which is about the first and not the last as in Circular Queue.

Unstack == Undock Circular Queue.
Empty Stack == Empty Circular Queue. 
*/

typedef struct sNodo{
    void        *info;
    unsigned    tamInfo;
    struct  sNodo   *sig;
}tNodo;

typedef tNodo*  tPila;

void createCircularStack(tPila *p);
int isFull(const tPila *p, unsigned cantBytes);
int push(tPila *p, const void *d, unsigned cantBytes);
int viewTop(const tPila *p, void *d, unsigned cantBytes);
int isEmpty(const tPila *p);
void emptyCircularStack(tPila *p);
int pop(tPila *p, void *d, unsigned cantBytes);
