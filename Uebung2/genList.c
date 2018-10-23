#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genList.h"

void listInit(list* list, int elementSize, deleteFunction deleteFn, printFunction printFn, compareFunction compareFn){
    //list = malloc(sizeof(list));
    list->elementSize = elementSize;
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
    list->deleteFn = deleteFn;
    list->printFn = printFn;
    list->compareFn = compareFn;
}

void listDelete(list *list){
    Node *current;
    while(list->head != NULL){
        current = list->head;
        list->head = current->next;
        if(list->deleteFn){
            list->deleteFn(current->data);
        }
        free(current->data);
        free(current);
    }
}

void listAppend(list *list, void *element){
    //printf("Append: Element:%s\n",(char *)element);
    Node *newNode = malloc(sizeof(Node));
    newNode->data = malloc(list->elementSize);
    newNode->next = NULL;
    //printf("Append:memcpy: %s\n",(char *)newNode->data);

    memcpy(newNode->data, element, list->elementSize);

    if(list->length == 0){
        list->head = list->tail = newNode;
    }else{
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->length++;
}

void printList(list *list){
    Node *current;
    current = list->head;
    while(current->next != NULL){
        if(list->printFn){
            list->printFn(current->data);
        }
        current = current->next;
    }
}

void insertSorted(list *list, void *element){
   puts("TEST\n");
    printf("insertSorted: Element:%s\n",(char *)element);

    Node *newNode = malloc(sizeof(Node));
    newNode->data = malloc(list->elementSize);
    newNode->next = NULL;
    //memcpy(newNode->data, element, list->elementSize);
    strcpy(newNode->data, element);
    printf("insertSorted:memcpy: %s\n",(char *)newNode->data);

    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    Node *current;
    current = list->head;
    while(current != NULL){
        if(list->compareFn(element,current->data)>= 0){
            Node *tmp;
            tmp = current->next;
            current->next = newNode;
            newNode->next = tmp;
            return;
        }
        current = current->next;
    }
}

