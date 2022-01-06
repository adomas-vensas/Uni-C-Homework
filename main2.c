#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slluti.h"
#include "revlist.h"
#include "structlist.h"

#define MSG_ERROR_BAD_INPUT  "\nIncorrect input.\n"
#define MSG_DECLARE_OPTIONS  "To end program enter - 0, to reverse list - 1\nEnter: "
#define MSG_DECLARE_REVERSED "\nThe list has been reversed!\n"
#define MSG_PRODUCT_DETAILS  "PRODUCT NAME------------PRICE PER ITEM------------AMOUNT\n"
#define MSG_SEPERATOR_LINE   "-----------------------------------------------------\n"

#define PRODUCT_AMOUNT 5
#define PRODUCT_NAME_MAX_LENGTH 20

void transferInformation(Node **head, char name[PRODUCT_AMOUNT][PRODUCT_NAME_MAX_LENGTH], double *pricePerItem, int *amount)
{
    Product item;

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
        Product *listing = ((Product *)getElementValue(head, i + 1));

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
    if( (scanf("%d", instr) != 1)    ||
        (*instr > 1) || (*instr < 0) ||
        getchar() != '\n' ){

        *instr = 2;
        
        //Not correct input
        printf(MSG_ERROR_BAD_INPUT);

        while(getchar() != '\n')
            ;
    }

    return;
}

void userInterface(Node **head)
{

    int instr = 2;              //Instruction to either end program (0) or reverse list (1)
    while(instr){
        printProductList(head);

        printf(MSG_DECLARE_OPTIONS);
        validateInstruction(&instr);

        if(instr == 1){
            reverseList(head);
            printf(MSG_DECLARE_REVERSED);
        }
    }


    return;
}

int main()
{
    Node *head;
    char name[PRODUCT_AMOUNT][PRODUCT_NAME_MAX_LENGTH] = {
        "Apples",
        "Beef",
        "Intel CPU i5",
        "Perfume",
        "Keyboard",
    };
    double pricePerItem[PRODUCT_AMOUNT] = {0.1, 3.5, 50.0, 49.99, 84.99};
    int amount[PRODUCT_AMOUNT] = {10, 2, 1, 1, 2};

    createList(&head);

    transferInformation(&head, name, pricePerItem, amount);
    userInterface(&head);
    
    return EXIT_SUCCESS;
}