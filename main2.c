#include <stdio.h>
#include <stdlib.h>
#include "slluti.h"
#include "revlist.h"
#include "product.h"


//TODO
//Padaryt, kad slluti.h veiktų su struct'u šitu

int main()
{
    Node *head;
    Product *cart;
    char name[5][20] = {
        "Apples",
        "Beef",
        "Intel CPU i5",
        "Perfume",
        "Keyboard",
    };
    double pricePerItem[5] = {0.1, 3.5, 50.0, 49.99, 84.99};
    int amount = {10, 2, 1, 1, 2};


    createList(&head);

    for(int i = 0; i < 5; ++i){
        insertElement(&head, i, &i, sizeof(int));
    }

    printList(&head, printInt);
    reverseList(&head);
    printList(&head, printInt);

    return EXIT_SUCCESS;
}