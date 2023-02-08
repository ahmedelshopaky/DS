#include "Global.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"

/*
 * backtracking algorithm (postponing the work):
 * eight queens puzzle
 */
void EightQueensPuzzle(void)
{
    //
}

/*
 * Polish Notation - Obvious Limitations:
 * 1. only single digit integers
 * 2. only positive integers
 * 3. no unary operators allowed.
 * 4. no brackets !!!
 * 5. no handling for invalid expr.
 *    - extra operators.
 *    - invalid ordering
 * 6. No characters allowed
 * HW: rewrite it to account for as much as limitations you can!
 * This can be your course project.
 * Hint: read Polish Notation, Ch.12.
 */
void InfixToPostfix(char infix[], char postfix[])
{
    //
}

double EvaluatePostfix(char expr[])
{
    //
}

/*
 * Sheet3: Queues
 */
void AddCustomer(Queue *pqueue)
{
    QueueEntry e;
    printf("ID: ");
    scanf("%d", &e.id);
    printf("Age: ");
    scanf("%d", &e.age);
    printf("Name: ");
    scanf("%s", &e.name);
    Append(e, pqueue);
}

void Display(QueueEntry e)
{
    printf("\nid is: %d\n", e.id);
    printf("age is: %d\n", e.age);
    printf("name is: %s\n\n", e.name);
}

int main()
{
    Queue queue;
    QueueEntry entry;
    CreateQueue(&queue);
    char input;
    printf("---------- Main Menu ----------\n1. Add a New Customer.\n2. Serve a Customer.\n3. How many Customers are waiting?\n4. Display Customers Information.\n5. Display Customers information in a 'most-recent' Order.\n6. Exit.\n-------------------------------\n");
    while (1)
    {
        printf(">> ");
        input = getchar();
        switch (input)
        {
        case '1':
            AddCustomer(&queue);
            break;
        case '2':
            Serve(&entry, &queue);
            Display(entry);
            break;
        case '3':
            printf("%d\n", QueueSize(&queue));
            break;
        case '4':
            TraverseQueue(&queue, &Display);
            break;
        case '5':
            /* code */
            break;
        default:
            break;;
        }
        getchar();
    }

    return 0;
}
