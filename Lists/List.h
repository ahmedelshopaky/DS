#include "../Global.h"
#define DOUBLY_LINKED_BASED_LIST

#ifdef DOUBLY_LINKED_BASED_LIST
typedef struct listnode
{
    struct listnode *next, *prev;
    ListEntry entry;
} ListNode;

typedef struct list
{
    ListNode *current, *head, *tail;
    int size, currentpos;
} List;
#endif

#ifdef LINKED_BASED_LIST
typedef struct listnode
{
    struct listnode *next;
    ListEntry entry;
} ListNode;

typedef struct list
{
    ListNode *head;
    int size;
    ListNode *current;
    int currentpos;
} List;
#endif

#ifdef ARRAY_BASED_LIST
typedef struct list
{
    ListEntry entry[MAXLIST];
    int size;
    // int currentpos;
} List;
#endif

void CreateList(List *);
int ListSize(List *);
int ListFull(List *);
int ListEmpty(List *);
void DestroyList(List *);
int InsertList(int, ListEntry, List *);
void DeleteList(int, ListEntry *, List *);
void RetrieveList(int, ListEntry *, List *);
void ReplaceList(int, ListEntry, List *);
void TraverseList(List *, void (*)(ListEntry));
