/*
 * Basic useful tools used by all modules
 */ 

#ifndef UTIL_H_
#define UTIL_H_

#include <assert.h>

#define TRUE 1
#define FALSE 0

typedef char* string;
typedef char bool;

void *checked_malloc(int);
string String(char *);

#endif
