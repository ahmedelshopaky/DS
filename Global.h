#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXELEMENTS 100

#define OPERAND 0
#define OPERATOR 1

typedef int KeyType;

#ifdef STR_CMP
#define EQ(a, b) (!strcmp((a), (b)))
#define LT(a, b) (strcmp((a), (b)) < 0)
#define LE(a, b) (strcmp((a), (b)) <= 0)
#define GT(a, b) (strcmp((a), (b)) > 0)
#define GE(a, b) (strcmp((a), (b)) >= 0)
#else
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LE(a, b) ((a) <= (b))
#define GT(a, b) ((a) > (b))
#define GE(a, b) ((a) >= (b))
#endif

typedef struct customer
{
    int id;
    int age;
    char name[];
} Customer;

typedef struct elementtype
{
    char etype;
    int esize;
    KeyType key;
    union
    {
        char operator;
        double operand;
    } info;

} ElemenType;

/*
void main()
{
    Stack s;
    ElementType e;
    Pop(&e, &s);
    switch (e.etype)
    {
    case OPERATOR:
        e.info.operator ...
        break;
    case OPERAND:
        e.info.operand ...
        break;

    default:
        break;
    }
    ...
}
*/

typedef Customer QueueEntry;
#define MAXQUEUE MAXELEMENTS

typedef ElemenType StackEntry;
#define MAXSTACK MAXELEMENTS

typedef ElemenType ListEntry;
#define MAXLIST MAXELEMENTS

#endif
