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
        //printf("%d\n", elem->data);
    }
    return elem;
}

bool traverse(LinkElement **head){
    LinkElement *elem = *head;
    while(elem != NULL){
        printf("%d -> ", elem->data);
        elem = elem->next;
    }
    printf("NULL\n");
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
//LinkElement *head;
LinkElement *tail;
bool delete(LinkElement **head, LinkElement *elem)
{
    LinkElement *curPos = *head;
    /* if the element to delete is the First(head) */
    if(!elem) return false;
    if(elem == *head){
        *head = elem->next;
        free(elem);
        if(*head==NULL) tail = NULL;  //if the element is only one,
        return true;
    }
    /* if the element to delete is in the middle */
    while(curPos)
    {
        if(curPos->next == elem){
            curPos->next = elem->next;
            free(elem);
            if(curPos->next == NULL){           //if the element is the last object,
                tail = curPos;
                printf("tail changed->%d\n",tail->data);
            }
            return true;
        }
        curPos =curPos->next;
    }
    return false;
}
bool InsertAfter(LinkElement **head, LinkElement *elem, int data)
{
    LinkElement *curPos = *head;
    LinkElement *newElem = malloc(sizeof(LinkElement));
    if(!newElem) return false;       //check memory allocation
    newElem->data = data;
        /* Insert it at the beginning of the list */
    if(!elem){
        newElem->next = *head;
        *head = newElem;
        /* if tail is also null -> list was empty) */
        if(!tail) tail = newElem;
        return true;
    }
    
    while(curPos){
        if(curPos==elem)
        {
            newElem->next = curPos->next;
            curPos->next = newElem;
            /* if it is at the end of the list */
            if(!newElem->next) tail = newElem;
            return true;
        }
        curPos = curPos -> next;
    }
    free(newElem);
    return false;
}
void RemoveHead(LinkElement **head)
{
    LinkElement *temp;
    if(*head !=NULL && head != NULL)
    {
       temp =(*head)->next;
        free(*head);
        *head= temp;
    }
}
LinkElement *findMthElement(LinkElement *head, int m){
    LinkElement *mBehind, *current;
    int i;
    /* find mth element from the head */
    if(!head) return NULL;
    current = head;
    for(i=0; i<m; i++){
        if(current->next != NULL){
            current = current->next;
        }
        else{
            return NULL;
        }
    }
    /* set mBehind to the Head, and foward the list until current at the last element */
    mBehind = head;
    while(current->next)
    {
        current= current->next;
        mBehind= mBehind->next;
    }
    return mBehind;
}

int main(int argc, const char * argv[]) {
    LinkElement *new = malloc(sizeof(LinkElement));
    new->data = 1;
    new->next = NULL;
    insertInFront(&new, 2);
    insertInFront(&new, 3);
    insertInFront(&new, 4);
    insertInFront(&new, 5);
    LinkElement *findelem = NULL;
//    printf("%d was found.\n", findelem->data);
    
    traverse(&new);
    
  // deleteElement(&new, findelem);
 
 //   traverse(&new);
//    delete(&new, findelem);
    
//    deleteList(&new)
//    printf("%d was deleted.\n", findelem->data);
//    traverse(&new);

    InsertAfter(&new, findelem, 6);
    traverse(&new);
    printf("ㄴInsertAfter inserted\n");
    RemoveHead(&new);
    traverse(&new);

    LinkElement *findM = findMthElement(new, 2);
    printf("ㄴFrom the end, 2st element is : %d \n", findM->data);
    LinkElement *newstack = malloc(sizeof(LinkElement));
    createStack(&newstack);
    push(&newstack, 1);
    push(&newstack, 2);
    push(&newstack, 3);
    push(&newstack, 4);
    traverse(&newstack);
    
    int popped;
    pop(&newstack, &popped);
//    traverse(&newstack);
    printf("%d was popped\n", popped);
    pop(&newstack, &popped);
//    traverse(&newstack);
    printf("%d was popped\n", popped);
    deleteStack(&newstack);
    // insert code here...

    return 0;
}
