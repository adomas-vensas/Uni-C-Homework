//    Author: Adomas Vensas
//    Student's ID: 2110644
//    E-mail: adomasve@gmail.com
//    Assignment's nr.: 7
//    Program's purpose:
//        The program is for providing unit tests for the 'slltool.o' module.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "slltool.h"

int unitTesting_createList()
{
    Node *head = (Node *) 1000;

    createList(&head);

    if(head != NULL){
        deleteList(&head);
        return EXIT_FAILURE;
    }
    deleteList(&head);  
    return EXIT_SUCCESS;
}

int unitTesting_DeleteList_1()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < 10; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }
    deleteList(&head);

    if(getListSize(&head) || head != NULL){
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int unitTesting_DeleteList_2()
{
    Node *head;
    int i = 10;

    createList(&head);
    insertElement(&head, 1, &i, sizeof(int));
    deleteList(&head);

    if(getListSize(&head) || head != NULL){
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;

}

int unitTesting_DeleteList_3()
{
    Node *head;

    createList(&head);
    deleteList(&head);

    if(getListSize(&head) || head != NULL){
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;

}

int unitTesting_printList_1()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < 10; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }
    printList(&head, printInt);

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_printList_2()
{
    Node *head;
    int k = 0;

    createList(&head);
    for(double i = 0; i < 0.9; i += 0.1){
        insertElement(&head, ++k, &i, sizeof(double));
    }
    printList(&head, printDouble);

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_printList_3()
{
    Node *head;
    int k = 0;

    createList(&head);
    for(char i = 'a'; i < 'k';  ++i){
        insertElement(&head, ++k, &i, sizeof(char));
    }
    printList(&head, printChar);

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_insertElement_1()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < 10; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }

    int k = -913;
    insertElement(&head, 5, &k, sizeof(int));

    for(int i = 0; i < 4; ++i){
        head = head -> next;
    }

    if(*((int *) head -> data) != -913){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_insertElement_2()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < 10; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }

    int k = -913;
    insertElement(&head, 11, &k, sizeof(int));

    for(int i = 0; i < 10; ++i){
        head = head -> next;
    }

    if(*((int *) head -> data) != -913){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_insertElement_3()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < 10; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }

    int k = -913;
    insertElement(&head, 1, &k, sizeof(int));

    if(*((int *) head -> data) != -913){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_deleteElement_1()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < 10; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }
    deleteElement(&head, 7);

    for(int i = 0; i < 5; ++i){
        head = head -> next;
    }

    if(*((int *) head -> data) == 6){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_deleteElement_2()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < 10; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }
    deleteElement(&head, 10);

    for(int i = 0; i < 8; ++i){
        head = head -> next;
    }

    if(*((int *) head -> data) == 9){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_deleteElement_3()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < 10; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }
    deleteElement(&head, 1);
    
    if(*((int *) head -> data) == 0){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_getListSize_1()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < SHRT_MAX; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }

    if(getListSize(&head) != SHRT_MAX){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_getListSize_2()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < 1; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }

    if(getListSize(&head) != 1){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_getListSize_3()
{
    Node *head;

    createList(&head);

    if(getListSize(&head) != 0){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_getElementValue_1()
{
    Node *head;

    createList(&head);
    for(int i = 0; i < 10; ++i){
        insertElement(&head, i + 1, &i, sizeof(int));
    }

    if(*((int *)getElementValue(&head, 4)) != 3){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_getElementValue_2()
{
    Node *head;
    int k = 0;

    createList(&head);
    for(double i = 0; i < 0.9; i += 0.1){
        insertElement(&head, ++k, &i, sizeof(double));
    }

    if(*((double *)getElementValue(&head, 10)) > 0.9){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}

int unitTesting_getElementValue_3()
{
    Node *head;
    int k = 0;

    createList(&head);
    for(char i = 'a'; i < 'k'; ++i){
        insertElement(&head, ++k, &i, sizeof(int));
    }

    if(*((char *)getElementValue(&head, 1)) != 'a'){
        deleteList(&head);
        return EXIT_FAILURE;
    }

    deleteList(&head);
    return EXIT_SUCCESS;
}


int main()
{

    //createList
    // 1. Create an empty linked list
    assert(unitTesting_createList() == EXIT_SUCCESS);

    //deleteList
    //1. Delete numerous elements
    //2. Delete one elemenent
    //3. Delete empty linked list
    assert(unitTesting_DeleteList_1() == EXIT_SUCCESS);
    assert(unitTesting_DeleteList_2() == EXIT_SUCCESS);
    assert(unitTesting_DeleteList_3() == EXIT_SUCCESS);

    //printList
    //1. Print INT
    //1. Print DOUBLE
    //2. Print CHAR
    printf("printList\n");
    assert(unitTesting_printList_1() == EXIT_SUCCESS);
    assert(unitTesting_printList_2() == EXIT_SUCCESS);
    assert(unitTesting_printList_3() == EXIT_SUCCESS);
    printf("\n");

    //insertElement
    //1. Insert element in the middle
    //2. Insert element in the end
    //3. Insert element at the start
    assert(unitTesting_insertElement_1() == EXIT_SUCCESS);
    assert(unitTesting_insertElement_2() == EXIT_SUCCESS);
    assert(unitTesting_insertElement_3() == EXIT_SUCCESS);

    //deleteElement
    //1. Delete element at the middle
    //2. Delete element at the end
    //3. Delete element at the start
    assert(unitTesting_deleteElement_1() == EXIT_SUCCESS);
    assert(unitTesting_deleteElement_2() == EXIT_SUCCESS);
    assert(unitTesting_deleteElement_3() == EXIT_SUCCESS);

    //getListSize
    //1. When list size = SHRT_MAX
    //2. When list size = 1
    //2. When list size = 0
    assert(unitTesting_getListSize_1() == EXIT_SUCCESS);
    assert(unitTesting_getListSize_2() == EXIT_SUCCESS);
    assert(unitTesting_getListSize_3() == EXIT_SUCCESS);

    //getElementValue
    //1. Return INT at middle
    //2. Return DOUBLE at end
    //3. Return CHAR at start
    assert(unitTesting_getElementValue_1() == EXIT_SUCCESS);
    assert(unitTesting_getElementValue_2() == EXIT_SUCCESS);
    assert(unitTesting_getElementValue_3() == EXIT_SUCCESS);


    printf("All tests have been passed successfully.\n");
    return EXIT_SUCCESS;
}
