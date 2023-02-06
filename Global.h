#ifndef GLOBAL_H
#define GLOBAL_H

#define MAXELEMENTS 100
typedef struct customer
{
    int id;
    int age;
    char name[];
} Customer;

typedef Customer QueueEntry;
#define MAXQUEUE MAXELEMENTS

typedef Customer StackEntry;
#define MAXSTACK MAXELEMENTS

typedef int ListEntry;
#define MAXLIST MAXELEMENTS

#endif
