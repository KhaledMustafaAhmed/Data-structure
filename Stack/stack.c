#include <stdio.h>
#include <stdlib.h>
/******************************************************************/
/*                     stack based on array                       */
/******************************************************************/

#define StackEntry   int
#define MAXSTACK    100
typedef struct stacknode{
    StackEntry entry;
    struct stacknode *next;
}StackNode_t;

typedef struct stack{
    StackNode_t *top;
    int size;
}Stack_t;

#if 0

typedef struct stack{
int top;
int size;
StackEntry stackElements[MAXSTACK];
}Stack_t;

/* 
for example: 
void main()
{
    int element;
    Stack_t s;
    CreateStack(&s);

    PushStack(element, &s);
}
*/
void CreateStack(Stack_t *stackptr)
{
    stackptr->top = 0;
    stackptr->size = 0;
}
/*
pre: the stack is initialized and not full
post: the element is has been stored at the top of the stack and e does not 
change.
*/
void PushStack(StackEntry element ,Stack_t * stackptr)
{
    stackptr->stackElements[stackptr->top++] = element;
    stackptr->size++;
}
/* 
return 1: if full
return 0: otherwise 
*/
int StackFull(Stack_t * stackptr)
{
    return (stackptr->top >= MAXSTACK) ? 1: 0;  
}
/* 
return 1: if empty
return 0: otherwise 
*/
int StackEmpty(Stack_t * stackptr)
{
    return (stackptr->top <= 0) ? 1: 0;  
}

/* 
pre: stack is initialized and not empty
post: pop the last element from stack and decrement the stack size, top.
*/
void PopStack(StackEntry *pe ,Stack_t * stackptr)
{
    stackptr->top--;
    *pe = stackptr->stackElements[stackptr->top];
    stackptr->size--;
} 
/* 
pre: stack is initialized and not empty
post: talk a copy of the last element from stack .
*/
void StackTop(StackEntry *pe ,Stack_t * stackptr)
{
    *pe = stackptr->stackElements[stackptr->top-1];
}

void ClearStack(Stack_t * stackptr)
{
    stackptr->top = 0;
    stackptr->size = 0;
}
void TraverseStack(Stack_t * stackptr, void(*ptrFunc)(StackEntry e))
{
    int i;
    for(i= stackptr->top; i>0; i--)
    {
        (*ptrFunc)(stackptr->stackElements[i-1]);
    }
}
void StackSize(Stack_t * stackptr, int *size)
{
    *size = stackptr->size;
}
#endif
/******************************************************************/
/*                   stack based on Linked List                   */
/******************************************************************/
#if 1
/* Stack first not point to any stack node. */
void CreateStack(Stack_t *stackptr)
{
    stackptr->top = NULL;
    stackptr->size = 0;
}
void PushStack(Stack_t *stackptr, StackEntry e)
{
    StackNode_t *node = (StackNode_t *)malloc(sizeof(StackNode_t));
    node->entry = e;
    node->next = stackptr->top;
    stackptr->top = node;
    stackptr->size++;
}
void PopStack(Stack_t *stackptr, StackEntry *pe)
{
    *pe = stackptr->top->entry;
    StackNode_t *ptr = stackptr->top;
    stackptr->top = stackptr->top->next;
    free(ptr);
    ptr = NULL;
    stackptr->size--;
}
void StactTop(Stack_t *stackptr, StackEntry *pe)
{
    *pe = stackptr->top->entry;
}
void ClearStack(Stack_t *stackptr)
{
    StackNode_t *pn = stackptr->top;
    StackNode_t *qn = stackptr->top;
    while(pn != NULL)
    { 
        pn = pn->next;
        free(qn);
        qn = pn;
    }
    stackptr->top = NULL;
    stackptr->size = 0;
}
void TraverseStack(Stack_t * stackptr, void(*ptrFunc)(StackEntry e))
{
    StackNode_t *pn = stackptr->top;
    while(pn)
    {
        (*ptrFunc)(pn->entry);
        pn= pn->next;
    }
}
void StackSize(Stack_t * stackptr, int *size)
{
    *size = stackptr->size;
}
#endif
