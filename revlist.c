#include <stdio.h>
#include <stdlib.h>
#include "slluti.h"

void reverseList(Node **head)
{
    Node *previous, *current, *following;

    current = *head;
    previous = NULL;

    while(current != NULL){
        following = current -> next;
        current -> next = previous;
        previous = current;
        current = following;
    }
    *head = previous;

    return;
}