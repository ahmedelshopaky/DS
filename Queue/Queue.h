#define ARRAY_BASED_QUEUE
#define MAXQUEUE 100
typedef int QueueEntry;

#ifdef ARRAY_BASED_QUEUE
typedef struct queue
{
    int front;
    int rear;
    int size;
    QueueEntry entry[MAXQUEUE];
} Queue;
#endif

void CreateQueue(Queue *);
void Append(QueueEntry, Queue *);
void Serve(QueueEntry *, Queue *);
int QueueEmpty(Queue *);
int QueueFull(Queue *);
int QueueSize(Queue *);
void ClearQueue(Queue *);
void TraverseQueue(Queue *, void (*)(QueueEntry));
