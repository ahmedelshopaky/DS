#define LINKED_BASED_STACK
#define MAXSTACK 100
typedef char StackEntry;

/*
 * Array-Based Implementation
 */
#ifdef ARRAY_BASED_STACK
typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
} Stack;
#endif

/*
 * Linked-Based Implementation
 */
#ifdef LINKED_BASED_STACK
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
#endif

void TraverseStack(Stack *, void (*)(StackEntry));
void ClearStack(Stack *);
int StackSize(Stack *);
int StackFull(Stack *);
int StackEmpty(Stack *);
void StackTop(StackEntry *, Stack *);
void Pop(StackEntry *, Stack *);
void Push(StackEntry, Stack *);
void CreateStack(Stack *);
