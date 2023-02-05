#ifndef GLOBAL_H
#define GLOBAL_H

#define MAXELEMENTS 100
typedef struct elementtype
{
    int year;
    float age;
    int tmp;
} ElementType;

typedef int QueueEntry;
#define MAXQUEUE MAXELEMENTS

typedef char StackEntry;
#define MAXSTACK MAXELEMENTS

#endif
