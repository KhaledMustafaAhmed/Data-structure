# Data Structures using C programming
## 1- Stacks

The stack data structure is known as LIFO, which stands for 
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
to implement a stack: based on arrays or based on linked lists.

- Stack based on array:
``` c
typedef struct stack{
int top;
StackEntry stackElements[MAXSTACK];
int size;
}Stack_t;
```
Defining a struct named Stack to contain heterogeneous data, followed by the APIs implemented using this struct: 

```c 
/*
Description: Creates a new stack.
Pre: stackptr points to a valid stack structure.
Post: A new stack is initialized and ready to use.
*/
void CreateStack(Stack_t *stackptr);
/* 
Description: Pushes an element onto the stack.
Pre: stackptr points to a valid stack structure, and element is of the appropriate data type.
Post: The element is added to the top of the stack.
*/
void PushStack(StackEntry element ,Stack_t * stackptr);
/* 
Description: Checks if the stack is full.
Pre: stackptr points to a valid stack structure.
Post: Returns 1 if the stack is full, 0 otherwise.
*/
int StackFull(Stack_t * stackptr);
/* 
Description: Checks if the stack is empty.
Pre: stackptr points to a valid stack structure.
Post: Returns 1 if the stack is empty, 0 otherwise.
*/
int StackEmpty(Stack_t * stackptr);
/* 
Description: Removes the top element from the stack.
Pre: stackptr points to a valid stack structure, and pe is a valid pointer.
Post: The top element is removed from the stack, and its value is stored in pe.
*/
void PopStack(StackEntry *pe ,Stack_t * stackptr);
/* 
Description: Retrieves the top element from the stack without removing it.
Pre: stackptr points to a valid stack structure, and pe is a valid pointer.
Post: The value of the top element is stored in pe.
*/
void StackTop(StackEntry *pe ,Stack_t * stackptr);
/*  
Description: Clears all elements from the stack.
Pre: stackptr points to a valid stack structure.
Post: The stack is empty after this operation.
*/
void ClearStack(Stack_t * stackptr);
/* 
Description: Traverses the stack and performs a function on each element.
Pre: stackptr points to a valid stack structure, and ptrFunc is a valid function pointer.
Post: The specified function ptrFunc is applied to each element in the stack.
*/
void TraverseStack(Stack_t * stackptr, void(*ptrFunc)
(StackEntry e));
/* 
Description: Retrieves the current size of the stack.
Pre: stackptr points to a valid stack structure, and size is a valid pointer.
Post: The size of the stack is stored in the variable pointed to by size.
*/
void StackSize(Stack_t * stackptr, int *size);
```
We have completed the APIs for the stack data structure using arrays. However, allocating a maximum stack size of 100 elements when only half are typically used consumes unnecessary memory. To address this,  we are considering implementing the stack using a linked list.This approach uses memory more efficiently by only allocating space for elements as they are needed. However, it is important to note that  using a linked list may result in higher processing time compared to an array-based implementation.
- stack based on Linked List:
```c
typedef struct stacknode{
    StackEntry entry;
    struct stacknode *next;
}StackNode_t;

typedef struct stack{
    StackNode_t *top;
}Stack_t;
```
Defining a struct named Stack to contain heterogeneous data, followed by the APIs implemented using this struct:
```c
/*
Description: Creates a new stack.
Pre: stackptr points to a valid stack structure.
Post: A new stack is initialized and ready to use.
*/
void CreateStack(Stack_t *stackptr);

/* 
Description: Pushes an element onto the stack.
Pre: stackptr points to a valid stack structure, and e is of the appropriate data type.
Post: The element e is added to the top of the stack.
*/
void PushStack(Stack_t *stackptr, StackEntry e);

/* 
Description: Removes the top element from the stack.
Pre: stackptr points to a valid stack structure, and pe is a valid pointer.
Post: The top element is removed from the stack, and its value is stored in pe.
*/
void PopStack(Stack_t *stackptr, StackEntry *pe);

/* 
Description: Retrieves the top element from the stack without removing it.
Pre: stackptr points to a valid stack structure, and pe is a valid pointer.
Post: The value of the top element is stored in pe.
*/
void StackTop(Stack_t *stackptr, StackEntry *pe);

/*  
Description: Clears all elements from the stack.
Pre: stackptr points to a valid stack structure.
Post: The stack is empty after this operation.
*/
void ClearStack(Stack_t *stackptr);

/* 
Description: Traverses the stack and performs a function on each element.
Pre: stackptr points to a valid stack structure, and ptrFunc is a valid function pointer.
Post: The specified function ptrFunc is applied to each element in the stack.
*/
void TraverseStack(Stack_t *stackptr, void(*ptrFunc)(StackEntry e));

/* 
Description: Retrieves the current size of the stack.
Pre: stackptr points to a valid stack structure, and size is a valid pointer.
Post: The size of the stack is stored in the variable pointed to by size.
*/
void StackSize(Stack_t *stackptr, int *size);
```
### Comparison between array-based and LinkedList-based implementation: 


| Functions | Array-based     | LinkedList-based                |
| :-------- | :------- | :------------------------- |
| `Pop` | `O(1)` | `O(1)` |
| `Push` | `O(1)` | `O(1)` |
| `CreateStack` | `O(1)` | `O(1)` |
| `StackSize` | `O(1)` | `O(1)` |
| `TraverseStack` | `O(N)` | `O(N)` |
| `ClearStack` | `O(1)` | `O(N)` |


| Array-based | LinkedList-based   |
| :-------- | :------- |
| `All the space is reserved even the stack is empty.`      | `extra field next for every node` |
| `Stack gets full even if the memory is not.`      | `the stack size as large as the memory you have.` |

Then, there are advantages and disadvantages for every implementation. Which one is better **really** depends on the application.

## 2- Queues
 
