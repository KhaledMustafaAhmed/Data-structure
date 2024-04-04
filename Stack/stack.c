#include <stdio.h>
/* stack based on array */
#define MAXSTACK    100

typedef struct stack{
int top;
int stackElements[MAXSTACK];
int size;
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
void PushStack(int element ,Stack_t * stackptr)
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
void PopStack(int *pe ,Stack_t * stackptr)
{
    stackptr->top--;
    *pe = stackptr->stackElements[stackptr->top];
    stackptr->size--;
} 
/* 
pre: stack is initialized and not empty
post: talk a copy of the last element from stack .
*/
void StackTop(int *pe ,Stack_t * stackptr)
{
    *pe = stackptr->stackElements[stackptr->top-1];
}

void ClearStack(Stack_t * stackptr)
{
    stackptr->top = 0;
    stackptr->size = 0;
}
