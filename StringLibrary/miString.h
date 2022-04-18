#ifndef MISTRING_H_INCLUDED
#define MISTRING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

///////////////////////

int str_len(const char *cad);
char* str_cat(char *donde, const char *que);
char* str_ncat(char *donde, const char *que, size_t n);
char* str_chr(const char *donde, int que);
char* str_rchr(char *donde, int que);
int str_cmp(const char *donde, const char *que);
char* str_cpy(char *donde, const char *que);
char* str_ncpy(char *donde, const char *que, size_t n);
char* str_cpy_mine(char *where, const char *since, const char *until);
size_t str_cspn(const char *donde, const char *que);
char* str_str(const char *donde, const char *que);
char* str_pbrk(const char *donde, const char *que);

void* mem_cpy(void *dest, const void *origen, size_t cantBytes);
void* mem_move(void *donde, const void *que, size_t n);
///////////////////////

#endif // MISTRING_H_INCLUDED

