/*  
"The stack data structure is known as LIFO, which stands for 
Last In, First Out. 
It allows you to push elements of the same data type onto it. 
The operations that can be performed on a stack include:
Push: Insert an element onto the top of the stack.
Pop: Remove the last inserted element from the stack.
Peek/Top: View the top element of the stack without removing it.
Is Empty: Check if the stack is empty.
Is Full: Check if the stack is full.
When pushing data onto the stack, you need to know the size of 
the array to allocate memory for the stack. There are two ways 
to implement a stack: based on arrays or based on linked lists."
*/
/******************************************************************/
/*                     stack based on array                       */
/******************************************************************/

#if 0
#define StackEntry   int
#define MAXSTACK    100
typedef struct stack{
int top;
StackEntry stackElements[MAXSTACK];
int size;
}Stack_t;

void CreateStack(Stack_t *stackptr);
void PushStack(StackEntry element ,Stack_t * stackptr);
int StackFull(Stack_t * stackptr);
int StackEmpty(Stack_t * stackptr);
void PopStack(StackEntry *pe ,Stack_t * stackptr);
void StackTop(StackEntry *pe ,Stack_t * stackptr);
void ClearStack(Stack_t * stackptr);
void TraverseStack(Stack_t * stackptr, void(*ptrFunc)(StackEntry e));
void StackSize(Stack_t * stackptr, int *size);
#endif
/* "We have completed the APIs for the stack data structure using arrays. 
However, allocating a maximum stack size of 100 elements when only half
are typically used consumes unnecessary memory. To address this, 
we are considering implementing the stack using a linked list. 
This approach uses memory more efficiently by only allocating space 
for elements as they are needed. However, it is important to note that 
using a linked list may result in higher processing time compared to 
an array-based implementation." */
/******************************************************************/
/*                   stack based on Linked List                   */
/******************************************************************/
#if 1
#define StackEntry   int

typedef struct stacknode{
    StackEntry entry;
    struct stacknode *next;
}StackNode_t;

typedef struct stack{
    StackNode_t *top;
}Stack_t;

void CreateStack(Stack_t *stackptr);
void PushStack(Stack_t *stackptr, StackEntry e);
void PopStack(Stack_t *stackptr, StackEntry *pe);
void StactTop(Stack_t *stackptr, StackEntry *pe);
void ClearStack(Stack_t *stackptr);
void TraverseStack(Stack_t * stackptr, void(*ptrFunc)(StackEntry e));
void StackSize(Stack_t * stackptr, int *size);

#endif
