#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ADDRESS_LENGTH 10
#define MAX_AMOUNT_LISTS 100

#define MSG_ERROR_NO_LIST "Variable not initialized as an empty Linked list.\n"
#define MSG_ERROR_LIST_EXISTS "Variable has already been initialized as an empty Linked list.\n"
#define MSG_ERROR_MAX_LIST_AMOUNT "Max Limit of a 100 linked lists reached in program.\n"

//TODO: 
//visur error zinutės sutvarkytos
//paziuret ar visur tenkinami corner cases
//paziurėt ar deleteElement veikia gerai
//parasyt deleteList funkciją

char dictionary[MAX_AMOUNT_LISTS][MAX_ADDRESS_LENGTH] = {{0}};

typedef struct Node{
    void *data;
    struct Node *next;
}Node;

unsigned checkInitialization(Node **head)
{
    char var[MAX_ADDRESS_LENGTH];
    unsigned short i = 0;

    sprintf(var, "%s", head);

    while(dictionary[i][0] && i < 100){
        if(strcmp(dictionary[i], var) == 0){
            return 0;
        }
        ++i;
    }

    printf("No initialized linked list found.\n");
    return 1;
}

void createList(Node **head)
{
    char var[MAX_ADDRESS_LENGTH];

    sprintf(var, "%s", head);

    unsigned short i = 0;
    while(dictionary[i][0] && i < 100){
        if(strcmp(dictionary[i], var) == 0){
            printf(MSG_ERROR_LIST_EXISTS);
            return;
        }
        ++i;
    }
    
    if(i == 100){
        printf(MSG_ERROR_MAX_LIST_AMOUNT);
        return;
    }

    *head = NULL;                       //Initialize empty linked list
    
    unsigned short k = 0;

    while(strcmp(dictionary[k], "#") != 0 && k < i){
        ++k;
    }
    (k == 100) ? --k : 0;
    strcpy(dictionary[k], var);         //Save new empty list address in dictionary

    return;
}

size_t getListSize(Node **head)
{
    if(checkInitialization(head)){
        return -1;
    }

    Node *temp = *head;
    size_t size = 0;

    while(temp){
        temp = temp -> next;
        ++size;
    }

    return size;
}

void insertElement(Node **head, int index, void *value, size_t value_size)
{
    if(checkInitialization(head)){
        return;
    } else if(getListSize(head) < (index - 1) || index < 1){
        printf("insertElement error. Improper index (List size: %d, Index: %d)\n", getListSize(head), index);
        return;
    }

    Node *temp1 = malloc(sizeof(Node));
    Node *temp2 = *head;

    temp1 -> data = malloc(value_size);
    memcpy(temp1->data, value, value_size);
    temp1 -> next = NULL;

    if(index == 1){
        temp1 -> next = *head;
        *head = temp1;
        return;
    }


    for(int i = 0; i < (index - 2); ++i){
        temp2 = temp2 -> next;
    }
    temp1 -> next = temp2 -> next;
    temp2 -> next = temp1;

    return;
}

void deleteElement(Node **head, int index)
{
    if(checkInitialization(head)){
        return;
    } else if((getListSize(head) < (index - 1) || index < 1)){
        printf("deleteElement error. Improper index (List size: %d)\n", getListSize(head));
        return;
    }

    Node *temp1 = *head;
    Node *temp2 = *head;

    if(index > 0){
        while((index - 1 > 0) && (temp1 != NULL)){
            temp1 = temp1 -> next;
            --index;
        }
        temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;

    } else {
        *head = temp2 -> next;
    }

    free(temp2);
    return;
}

void deleteList(Node **head)
{
    if(checkInitialization(head)){
        return;
    }

    Node *current = *head;
    Node *next;
    char var[MAX_ADDRESS_LENGTH];

    sprintf(var, "%d", head);

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    unsigned short i = 0;
    while(dictionary[i][0] && i < 100){
        if(strcmp(dictionary[i], var) == 0){
            strcpy(dictionary[i], "#");
            break;
        }
        ++i;
    }

    *head = NULL;

    return; 
}

void* getElementValue(Node **head, int index)
{
    if(checkInitialization(head) || (getListSize(head) < (index - 1)) || index < 1){
        printf("getElementValue error. Improper index (List size: %d, Index: %d)\n", getListSize(head), index);
        return NULL;
    }

    Node *temp = *head;

    while(--index){
        temp = temp -> next;
    }

    return temp -> data;
} 

void reverseList(Node **head)
{
    if(checkInitialization(head)){
        return;
    }

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

void printList(Node **head, void (*callPrint)(void *))
{
    if(checkInitialization(head)){
        return;
    }

    Node *temp = *head;

    while(temp != NULL){
        (*callPrint)(temp -> data);
        temp = temp -> next;
    }

    return;
}

//--------Print Functions----------//
void printShortInt(void *n)
{
    printf("%hd ", *(short *)n);
    return;
}

void printUnShort(void *n)
{
    printf("%hu ", *(unsigned short *)n);
    return;
}

void printUnInt(void *n)
{
    printf("%u ", *(unsigned *)n);
    return;
}

void printInt(void *n)
{
    printf("%d ", *(int *)n);
    return;
}

void printLong(void *n)
{
    printf("%ld ", *(long *)n);
    return;
}

void printUnLong(void *n)
{
    printf("%lu ", *(unsigned long *)n);
    return;
}

void printLongLong(void *n)
{
    printf("%lld ", *(long long *)n);
    return;
}

void printUnLongLong(void *n)
{
    printf("%llu ", *(unsigned long long *)n);
    return;
}

void printChar(void *n)
{
    printf("%c ", *(char *)n);
    return;
}

void printUnChar(void *n)
{
    printf("%c ", *(unsigned char *)n);
    return;
}

void printFloat(void *n)
{
    printf("%f ", *(float *)n);
    return;
}

void printDouble(void *n)
{
    printf("%lf ", *(double *)n);
    return;
}

void printLongDouble(void *n)
{
    printf("%Lf ", *(long double *)n);
    return;
}

void printString(void *n)
{
    printf("%s ", (char *)n);
    return;
}

int main()
{
    Node *head;
    Node *jeff;
    Node *num1, *num2, *num3;
    double h = 10, j = 9, k = 8;

    // createList(&jeff);
    // createList(&jeff);
    createList(&head);
    // createList(&head);



    // printf("%d", &head);
    // printf("%p", head -> value);
    insertElement(&head, 1, &h, sizeof(double));
    // insertElement(&head, 1, &j, sizeof(double));
    // insertElement(&head, 2, &k, sizeof(double));

    // insertElement(&head, 3, &h, sizeof(int));
    // insertElement(&head, 4, &h, sizeof(int));

    // k = *((double *)getElementValue(&head, 3));
    // insertElement(&head, 2, "Gyvenimas be ribu", 18 * sizeof(char));
    // createList(&head);
    // deleteList(&head);
    // createList(&head);

    // insertElement(&head, 10, 2);

    // createList(&head);
    // // insertElement(&head, 20, 1);
    // // deleteElement(&head, 0);
    // printf("List size: %u\n", getListSize(&head));
    // // printf("%d", getElementValue(&head, 0));

    // printList(jeff);
    // reverseList(&head);
    printList(&head, printDouble);




    return EXIT_SUCCESS;
}