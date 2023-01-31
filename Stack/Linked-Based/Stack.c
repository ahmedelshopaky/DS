#include <stdlib.h>
#include "../Stack.h"

/*
 * Pre: The stack exists
 * Post: All the elements freed
 */
void ClearStack(Stack *ps)
{
    /*
     * Complexity is ϴ(N)
     * Total time = N * one loop time
     */
    StackNode *pn = ps->top;
    while (pn)
    {
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
}

int StackFull(Stack *ps)
{
    return 0;
}

/*
 * Pre: The stack exists
 * Post: Returns the status, 1 or 0
 */
int StackEmpty(Stack *ps)
{
    return !ps->top;
}

void StackTop(StackEntry *pe, Stack *ps)
{
    *pe = ps->top->entry;
}

/*
 * Pre: The stack exists and it is not empty
 * Post: The item at the top of the stack has been removed and returned
 */
void Pop(StackEntry *pe, Stack *ps)
{
    StackNode *pn;
    *pe = ps->top->entry;
    pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
}

/*
 * Pre: The stack exists and is initialized
 * Post: The argument item has been stored at the top of the stack
 */
void Push(StackEntry e, Stack *ps)
{
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
}

void CreateStack(Stack *ps)
{
    (*ps).top = NULL;
}
