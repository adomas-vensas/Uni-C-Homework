#ifndef SLLUTI_H_INCLUDED
#define SLLUTI_H_INCLUDED

#include "slluti.c"

typedef struct Node Node;

void createList(Node **head);
void deleteList(Node **head);
void printList(Node **head, void (*callPrint)(void *));
void insertElement(Node **head, int index, void *value, size_t value_size);
void deleteElement(Node **head, int index);
size_t getListSize(Node **head);
void* getElementValue(Node **head, int index);

#endif