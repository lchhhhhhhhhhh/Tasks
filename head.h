#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>
#include <unistd.h>


#define OK 1
#define ERROR 0
#define MAXSIZE 10

typedef double StackElem;
typedef int Status;
typedef int Bool;
typedef struct 
{
    char* pBase;
    char* pTop;
    int size;
}Stack;

typedef struct 
{
    StackElem* pBase;
    StackElem* pTop;
    int size;
}Stackn;



