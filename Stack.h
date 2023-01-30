#define MAXSTACK 100
typedef int StackEntry;

typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
} Stack;

void TraverseStack(Stack *, void (*)(StackEntry));
void ClearStack(Stack *);
int StackSize(Stack *);
void StackTop(StackEntry *, Stack *);
int StackEmpty(Stack *);
void Pop(StackEntry *, Stack *);
int StackFull(Stack *);
void Push(StackEntry, Stack *);
void CreateStack(Stack *);
