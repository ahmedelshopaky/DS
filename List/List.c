#include <stdlib.h>
#include "List.h"

#ifdef DOUBLY_LINKED_LIST

void CreateList(List *pl)
{
    pl->current = NULL;
    pl->head = NULL;
    pl->tail = NULL;
    pl->size = 0;
    pl->currentpos = 0;
}

int ListSize(List *pl)
{
    return pl->size;
}

int ListFull(List *pl)
{
    return 0;
}

int ListEmpty(List *pl)
{
    return !pl->size;
}

void DestroyList(List *pl)
{
    while (pl->size)
    {
        pl->current = pl->head->next;
        free(pl->head);
        pl->head = pl->current;
        pl->size--;
    }
    pl->tail = pl->head = pl->current = NULL;
    pl->currentpos = 0;
}

int InsertList(int pos, ListEntry e, List *pl)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    if (temp)
    {
        temp->entry = e;
        temp->next = NULL;
        temp->prev = NULL;

        if (pos == 0)
        {

            if (pl->head)
            {
                pl->head->prev = pl->tail->next = temp;
                temp->prev = pl->tail;
                temp->next = pl->head;
            }
            else
                pl->head = pl->tail = temp->next = temp->prev = temp;
            pl->head = temp;
            pl->current = temp;
            pl->currentpos = 0;
        }
        else
        {
            if (pos <= pl->currentpos)
                for (; pl->currentpos != pos - 1; pl->currentpos--)
                    pl->current = pl->current->prev;
            else
                for (; pl->currentpos != pos - 1; pl->currentpos++)
                    pl->current = pl->current->next;
            temp->next = pl->current->next;
            temp->prev = pl->current;
            pl->current->next->prev = temp;
            pl->current->next = temp;
            pl->current = temp;
            pl->currentpos = pos;
            if (pos == pl->size)
                pl->tail = temp;
        }
        pl->size++;
        return 1;
    }
    else
        return 0;
}

void DeleteList(int pos, ListEntry *e, List *pl)
{
    if (pos == 0)
    {
        pl->current = pl->head->next;
        pl->currentpos = 0;
        *e = pl->head->entry;
        free(pl->head);
        pl->head = pl->current;
        pl->current->prev = pl->tail;
        pl->tail->next = pl->current;
    }
    else if (pos == pl->size - 1)
    {
        pl->current = pl->tail->prev;
        pl->currentpos = pos - 1;
        *e = pl->tail->entry;
        free(pl->tail);
        pl->tail = pl->current;
        pl->current->next = pl->head;
        pl->head->prev = pl->current;
    }
    else
    {
        if (pos > pl->currentpos)
            for (; pl->currentpos != pos; pl->currentpos++)
                pl->current = pl->current->next;
        else
            for (; pl->currentpos != pos; pl->currentpos--)
                pl->current = pl->current->prev;
        free(pl->current);
    }
    pl->size--;
}

void RetrieveList(int pos, ListEntry *e, List *pl)
{
    if (pos == 0)
        *e = pl->head->entry;
    else if (pos == pl->size - 1)
        *e = pl->tail->entry;
    else
    {
        if (pos > pl->currentpos)
            for (; pl->currentpos != pos; pl->currentpos++)
                pl->current = pl->current->next;
        else
            for (; pl->currentpos != pos; pl->currentpos--)
                pl->current = pl->current->prev;
        *e = pl->current->entry;
    }
}

void ReplaceList(int pos, ListEntry e, List *pl)
{
    if (pos == 0)
        pl->head->entry = e;
    else if (pos == pl->size - 1)
        pl->tail->entry = e;
    else
    {
        if (pos > pl->currentpos)
            for (; pl->currentpos != pos; pl->currentpos++)
                pl->current = pl->current->next;
        else
            for (; pl->currentpos != pos; pl->currentpos--)
                pl->current = pl->current->prev;
        pl->current->entry = e;
    }
}

void TraverseList(List *pl, void (*pf)(ListEntry))
{
    ListNode *temp;
    int i;
    for (temp = pl->head, i = 0; i < pl->size; temp = temp->next, i++)
        (*pf)(temp->entry);
}
#endif

#ifdef LINKED_BASED_LIST
void CreateList(List *pl)
{
    pl->head = NULL;
    pl->size = 0;
    pl->currentpos = 0;
    pl->current = NULL;
} // ϴ(1)

int ListSize(List *pl)
{
    return pl->size;
} // ϴ(1)

int ListFull(List *pl)
{
    return 0;
} // ϴ(1)

int ListEmpty(List *pl)
{
    return !pl->head;
} // ϴ(1)

void DestroyList(List *pl)
{
    while (pl->head)
    {
        pl->current = pl->head->next;
        free(pl->head);
        pl->head = pl->current;
    }
    pl->currentpos = 0;
    pl->current = NULL;
    pl->size = 0;
} // ϴ(N)

