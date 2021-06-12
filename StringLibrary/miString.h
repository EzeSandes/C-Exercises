#ifndef MISTRING_H_INCLUDED
#define MISTRING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

///////////////////////

int miStrlen(const char *cad);
char* miStrcat(char *donde, const char *que);
char* miStrncat(char *donde, const char *que, size_t n);
char* miStrchr(const char *donde, int que);
char* miStrrchr(char *donde, int que);
int miStrcmp(const char *donde, const char *que);
char* miStrcpy(char *donde, const char *que);
char* miStrncpy(char *donde, const char *que, size_t n);
size_t miStrcspn(const char *donde, const char *que);
char* miStrstr(const char *donde, const char *que);
char* miStrpbrk(const char *donde, const char *que);

void* mem_cpy(void *dest, const void *origen, size_t cantBytes);
void* memmove_mio(void *donde, const void *que, size_t n);
///////////////////////

#endif // MISTRING_H_INCLUDED

