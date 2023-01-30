#include "Stack.h"

/*
 * Precondition: The stack is initialized
 */
void TraverseStack(Stack *ps, void (*pf)(StackEntry))
{
    for (int i = ps->top; i > 0; i--)
    {
        (*pf)(ps->entry[i - 1]);
    }
}

/*
 * Pre: The stack is initialized
 * Post: Destroy all elements, the stack looks initialized.
 */
void ClearStack(Stack *ps)
{
    ps->top = 0;
}

int StackSize(Stack *ps)
{
    return ps->top;
}

/*
 * Pre: The stack is initialized and not empty
 * Post: The last elemnet in the stack is returned without destroy it
 */
void StackTop(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[ps->top - 1];
}

int StackEmpty(Stack *ps)
{
    return !ps->top;
}

/*
 * Pre: The stack is initialized and not empty
 * Post: The last element entered is returned
 */
void Pop(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[--(ps->top)];
}

int StackFull(Stack *ps)
{
    return ps->top >= MAXSTACK;
}

/*
 * Pre: The stack is initialized and not full
 * The user has to check before calling Push
 * Post: The element e has been stored at the top of the stack
 */
void Push(StackEntry e, Stack *ps)
{
    ps->entry[ps->top++] = e;
}

// int Push(StackEntry e, Stack *ps)
// {
//     if (ps->top == MAXSTACK) return 0;
//     else
//     {
//         ps->entry[ps->top++] = e;
//         return 1;
//     }
// }

void CreateStack(Stack *ps)
{
    ps->top = 0; // is the index of the first available place in the stack
}

// void ReverseRead(void)
// {
//     StackEntry item;
//     Stack stack;
//     CreateStack(&stack);
//     while (!StackFull(&stack) && (item = getchar()) != '\n')
//         Push(item, &stack);
//     while (!StackEmpty(&stack))
//     {
//         Pop(&item, &stack);
//         putchar(item);
//     }
//     putchar('\n');
// }