int InsertList(int pos, ListEntry e, List *pl)
{
    ListNode *temp;
    if (temp = (ListNode *)malloc(sizeof(ListNode)))
    {
        temp->entry = e;
        temp->next = NULL;

        if (pos == 0)
        {
            temp->next = pl->head;
            pl->head = temp;
            pl->currentpos = 0;
            pl->current = pl->head;
        }
        else
        {
            if (pos <= pl->currentpos)
            {
                pl->current = pl->head;
                pl->currentpos = 0;
            }
            for (; pl->currentpos != pos - 1; pl->currentpos++)
                pl->current = pl->current->next;
            temp->next = pl->current->next;
            pl->current->next = temp;
        }
        pl->size++;
        return 1;
    }
    else
        return 0;
} // ϴ(N) But without shifting elements

void DeleteList(int pos, ListEntry *pe, List *pl)
{
    ListNode *temp;
    if (pos == 0)
    {
        *pe = pl->head->entry;
        pl->current = pl->head->next;
        free(pl->head);
        pl->head = pl->current;
        pl->currentpos = 0;
    }
    else
    {
        if (pos <= pl->currentpos)
        {
            pl->current = pl->head;
            pl->currentpos = 0;
        }
        for (; pl->currentpos != pos - 1; pl->currentpos++)
            pl->current = pl->current->next;
        *pe = pl->current->next->entry;
        temp = pl->current->next->next;
        free(pl->current->next);
        pl->current->next = temp;
    }
    pl->size--;
} // ϴ(N) But without shifting elements

void RetrieveList(int pos, ListEntry *pe, List *pl)
{
    if (pos <= pl->currentpos)
    {
        pl->current = pl->head;
        pl->currentpos = 0;
    }
    for (; pl->currentpos != pos; pl->currentpos++)
        pl->current = pl->current->next;
    *pe = pl->current->entry;
} // ϴ(N)

void ReplaceList(int pos, ListEntry e, List *pl)
{
    // ListNode *temp;
    // int i;
    // for (temp = pl->head, i = 0; i < pos; i++)
    //     temp = temp->next;
    // temp->entry = e;
    if (pos <= pl->currentpos)
    {
        pl->current = pl->head;
        pl->currentpos = 0;
    }
    for (; pl->currentpos != pos; pl->currentpos++)
        pl->current = pl->current->next;
    pl->current->entry = e;
} // ϴ(N)

void TraverseList(List *pl, void (*pf)(ListEntry))
{
    ListNode *p;
    p = pl->head;
    while (p)
    {
        (*pf)(p->entry);
        p = p->next;
    }

} // ϴ(N)
#endif

#ifdef ARRAY_BASED_LIST
void CreateList(List *pl)
{
    pl->size = 0;
} // ϴ(1)

int ListSize(List *pl)
{
    return pl->size;
} // ϴ(1)

int ListFull(List *pl)
{
    return pl->size >= MAXLIST;
} // ϴ(1)

int ListEmpty(List *pl)
{
    return !pl->size;
} // ϴ(1)

void DestroyList(List *pl)
{
    pl->size = 0;
} // ϴ(1)

void TraverseList(List *pl, void (*pf)(ListEntry))
{
    for (int i = 0; i < pl->size; i++)
        (*pf)(pl->entry[i]);
} // ϴ(N)

/*
 * Precondition: 0 <= p <= size, list is not full and has been created
 * Postcondition: The element e has been inserted at position p,
 * all ements at old positions p, p+1, ..., size-1 are incremented by 1
 * and the size increases by 1
 */
int InsertList(int p, ListEntry e, List *pl)
{
    /*
     * The loop shifts up all of the elements in the
     * range [p, size-1] to free the pth location
     */
    for (int i = pl->size - 1; i >= p; i--)
        pl->entry[i + 1] = pl->entry[i];
    pl->entry[p] = e;
    pl->size++;
    return 1;
} // ϴ(N)

/*
 * Precondition: 0 <= p <= size-1, list is not empty and has been created
 * Postcondition: The element e has been retrieved from position p,
 * all ements at old positions p+1, ..., size-1 are decremented by 1
 * and the size decreases by 1
 */
void DeleteList(int p, ListEntry *pe, List *pl)
{
    *pe = pl->entry[p];
    /*
     * The loop shifts down all of the elements in the
     * range [p+1, size-1] to free the pth location
     */
    for (int i = p + 1; i <= pl->size - 1; i++)
        pl->entry[i - 1] = pl->entry[i];
    pl->size--;
} // ϴ(N)

/*
 * Pre: 0 =< p <= size-1
 */
void RetrieveList(int p, ListEntry *pe, List *pl)
{
    *pe = pl->entry[p];
} // ϴ(1)

/*
 * Pre: 0 =< p <= size-1
 */
void ReplaceList(int p, ListEntry e, List *pl)
{
    pl->entry[p] = e;
} // ϴ(1)
#endif
