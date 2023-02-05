#define LINKED_BASED_STACK
#define MAXSTACK 100
typedef char StackEntry;

#ifdef LINKED_BASED_STACK
/*
 * Linked-Based Implementation
 */
typedef struct stacknode
{
    StackEntry entry;
    struct stacknode *next;
} StackNode;

typedef struct stack
{
    StackNode *top;
    int size;
} Stack;
#else

/*
 * Array-Based Implementation
 */
typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
} Stack;
#endif

void TraverseStack(Stack *, void (*)(StackEntry));
void ClearStack(Stack *);
int StackSize(Stack *);
int StackFull(Stack *);
int StackEmpty(Stack *);
void StackTop(StackEntry *, Stack *);
void Pop(StackEntry *, Stack *);
int Push(StackEntry, Stack *);
void CreateStack(Stack *);
