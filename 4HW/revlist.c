#include <stdio.h>
#include <stdlib.h>
#include "slltool.h"

void reverseList(Node **head)
{
    Node *previous, *current, *following; //corresponding to nodes of a linked list

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