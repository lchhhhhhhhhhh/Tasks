#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/select.h>
#include <math.h>


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

extern Status init_stack(Stackn* pStack);
extern Status init_stackc(Stack* pStack);
extern void stack_free(Stack *pStack);
extern void stack_clear(Stack *pStack);
extern Status stack_pushc(Stack *pStack,char e);
extern Status stack_push(Stackn *pStack,StackElem e);
extern Status stack_pop(Stackn* pStack,StackElem *pElem);
extern Status stack_popc(Stack* pStack,char* pChar);
extern int StackEmpty(Stack *s);
extern void trans(char* str,char* p);
extern double calc(char* str);
extern double dec(char str[]);
extern int stackn_length(Stackn *pStack);
extern void total(FILE* fp,const char* name);
extern char get_char();
extern void tbin(char* str,char* post);
extern int bint_print(double dec_0);
extern char* inttohex(int aa);
extern long hexToDec(char *source);
extern char* hex(char str[]);