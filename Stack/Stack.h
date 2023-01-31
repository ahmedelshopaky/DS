#define MAXSTACK 100
typedef int StackEntry;

/*
 * Array-Based Implementation
 */
// typedef struct stack
// {
//     int top;
//     StackEntry entry[MAXSTACK];
// } Stack;

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

void TraverseStack(Stack *, void (*)(StackEntry));
void ClearStack(Stack *);
int StackSize(Stack *);
int StackFull(Stack *);
int StackEmpty(Stack *);
void StackTop(StackEntry *, Stack *);
void Pop(StackEntry *, Stack *);
void Push(StackEntry, Stack *);
void CreateStack(Stack *);
