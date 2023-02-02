#include <stdlib.h>
#include "../Queue.h"

void CreateQueue(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

void Append(QueueEntry e, Queue *pq)
{
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    pn->next = NULL;
    pn->entry = e;
    if (!pq->rear)
        pq->front = pn;
    else
        pq->rear->next = pn;
    pq->rear = pn;
    pq->size++;
}

void Serve(QueueEntry *pe, Queue *pq)
{
    QueueNode *pn = pq->front;
    *pe = pn->entry;
    pq->front = pn->next;
    free(pn);
    if (!pq->front)
        pq->rear = NULL;
    pq->size--;
}

int QueueEmpty(Queue *pq)
{
    return !pq->front;
}

int QueueFull(Queue *pq)
{
    return 0;
}

int QueueSize(Queue *pq)
{
    return pq->size;
}

void ClearQueue(Queue *pq)
{
    while (pq->front)
    {
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }

    pq->size = 0;
}

void TraverseQueue(Queue *pq, void (*pf)(QueueEntry))
{
    for (QueueNode *pn = pq->front; pn; pn = pn->next)
        (*pf)(pn->entry);
}
