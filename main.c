#include <stdio.h>
#include "Global.h"
#include "Stack/Stack.h"
#include "Queue/Queue.h"

int main()
{
    char input;
    printf("\
    ---------- Main Menu ----------\n\
    1. Add a New Customer.\n\
    2. Serve a Customer.\n\
    3. How many Customers are waiting?\n\
    4. Display Customers Information.\n\
    5. Display Customers information in a “most-recent” Order.\n\
    6. Exit.\n\
    -------------------------------\n>> ");
    scanf("%c", &input);
    switch (input)
    {
    case '1':
        /* code */
        break;
    case '2':
        /* code */
        break;
    case '3':
        /* code */
        break;
    case '4':
        /* code */
        break;
    case '5':
        /* code */
        break;
    default:
        break;
    }
    return 0;
}
