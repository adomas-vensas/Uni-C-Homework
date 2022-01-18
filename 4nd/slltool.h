#ifndef SLLTOOL_H_INCLUDED
#define SLLTOOL_H_INCLUDED

#include <stddef.h>

typedef struct Node{
    void *data;
    struct Node *next;
}Node;

void createList(Node **head);
void deleteList(Node **head);
void printList(Node **head, void (*callPrint)(void *));
void insertElement(Node **head, int index, void *value, size_t value_size);
void deleteElement(Node **head, int index);
size_t getListSize(Node **head);
void* getElementValue(Node **head, int index);

void printShort(void *n);
void printUnShort(void *n);
void printUnInt(void *n);
void printInt(void *n);
void printLong(void *n);
void printUnLong(void *n);
void printLongLong(void *n);
void printUnLongLong(void *n);
void printChar(void *n);
void printUnChar(void *n);
void printFloat(void *n);
void printDouble(void *n);
void printLongDouble(void *n);
void printString(void *n);


#endif /*SLLTOOL_H INCLUDED */