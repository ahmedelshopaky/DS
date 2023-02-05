#include <stdio.h>
#include "Queue.h"

void Display(QueueEntry e)
{
    printf("e is: %d\n", e);
}

void TestQueue()
{
    QueueEntry e;
    Queue q;
    CreateQueue(&q);
    if (!QueueFull(&q))
    {
        Append(10, &q);
        Append(20, &q);
        Append(30, &q);
    }
    printf("queue size is: %d\n", QueueSize(&q));
    TraverseQueue(&q, &Display);
    if (!QueueEmpty(&q))
    {
        Serve(&e, &q);
        printf("queue entry is: %d\n", e);
        Serve(&e, &q);
        printf("queue entry is: %d\n", e);
    }
    printf("queue size is: %d\n", QueueSize(&q));
    ClearQueue(&q);
    printf("queue size is: %d\n", QueueSize(&q));
}

/*
 * Queue: FIFO
 * Array Implementation 1: Physical Model (One index, rear)
 * Array Implementation 2: Linear Model (Two indecies, front and rear
 * Array Implementation 3: Circular Implementation
 */
int main()
{
    TestQueue();
    return 0;
}
