#include <stdio.h>
#include "Global.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"

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
