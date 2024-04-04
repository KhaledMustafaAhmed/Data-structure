/*  
Stack data structure: known as LIFO or Last in first out.
you can only puch a data from same data type.
operations on satck: 
1- push >> inset element from top
2- pop >> remove the last inserted element
3- peek / top >> tack the top element without remove it.
4- is empty >> check if it is empty or not.
5- is full >> check if it is full or not.
to push data to stack you need to know the size of array so you need to allocate some memory for stack. 
there is two ways of implementing stack >> 1- based arrays   2- based linked list
*/

/* stack based on array */
#define MAXSTACK    100

typedef struct stack{
int top;
int stackElements[MAXSTACK];
int size;
}Stack_t;

/* this function to initialize the top to -1 */
void CreateStack(Stack_t *stackptr);
/* to push new element into stack */
void PushStack(int element ,Stack_t * stackptr);
/*1 if full, 0 otherwise*/
int StackFull(Stack_t * stackptr);
/* pop element from stack */
void PopStack(int *pe ,Stack_t * stackptr);