#include <stdlib.h>
#include "../Stack.h"

/*
 * Pre: The stack exists
 * Post: Returns the number of elements
 */
int StackSize(Stack *ps)
{
    /*
     * Complexity is ϴ(1)
     */
    return ps->size;
    
    /*
     * Complexity is ϴ(N)
     */
    int x;
    StackNode *pn = ps->top;
    for (x = 0; pn; pn = pn->next)
        x++;
    return x;
}

/*
 * Pre: The stack exists
 * Post: Function is passed to process every element
 */
void TraverseStack(Stack *ps, void (*pf)(StackEntry))
{
    for (StackNode *pn = ps->top; pn; pn = pn->next)
        (*pf)(pn->entry);
}

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
    ps->size = 0;
}

int StackFull(Stack *ps)
{
    return 0;
    // return ps->size >= MAXSTACK;
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
    ps->size--;
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
    ps->size++;
}

void CreateStack(Stack *ps)
{
    (*ps).top = NULL;
    (*ps).size = 0;
}
