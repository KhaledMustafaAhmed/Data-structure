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

/* ============================================================================================================== */
/* 
Doubly LinkedList:
-------------------------------------------------
|  _node_t *previous  | Data |  _node_t *next   |
-------------------------------------------------
*/
/* Node type contain Data and pointer of type _single_node_t point to next node and prev node */
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}_Double_node_t;

/* ============================================================================================================== */
/* 
circuly single LinkedList: as the same as the Singly linkedlist but the last node point to the first node.
----------------------------------
| Data | _single_node_t *next   |
----------------------------------
circuly Doubly LinkedList: as the same as the Singly linkedlist but the last node point to the first node.
-------------------------------------------------
|  _node_t *previous  | Data |  _node_t *next   |
-------------------------------------------------
*/

_single_node_t* Create_new_single_node(void);

void Display_single_LinkedList(_single_node_t* node);

_single_node_t * Insert_atbegain_single_Node(_single_node_t *node);

void Insert_atEnd_single_Node(_single_node_t *node);

void Insert_atPosition_single_node(_single_node_t *node, int position);

void Delete_first_Node(_single_node_t *node);
