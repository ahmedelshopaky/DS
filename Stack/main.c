#include <stdio.h>
#include "Stack.h"

void Display(StackEntry e)
{
    printf("e is: %d\n", e);
}

int main()
{
    StackEntry e;
    Stack s;
    int x;
    CreateStack(&s);

    if (!StackFull(&s))
    {
        Push(100, &s);
    }
    if (!StackEmpty(&s))
    {
        StackTop(&e, &s);
        printf("e is: %d\n", e);
        Pop(&e, &s);
    }
    x = StackSize(&s);
    printf("x is: %d\n", x);
    ClearStack(&s);
    TraverseStack(&s, &Display);
    return 0;
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

/*
 * Information Hiding (Encapsulation)
 * WHAT - HOW
 * I am in the user level, I don't care about details at the implementation level
 *
 * Top-Down-Design !!!
 * The execution time, complexity, depends on n.!!!
 *
 * Stack: LIFO
 * Type: is a set of values and a set of operations on those values
 * Sequence: is...
 * ADT, Abstract Data Type: is a data type that is accessed only through an interface (or Accessing Mechanism)
 * Stack: is...
 */
