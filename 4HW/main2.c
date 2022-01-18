//    Author: Adomas Vensas
//    Student's ID: 2110644
//    E-mail: adomasve@gmail.com
//    Assignment's nr.: 7
//    Program's purpose:
//        The program is made to demonstrate the general use cases
//        of the 'slltool' module. Specifically to this program - create a list
//        full of shopping items. Also, there are two additional modules:
//        'revlist' and 'structlist'. First one extends the capabilities of
//        'slltool' by adding the option to reverse the list. Second one - to aggregate
//        future structures that may be used.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slltool.h"
#include "revlist.h"
#include "structlist.h"

#define MSG_ERROR_BAD_INPUT  "\nIncorrect input.\n"
#define MSG_DECLARE_OPTIONS  "To end program enter - 0, to reverse list - 1\nEnter: "
#define MSG_DECLARE_REVERSED "\nThe list has been reversed!\n"
#define MSG_PRODUCT_DETAILS  "PRODUCT NAME------------PRICE PER ITEM------------AMOUNT\n"
#define MSG_SEPERATOR_LINE   "-----------------------------------------------------\n"

#define PRODUCT_AMOUNT 5
#define PRODUCT_NAME_MAX_LENGTH 20

void transferInformation(Node **head)
{
    //Variables and arrays needed for filling up the linked list
    Product item;
    char name[PRODUCT_AMOUNT][PRODUCT_NAME_MAX_LENGTH] = {
        "Apples",
        "Beef",
        "Intel CPU i5",
        "Perfume",
        "Keyboard",
    };
    double pricePerItem[PRODUCT_AMOUNT] = {0.1, 3.5, 50.0, 49.99, 84.99,};
    int amount[PRODUCT_AMOUNT] = {10, 2, 1, 1, 2,};

    //Input given data to the linked list
    for(int i = 0; i < PRODUCT_AMOUNT; ++i){
        strcpy(item.name, name[i]);
        item.pricePerItem = pricePerItem[i];
        item.amount = amount[i];
        insertElement(head, i + 1, &item, sizeof(Product));
    }

    return;
}

void printProductList(Node **head)
{
    printf(MSG_PRODUCT_DETAILS);
    for(int i = 0; i < PRODUCT_AMOUNT; ++i){
        //Obtain the structs node's address
        Product *listing = ((Product *)getElementValue(head, i + 1));

        //Format listing and print subsequent elements
        printf
        ("%-25s %-25.2lf %d\n",
            listing -> name,
            listing -> pricePerItem,
            listing -> amount   
        );
    }
    printf(MSG_SEPERATOR_LINE);

    return;
}

void validateInstruction(int *instr)
{
    if( (scanf("%d", instr) != 1)    ||     //Only one number is needed
        (*instr > 1) || (*instr < 0) ||     //either 1 or 0
        getchar() != '\n' ){                //no trailing input

        *instr = 2;                         //Reset instruction
        
        printf(MSG_ERROR_BAD_INPUT);

        while(getchar() != '\n')            //Clear buffer
            ;
    }

    return;
}

void loadUserInterface(Node **head)
{
    int instr = 2;                      //Instruction to either end program (0) or reverse list (1)
    while(instr){
        printProductList(head);         //Print the product listing

        printf(MSG_DECLARE_OPTIONS);    
        validateInstruction(&instr); 

        if(instr == 1){                 //Reverse the linked list
            reverseList(head);
            printf(MSG_DECLARE_REVERSED);
        }
    }

    return;
}

int main()
{
    Node *head;                 //Head of the linked list

    createList(&head);          //Create a SLL

    transferInformation(&head); //Input information into the linked list
    loadUserInterface(&head);   //Invoke the UI

    deleteList(&head);          //Delete the linked list if finished
    
    return EXIT_SUCCESS;
}