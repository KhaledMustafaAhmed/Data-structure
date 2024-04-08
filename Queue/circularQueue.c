#define LIMIT_MEMORY_   0
#define STATIC_MEMORY_  1
#define MAXQUEUE  10

#if STATIC_MEMORY_
/* Queue type */
typedef struct _Queue_t{
    int rear;
    int front;
    int size;
    int QueueElements[MAXQUEUE];
}_Queue_t;

/* Initialization of Queue */
void CreateQueue(_Queue_t *Queueptr)
{
    Queueptr->rear = -1;
    Queueptr->front = 0;
    Queueptr->size = 0;
}

void EnQueue(_Queue_t *Queueptr, int element)
{
    if(Queueptr->size == MAXQUEUE)
    {
        printf(" Queue is full \n");
    }
    else
    {
        Queueptr->rear = (Queueptr->rear + 1) % MAXQUEUE;
        Queueptr->QueueElements[Queueptr->rear] = element;
        Queueptr->size++;
    }
}

void DeQueue(_Queue_t *Queueptr, int *element)
{
    if(Queueptr->size == 0)
    {
        printf(" Queue is empty \n");
    }
    else
    {
        *element = Queueptr->QueueElements[Queueptr->front];
        Queueptr->front = (Queueptr->front + 1) % MAXQUEUE;
        Queueptr->size--;        
    }
}
int EmptyQueue(_Queue_t *Queueptr)
{
    return !Queueptr->size;
}
int FullQueue(_Queue_t *Queueptr)
{
    return (Queueptr->size == MAXQUEUE);
}
int QueueSize(_Queue_t *Queueptr)
{
    return Queueptr->size;
}
void ClearQueue(_Queue_t *Queueptr)
{
    Queueptr->rear = -1;
    Queueptr->front = 0;
    Queueptr->size = 0;
}
void TraverseQueue(_Queue_t *Queueptr, void(*ptrFunc)(int element))
{
    int i = 0, pos= Queueptr->front;
    while(i != Queueptr->size)
    {
        (*ptrFunc)(Queueptr->QueueElements[pos]);
        pos = (pos + 1) % MAXQUEUE;
        i++;
    }
    if(!i)
    {
        printf(" Queue is Empty \n");
    }
}
#endif

#if LIMIT_MEMORY_
typedef struct _QueueNode{
    int data;
    struct _QueueNode *next;
}_QueueNode;

typedef struct _Queue_t{
   _QueueNode* front;
   _QueueNode* rear;
   int size;
}_Queue_t;
#endif