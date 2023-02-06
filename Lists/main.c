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
        InsertList(0, 10, &l);
        InsertList(1, 20, &l);
        InsertList(2, 30, &l);
    }
    printf("list size is: %d\n", ListSize(&l));
    TraverseList(&l, &Display);
    if (!ListEmpty(&l))
    {
        DeleteList(2, &e, &l);
        printf("list entry is: %d\n", e);
        DeleteList(0, &e, &l);
        printf("list entry is: %d\n", e);
    }
    printf("list size is: %d\n", ListSize(&l));
    TraverseList(&l, &Display);
    DestroyList(&l);
    printf("list size is: %d\n", ListSize(&l));
}

int main()
{
    TestList();
    return 0;
}
