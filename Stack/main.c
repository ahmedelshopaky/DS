#include <math.h>
#include <stdio.h>
#include "Stack.h"

#define POWER '^'
#define MUL '*'
#define DIV '/'
#define PLUS '+'
#define MINUS '-'

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
        Push(10, &s);
        Push(20, &s);
        Push(30, &s);
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
        /*
         * Tail Recursion: Last statement in a function is a call to itself
         */
        MoveDisks(count - 1, start, temp, finish);
        printf("Move disk %d from %d to %d\n", count, start, finish);
        MoveDisks(count - 1, temp, finish, start);
    }
}

/*
 * Removing Tail Recursion, To reduce stack consumption
 */
void Move(int count, int start, int finish, int temp)
{
    int swap;
    while (count > 0)
    {
        MoveDisks(count - 1, start, temp, finish);
        printf("Move disk %d from %d to %d\n", count, start, finish);
        count--;
        swap = start;
        start = temp;
        temp = swap;
    }
}

double Factorial(int n)
{
    /*
     * recursive algorithm
     * Complexity is ϴ(N)
     */
    return n == 0
               ? 1
               : n * Factorial(n - 1);

    /*
     * iterative algorithm
     * Complexity is ϴ(N)
     */
    double product;
    for (product = 1; n >= 1; n--)
        product *= n;
    return product;
    // int count;
    // double product;
    // for (count = 2, product = 1; count <= n; count++)
    //     product *= count;
    // return product;
}

/*
 * Given a number n, print n-th Fibonacci Number.
 */
double Fibonacci(int n)
{
    /*
     * iterative algorithm
     * Complexity is ϴ(N)
     */
    int oneback, twoback, current;
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        oneback = 1;
        twoback = 0;
        for (int i = 2; i <= n; i++)
        {
            current = oneback + twoback;
            twoback = oneback;
            oneback = current;
        }
        return current;
    }

    /*
     * recursive algorithm
     * Complexity is ϴ(C^N)
     */
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int IsDigit(char c)
{
    return c >= '0' && c <= '9';
}

int Presedent(char op1, char op2)
{
    if (op1 == POWER)
        return 1;
    if (op1 == MUL || op1 == DIV)
        return op2 != POWER;
    if (op1 == PLUS || op1 == MINUS)
        return op2 != POWER && op2 != MUL && op2 != DIV;
}

/*
 * Polish Notaion.
 * --- Example ---
 * - Prefix:  +ab
 * - Infix:   a+b
 * - Postfix: ab+
 */
void InfixToPostfix(char infix[], char postfix[])
{
    int i, j;
    char c, op;
    Stack s;
    CreateStack(&s);
    for (i = 0, j = 0; (c = infix[i]) != '\0'; i++)
        if (IsDigit(c))
            postfix[j++] = c;
        else
        {
            if (!StackEmpty(&s))
            {
                StackTop(&op, &s);
                while (!StackEmpty(&s) && Presedent(op, c))
                {
                    Pop(&op, &s);
                    postfix[j++] = op;
                    if (!StackEmpty(&s))
                        StackTop(&op, &s);
                }
            }
            Push(c, &s);
        }
    while (!StackEmpty(&s))
    {
        Pop(&op, &s);
        postfix[j++] = op;
    }
    postfix[j] = '\0';
}

double Oper(char c, double op1, double op2)
{
    switch (c)
    {
    case POWER:
        return pow(op1, op2);
    case PLUS:
        return op1 + op2;
    case MINUS:
        return op1 - op2;
    case MUL:
        return op1 * op2;
    case DIV:
        return op1 / op2;
    }
}

// double EvaluatePostfix(char expr[])
// {
//     char c;
//     Stack s;
//     double op1, op2, val;
//     for (int i = 0; (c = expr[i]) != '\0'; i++)
//         if (IsDigit(c))
//             Push((double)(c - '0'), &s);
//         else
//         {
//             Pop(&op2, &s);
//             Pop(&op1, &s);
//             val = Oper(c, op1, op2);
//             // printf("%.2f %c %.2f = %.2f\n", op1, c, op2, val);
//             Push(val, &s);
//         }
//     Pop(&val, &s);
//     return val;
// }

int main()
{
    // char infix[] = "1+2*3^4/5+6";
    // char postfix[sizeof(infix)];
    // InfixToPostfix(infix, postfix);
    // printf("%s\n", postfix);

    // printf("%.2f\n", EvaluatePostfix("1234^*5/+6+"));
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
