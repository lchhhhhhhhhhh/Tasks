#include "head.h"

Status init_stack(Stackn* pStack)
{
    pStack ->pBase = (StackElem*)malloc(MAXSIZE * sizeof(StackElem));
    if(!pStack ->pBase)
    {
        return ERROR;
    }
    pStack ->pTop = pStack ->pBase;
    pStack ->size = MAXSIZE;
    return OK;
}

Status init_stackc(Stack* pStack)
{
    pStack ->pBase = (char*)malloc(MAXSIZE * sizeof(char));
    if(!pStack ->pBase)
    {
        return ERROR;
    }
    pStack ->pTop = pStack ->pBase;
    pStack ->size = MAXSIZE;
    return OK;
}

void stack_free(Stack *pStack)
{
    while(pStack ->pTop != pStack ->pBase){
        free(pStack ->pTop);
    }
};

void stack_clear(Stack *pStack)
{
    pStack ->pTop = pStack ->pBase;
};

Bool is_empty(Stack* pStack)
{
    if (pStack ->pTop == pStack ->pBase)
		return 1;    
	else
		return 0;
};

int stackn_length(Stackn *pStack)
{
    return pStack ->pTop - pStack ->pBase;
}

int stack_length(Stack *pStack)
{
    return pStack ->pTop - pStack ->pBase;
}

Status stack_get_top(Stack pStack,StackElem pElem)
{
        pElem = *pStack.pTop;
        if(pElem != *pStack.pTop)
        {
            return ERROR;
        }
        else
        {
            return OK;
        }
}

Status stack_pushc(Stack *pStack,char e)
{
    if(pStack->pTop - pStack->pBase >= pStack->size){
        pStack->pBase = (char *)realloc(pStack->pBase,(pStack->size + 5)*sizeof(char));
        if(NULL == pStack->pBase)
            return ERROR;
        pStack->pTop = pStack->pBase + pStack->size;
        pStack->size = pStack->size+5;
    }
    *pStack->pTop = e;
    pStack->pTop++;
    return OK;
}

Status stack_push(Stackn *pStack,StackElem e)
{
    if(pStack->pTop - pStack->pBase >= pStack->size){
        pStack->pBase = (double *)realloc(pStack->pBase,(pStack->size + 5)*sizeof(double));
        if(NULL == pStack->pBase)
            return ERROR;
        pStack->pTop = pStack->pBase + pStack->size;
        pStack->size = pStack->size+5;
    }
    *pStack->pTop = e;
    pStack->pTop++;
    return OK;
}

Status stack_pop(Stackn* pStack,StackElem *pElem)
{
    if(pStack->pTop == pStack->pBase)
        return ERROR;
    pStack->pTop--;
    *pElem=*pStack->pTop;
    return OK;
}

Status stack_popc(Stack* pStack,char* pChar)
{
    if(pStack->pTop == pStack->pBase)
        return ERROR;
    pStack->pTop--;
    *pChar=*pStack->pTop;
    return OK;
}

int StackEmpty(Stack *s){
    if(s->pTop == s->pBase)
        return OK;
    return ERROR;
}