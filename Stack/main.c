#include <stdio.h>
#include "Stack.h"

void Display(StackEntry e)
{
    printf("e is: %d\n", e);
}

void TestStack()
{
    StackEntry e;
    Stack s;
    CreateStack(&s);
    if (!StackFull(&s))
    {
        Push(100, &s);
        Push(200, &s);
        Push(300, &s);
    }
    printf("stack size is: %d\n", StackSize(&s));
    TraverseStack(&s, &Display);
    if (!StackEmpty(&s))
    {
        StackTop(&e, &s);
        printf("stack entry is: %d\n", e);
        Pop(&e, &s);
        printf("stack entry is: %d\n", e);
        Pop(&e, &s);
        printf("stack entry is: %d\n", e);
    }
    printf("stack size is: %d\n", StackSize(&s));
    ClearStack(&s);
    printf("stack size is: %d\n", StackSize(&s));
}

void ReverseRead()
{
    StackEntry item;
    Stack stack;
    CreateStack(&stack);
    while (!StackFull(&stack) && (item = getchar()) != '\n')
        Push(item, &stack);
    while (!StackEmpty(&stack))
    {
        Pop(&item, &stack);
        putchar(item);
    }
    putchar('\n');
}

/*
 * Stacks applications: Recursion
 * Towers of Hanoi
 * Pre: There is at least (count) disks on the tower (start).
 * The top disk on each of towers (temp) and (finish) is
 * larger than any of the top (count) disks on tower (start).
 * Post: The top (count) disks on (start) have been moved to (finish),
 * (temp) has been returned to its starting position.
 */
void MoveDisks(int count, int start, int finish, int temp)
{
    /*
     * No. of function calls = 2^count - 1
     * This step of printf is the base condition.
     */
    if (count > 0)
    {
        MoveDisks(count - 1, start, temp, finish);
        printf("Move disk %d from %d to %d\n", count, start, finish);
        MoveDisks(count - 1, temp, finish, start);
    }
}

int main()
{
    MoveDisks(64, 1, 3, 2);
    // TestStack();
    // ReverseRead();
    return 0;
}

/*
 * Information Hiding (Encapsulation)
 * WHAT - HOW
 * In the user level, I don't care about details at the implementation level
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
