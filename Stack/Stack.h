#include "../Global.h"
#define LINKED_BASED_STACK

typedef struct stack *PStack;

void TraverseStack(PStack *, void (*)(StackEntry));
void ClearStack(PStack *);
int StackSize(PStack *);
int StackFull(PStack *);
int StackEmpty(PStack *);
void StackTop(StackEntry *, PStack *);
void Pop(StackEntry *, PStack *);
int Push(StackEntry, PStack *);
// int Push(void *, PStack *, int);
void CreateStack(PStack *);
