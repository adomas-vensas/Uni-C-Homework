#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_ERROR_MEMALLOC      "Could not allocate memory to insert element.\n"
#define MSG_ERROR_BAD_INDEX     "Unidentified index.\n"

typedef struct Node{
    void *data;             //Holds data of the current node         
    struct Node *next;      //Points to the next node
}Node;

static inline void checkMemAlloc(char *msg, Node *ptr)
{
    if(!ptr){
        printf("%s"MSG_ERROR_MEMALLOC, msg);
        return;
    }
}

static inline void checkIndex(char *msg, int index)
{
    if(index < 1){
        printf("%s"MSG_ERROR_BAD_INDEX, msg);
        return;
    }
}

static inline void* checkIndexGEV(char *msg, int index)
{
    if(index < 1){
        printf("%s"MSG_ERROR_BAD_INDEX, msg);
        return NULL;
    }
}

void createList(Node **head)
{
    *head = NULL;           //Initialize empty linked list

    return;
}

void deleteList(Node **head)
{
    //Temporary variables for access to linked list
    Node *current = *head;
    Node *next;

    //Save address of the next node and delete the current one
    while (current != NULL)         
    {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;           //Signifies emptiness

    return;
}

void printList(Node **head, void (*callPrint)(void *))
{
    //Temporary variable for access to linked list
    Node *temp = *head;

    //Execute print[...] function to print the data type
    while(temp != NULL){
        (*callPrint)(temp -> data);
        temp = temp -> next;
    }

    //If head node != 0, than put newline symbol 
    *head ? printf("\n") : 0;

    return;
}

void insertElement(Node **head, int index, void *value, size_t value_size)
{
    checkIndex("InsertElement error. ", index);              //Check if index > 0

    //Temporary variables for access to linked list and its manipulation
    Node *temp1 = malloc(sizeof(Node));         
    Node *temp2 = *head;

    checkMemAlloc("InsertElement error. ", temp1);          //Check memory allocation status

    temp1 -> data = malloc(value_size);                     //Allocate memory of 'value_size' for the provided data type
    checkMemAlloc("InsertElement error. ", temp1 -> data);  //Check memory allocation status
    memcpy(temp1 -> data, value, value_size);               //Copy the 'value' byte by byte to the 'data'
    
    temp1 -> next = NULL;

    if(index == 1){                             //Corner case
        temp1 -> next = *head;
        *head = temp1;
        return;
    }


    for(int i = 0; i < (index - 2); ++i){       //Traverse the linked list
        temp2 = temp2 -> next;
    }
    temp1 -> next = temp2 -> next;              //Link up the new node with the linked list
    temp2 -> next = temp1;

    return;
}

void deleteElement(Node **head, int index)
{
    checkIndex("deleteElement error. ", index);              //Check if index > 0

    //Temporary variables for access to linked list
    Node *temp1 = *head;
    Node *temp2;

    if(index == 1){                         //Corner case
        *head = temp1 -> next;
        free(temp1);
        return;
    }

    for(int i = 0; i < (index - 2); ++i){   //Traverse the linked list
        temp1 = temp1 -> next;
    }
    temp2 = temp1 -> next;                  //Link up the seperated nodes
    temp1 -> next = temp2 -> next;

    free(temp2);
    return;
}

size_t getListSize(Node **head)
{
    Node *temp = *head;     //Temporary variable for counting
    size_t size = 0;        //Size of the linked list

    while(temp){
        temp = temp -> next;
        ++size;
    }

    return size;
}

void* getElementValue(Node **head, int index)
{
    checkIndexGEV("getElementValue error. ", index);              //Check if index > 0

    //Temporary variable for access to linked list
    Node *temp = *head;

    //While index > 0, traverse the list
    while(--index){
        temp = temp -> next;
    }

    return temp -> data;
}

//--------Print Functions----------//
void printShort(void *n)
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
