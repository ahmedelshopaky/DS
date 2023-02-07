#include <stdio.h>
#include "List.h"

void Display(ListEntry e)
{
    printf("e is: %d\n", e);
}

void TestList()
{
    ListEntry e;
    List l;
    CreateList(&l);
    if (!ListFull(&l))
    {
        InsertList(0, 0, &l);
        InsertList(1, 3, &l);
        InsertList(2, 4, &l);
        InsertList(3, 5, &l);
        InsertList(4, 6, &l);
        InsertList(1, 1, &l);
        InsertList(2, 2, &l);
    }
    printf("list size is: %d\n", ListSize(&l));
    TraverseList(&l, &Display);
    if (!ListEmpty(&l))
    {
        RetrieveList(0, &e, &l);
        printf("retrieve list entry 0: %d\n", e);
        ReplaceList(2, 9, &l);
        RetrieveList(2, &e, &l);
        printf("retrieve list entry 2: %d\n", e);
        DeleteList(0, &e, &l);
        printf("delete list entry 0: %d\n", e);
        DeleteList(5, &e, &l);
        printf("delete list entry 5: %d\n", e);
    }
    TraverseList(&l, &Display);
    printf("list size is: %d\n", ListSize(&l));
    DestroyList(&l);
    printf("list size is: %d\n", ListSize(&l));
    TraverseList(&l, &Display);

    // printf("\nhead: %d\n", l.head->entry);
    // printf("tail: %d\n", l.tail->entry);
    // printf("current: %d\n", l.current->entry);
    // printf("pos: %d\n\n", l.currentpos);
}

int main()
{
    TestList();
    return 0;
}
