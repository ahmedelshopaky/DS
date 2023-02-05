#include <stdlib.h>
#include <string.h>
#include "Stack.h"

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

/*
 * Pre: The stack exists
 * Post: Returns the number of elements
 */
int StackSize(PStack *pps)
{
    /*
     * Complexity is ϴ(1)
     */
    return (*pps)->size;

    /*
     * Complexity is ϴ(N)
     */
    int x;
    StackNode *pn = (*pps)->top;
    for (x = 0; pn; pn = pn->next)
        x++;
    return x;
}

/*
 * Pre: The stack exists
 * Post: Function is passed to process every element
 */
void TraverseStack(PStack *pps, void (*pf)(StackEntry))
{
    for (StackNode *pn = (*pps)->top; pn; pn = pn->next)
        (*pf)(pn->entry);
}

/*
 * Pre: The stack exists
 * Post: All the elements freed
 */
void ClearStack(PStack *pps)
{
    /*
     * Complexity is ϴ(N)
     * Total time = N * one loop time
     */
    StackNode *pn = (*pps)->top;
    while (pn)
    {
        pn = pn->next;
        free((*pps)->top);
        (*pps)->top = pn;
    }
    (*pps)->size = 0;
}

int StackFull(PStack *pps)
{
    return 0;
    // return (*pps)->size >= MAXSTACK;
}

/*
 * Pre: The stack exists
 * Post: Returns the status, 1 or 0
 */
int StackEmpty(PStack *pps)
{
    return !(*pps)->top;
}

void StackTop(StackEntry *pe, PStack *pps)
{
    *pe = (*pps)->top->entry;
}

/*
 * Pre: The stack exists and it is not empty
 * Post: The item at the top of the stack has been removed and returned
 */
void Pop(StackEntry *pe, PStack *pps)
{
    StackNode *pn;
    *pe = (*pps)->top->entry;
    pn = (*pps)->top;
    (*pps)->top = (*pps)->top->next;
    free(pn);
    (*pps)->size--;
}

/*
 * Pre: The stack exists and is initialized
 * Post: The argument item has been stored at the top of the stack
 */
int Push(StackEntry e, PStack *pps)
{
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    if (!pn)
        return 0;
    else
    {
        pn->entry = e;
        pn->next = (*pps)->top;
        (*pps)->top = pn;
        (*pps)->size++;
        return 1;
    }
}

void CreateStack(PStack *pps)
{
    *pps = (Stack *)malloc(sizeof(Stack));
    (*pps)->size = 0;
    (*pps)->top = NULL;
}

#else

/*
 * Array-Based Implementation
 */
typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
    // void *entry[MAXSTACK];
} Stack;

/*
 * Precondition: The stack is initialized
 */
void TraverseStack(PStack *pps, void (*pf)(StackEntry))
{
    for (int i = (*pps)->top; i > 0; i--)
    {
        (*pf)((*pps)->entry[i - 1]);
    }
}

/*
 * Pre: The stack is initialized
 * Post: Destroy all elements, the stack looks initialized.
 */
void ClearStack(PStack *pps)
{
    (*pps)->top = 0;
}

int StackSize(PStack *pps)
{
    return (*pps)->top;
}

/*
 * Pre: The stack is initialized and not empty
 * Post: The last elemnet in the stack is returned without destroy it
 */
void StackTop(StackEntry *pe, PStack *pps)
{
    *pe = (*pps)->entry[(*pps)->top - 1];
}

int StackEmpty(PStack *pps)
{
    return !(*pps)->top;
}

/*
 * Pre: The stack is initialized and not empty
 * Post: The last element entered is returned
 */
void Pop(StackEntry *pe, PStack *pps)
{
    *pe = (*pps)->entry[--((*pps)->top)];
}

int StackFull(PStack *pps)
{
    return (*pps)->top >= MAXSTACK;
}

/*
 * Pre: The stack is initialized and not full
 * The user has to check before calling Push
 * Post: The element e has been stored at the top of the stack
 */
int Push(StackEntry e, PStack *pps)
{
    (*pps)->entry[(*pps)->top++] = e;
    return 1;
}

// int Push(void *, PStack *pps, int bytes)
// {
//     void *ptr = malloc(bytes);
//     if (!ptr)
//         return 0;
//     else
//     {
//         memcpy(ptr, pe, bytes);
//         (*pps)->entry[(*pps)->top] = ptr;
//         (*pps)->top++;
//         return 1;
//     }
// }

void CreateStack(PStack *pps)
{
    *pps = (Stack *)malloc(sizeof(Stack));
    (*pps)->top = 0; // is the index of the first available place in the stack
}

#endif
