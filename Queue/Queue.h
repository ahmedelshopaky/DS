#include "../Global.h"
#define LINKED_BASED_QUEUE

#ifdef LINKED_BASED_QUEUE

typedef struct queuenode
{
    struct queuenode *next;
    QueueEntry entry;
} QueueNode;

typedef struct queue
{
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

#else

typedef struct queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
} Queue;

#endif

void CreateQueue(Queue *);
int Append(QueueEntry, Queue *);
void Serve(QueueEntry *, Queue *);
int QueueEmpty(Queue *);
int QueueFull(Queue *);
int QueueSize(Queue *);
void ClearQueue(Queue *);
void TraverseQueue(Queue *, void (*)(QueueEntry));
