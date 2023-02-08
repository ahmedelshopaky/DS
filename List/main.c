#include "List.h"

/*
 * Search and Analysis of Algorithms
 * Pre: list is created
 * Post: Return the location if element exists.
 * Otherwise, return -1.
 * This code is implementation-independent
 * Complexity: ϴ(N)
 * The best case: The element is in the first position,
 * so the number of comparisons is 1.
 * The worst case: The number of comparisons is n.
 * Unsuccessful search takes n comparisons.
 */
int SequentialSearch(KeyType target, List *pl)
{
    int current, s = ListSize(pl);
    ListEntry currententry;
    for (current = 0; current < s; current++)
    {
        RetrieveList(current, &currententry, pl);
        if (EQ(currententry.key, target))
            return current;
    }
    return -1;
}

/*
 * Pre: created, not full and ordered.
 * Post: e is inserted in order. If the new element has a key equal
 * to an element in the list it will be inserted before it.
 */
void InsertOrder(ListEntry e, List *pl)
{
    int current, s = ListSize(pl);
    ListEntry currententry;
    for (current = 0; current < s; current++)
    {
        RetrieveList(current, &currententry, pl);
        if (LE(e.key, currententry.key))
            break;
    }
    InsertList(current, e, pl);
}

#ifdef ARRAY_BASED_LIST
/*
 * Binary2Search
 * Middle = f + floor((n - 1) / 2)
 * f: First Index, n: List Size.
 * LT Elements = ceiling((n - 1) / 2)
 * RT Elements = floor((n - 1) / 2)
 */
int RecBinary2(List *pl, KeyType k, int bottom, int top)
{
    /*
     * recursive algorithm
     */
    int middle;
    ListEntry e;
    if (middle <= top)
    {
        middle = (bottom + top) / 2;
        if (GT(k, pl->entry[middle].key))
            RecBinary2(pl, k, middle + 1, top);
        else if (LT(k, pl->entry[middle].key))
            RecBinary2(pl, k, bottom, middle - 1);
        else
            return middle;
    }
    return -1; // Base Condition
}

int Binary2Search(List *pl, KeyType k, int bottom, int top)
{
    /*
     * iterative algorithm
     */
    int middle;
    ListEntry e;
    while (middle <= top)
    {
        middle = (bottom + top) / 2;
        if (GT(k, pl->entry[middle].key))
            bottom = middle + 1;
        else if (LT(k, pl->entry[middle].key))
            top = middle - 1;
        else
            return middle;
    }
    return -1;
}

int RecBinary2Search(KeyType target, List *pl)
{
    // return RecBinary2(pl, target, 0, ListSize(pl) - 1);
    return Binary2Search(pl, target, 0, ListSize(pl) - 1);
}
#endif

/*
 * TestList
 */
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
        // InsertList(0, 0, &l);
        // InsertList(1, 3, &l);
        // InsertList(2, 4, &l);
        // InsertList(3, 5, &l);
        // InsertList(4, 6, &l);
        // InsertList(1, 1, &l);
        // InsertList(2, 2, &l);
    }
    printf("list size is: %d\n", ListSize(&l));
    TraverseList(&l, &Display);
    if (!ListEmpty(&l))
    {
        RetrieveList(0, &e, &l);
        printf("retrieve list entry 0: %d\n", e);
        // ReplaceList(2, 9, &l);
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
}

int main()
{
    TestList();
    return 0;
}
