#include <stdlib.h>
#include "Queue.h"

#ifdef LINKED_BASED_QUEUE
void CreateQueue(Queue *pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->size = 0;
}

int Append(QueueEntry e, Queue *pq)
{
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    if (!pn)
        return 0;
    else
    {
        pn->next = NULL;
        pn->entry = e;
        if (!pq->rear)
            pq->front = pn;
        else
            pq->rear->next = pn;
        pq->rear = pn;
        pq->size++;
        return 1;
    }
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
#else

void CreateQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

int Append(QueueEntry e, Queue *pq)
{
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
    return 1;
}

void Serve(QueueEntry *pe, Queue *pq)
{
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}

int QueueEmpty(Queue *pq)
{
    return !pq->size;
}

int QueueFull(Queue *pq)
{
    return pq->size >= MAXQUEUE;
}

int QueueSize(Queue *pq)
{
    return pq->size;
}

void ClearQueue(Queue *pq)
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void TraverseQueue(Queue *pq, void (*pf)(QueueEntry))
{
    int pos, s;
    for (pos = pq->front, s = 0; s < pq->size; s++)
    {
        (*pf)(pq->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}
#endif
