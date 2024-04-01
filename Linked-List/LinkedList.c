#include <stdio.h>
#include <stdlib.h>
/* 
Singly LinkedList:
----------------------------------
| Data | _single_node_t *next   |
----------------------------------
*/
/* Node type contain Data and pointer of type _single_node_t point to next node */
typedef struct node{
    int data;
    struct node *next;
}_single_node_t;

/* initialize head and tail Global pointer to know the start and end of linkedlist */
_single_node_t *head = NULL;
_single_node_t *tail = NULL;
int size_of_linkedlist = 0;


_single_node_t* Create_new_single_node(void);

void Display_single_LinkedList(_single_node_t* node);

_single_node_t * Insert_atbegain_single_Node(_single_node_t *node);

void Insert_atEnd_single_Node(_single_node_t *node);

void Insert_atPosition_single_node(_single_node_t *node, int position);

void Delete_first_Node(_single_node_t **nodePtr);

void Delete_last_Node(_single_node_t **nodePtr);

int main(void)
{
    /* Create new node */
    _single_node_t *newNode = Create_new_single_node();
    if(newNode != NULL) {
        head = newNode;
        tail = newNode;
    }
    /* Create another node */
    _single_node_t *seconedNode = Create_new_single_node();
    if(seconedNode != NULL) {
        newNode->next = seconedNode;
        tail = seconedNode;
    }
    /* create another node */
     _single_node_t *thirdNode = Create_new_single_node();
    if(thirdNode != NULL) {
        seconedNode->next = thirdNode;
        tail = thirdNode;
    }
    Display_single_LinkedList(head);
    Delete_last_Node(&head);
    printf("===================\n");
    Display_single_LinkedList(head);
    return 0;
}
_single_node_t* Create_new_single_node(void)
{
    /* create first node in linkedlist */
    _single_node_t* newNode = (_single_node_t *)malloc(sizeof(_single_node_t));
    if(newNode != NULL)
    {
        printf("Inserting Data into node: ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        size_of_linkedlist++;
    } 
    return newNode;
}
_single_node_t * Insert_atbegain_single_Node(_single_node_t *node)
{
    printf("Insert at begain ");
    _single_node_t * newNode = Create_new_single_node();
    newNode->next = node; 
    size_of_linkedlist++;
    return newNode; 
}
void Insert_atEnd_single_Node(_single_node_t *node)
{
    printf("Insert at end ");
    _single_node_t *newNode = Create_new_single_node();
    node->next = newNode;
    newNode->next = NULL;
    node = newNode;
    size_of_linkedlist++;
}
void Display_single_LinkedList(_single_node_t* node)
{
    _single_node_t *ptr = node;
    int i = 0;
    while(i<size_of_linkedlist)
    {
        printf("data of node %d = %d\n",i+1,ptr->data);
        i++;
        ptr = ptr->next;
    }
}
void Insert_atPosition_single_node(_single_node_t *node, int position)
{
    if(position > size_of_linkedlist || position < 0)
    {
        printf("Invalid position");
        return;
    }
    printf("Insert data at position %d ", position);
    _single_node_t *newNode = Create_new_single_node();
    
    if(position == 0)
    {
        newNode->next = node;
        node = newNode;
    }
    else
    {
        _single_node_t * ptr = node;
        int i = 0;
        while(i< position-1)
        {
            ptr = ptr->next;
            i++;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    size_of_linkedlist++;
}
void Delete_first_Node(_single_node_t **nodePtr)
{
    if (*nodePtr != NULL)
    {
        _single_node_t *ptr = *nodePtr;
        *nodePtr = (*nodePtr)->next;
        ptr->next = NULL;
        free(ptr);
        ptr = NULL;
        size_of_linkedlist--;
    }
    else
    {
        printf("Invalid node");
    }
}

void Delete_last_Node(_single_node_t **nodePtr)
{
    if (*nodePtr != NULL)
    {
        _single_node_t *prev = NULL;
        _single_node_t *ptr = *nodePtr;
        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        if (prev != NULL) {
            prev->next = NULL;
            free(ptr);
            ptr = NULL;
            tail = prev;
            size_of_linkedlist--;
        } else { // Only one node in the list
            free(ptr);
            ptr = NULL;
            *nodePtr = NULL;
            head = NULL;
            tail = NULL;
            size_of_linkedlist--;
        }
    }
    else
    {
        printf("Invalid node");
    }
}
