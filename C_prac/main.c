//
//  main.c
//  C_prac
//
//  Created by NAKHOE KIM on 11/28/15.
//  Copyright © 2015 NAKHOE KIM. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkElement{
    struct LinkElement *next;
    int data;
}LinkElement;  //  Singly Linked List

//insert new element to the very first of linked list
//the reason why uses double pointer is that if so, you don't have to return head by changing head pointer
bool insertInFront(LinkElement **head, int data){
    if(!head || !*head) return false;  //check for null pointer
    LinkElement *newElem =malloc(sizeof(LinkElement)); // allocate memory
    if(!newElem) return false;
    
    newElem->data = data;   //  fill data to the 'data' field of newElem
    newElem->next = *head;   // fill head's pointer to the 'next' field of newElem
    *head = newElem;         // newElem is to be the new head pointer (head indicates)
    
    return true;
}
bool deleteElement(LinkElement **head, LinkElement *deleteMe){
    LinkElement *elem;
    if (!head || !*head || !deleteMe)    // check the null pointer
        return false;
    
    elem = *head;                        //start from the head
    if (deleteMe == *head )              //if it is the head
    {
        *head = elem->next;
        free(deleteMe);
        return true;
    }
    while (elem)
    {
        if(elem->next == deleteMe ){      //when elem is infront of deleteMe
            elem->next = deleteMe->next;
            free(deleteMe);
            return true;
        }
        elem = elem->next;
    }
    return false;
}

LinkElement *find(LinkElement *head, int data){   // find from the start
    LinkElement *elem = head;
    while(elem != NULL && elem->data != data){  // if misses the last element, elem = NULL
        printf("%d -> ", elem->data);
        elem = elem->next;
        printf("%d\n", elem->data);
    }
    return elem;
}

bool traverse(LinkElement **head){
    LinkElement *elem = *head;
    while(elem != NULL){
        printf("%d -> ", elem->data);
        elem = elem->next;
    //printf("%d\n", elem->data);
    }
    printf("\n");
    return true;
}

void deleteList(LinkElement **head){
    
    LinkElement *deleteMe =  *head;                 //declares pointer 'deleteMe' to head pointer
    
    while (deleteMe)                                //while deleteme is not NULL
    {
        LinkElement *next = deleteMe->next;         //pointer next -> next node of deleteMe
        free(deleteMe);
        deleteMe = next;
    }
    *head = NULL;
}
bool push(LinkElement **stack, int data)           //pointer of stack and the data to push
{
    LinkElement *elem = malloc(sizeof(LinkElement));
    if(!elem) return false;
    elem->data= data;
    elem->next = *stack;
    *stack = elem;
    return true;
}
bool pop(LinkElement **stack, int *data)          //pointer of stack and return the popped data
{
    LinkElement *elem;
    if(!(elem=*stack)) return false;              // The current element is one indicates stack pointer.
    *data = elem->data;
    *stack = elem->next;
    free(elem);
    return true;
    
}
bool createStack (LinkElement **stack)
{
    *stack= NULL;
    return true;
}
bool deleteStack (LinkElement **stack)
{
    LinkElement *next;
    while(*stack)
    {
        next =(*stack)->next;
        free(*stack);
        *stack = next;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    LinkElement *new = malloc(sizeof(LinkElement));
//    new->data = 0;
//    new->next = NULL;
    insertInFront(&new, 4);
    insertInFront(&new, 3);
    insertInFront(&new, 2);
    insertInFront(&new, 1);
    LinkElement *findelem = find(new, 3);
    printf("found\n");
    
    traverse(&new);
    
    deleteElement(&new, findelem);
    
    traverse(&new);
    deleteList(&new);
    traverse(&new);
    
    LinkElement *newstack = malloc(sizeof(LinkElement));
    createStack(&newstack);
    push(&newstack, 1);
    push(&newstack, 2);
    push(&newstack, 3);
    push(&newstack, 4);
    traverse(&newstack);
    int popped;
    pop(&newstack, &popped);
    traverse(&newstack);
    printf("%d was popped\n", popped);
    pop(&newstack, &popped);
    traverse(&newstack);
    printf("%d was popped\n", popped);
    
    // insert code here...

    return 0;
}
