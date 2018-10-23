#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genList.h"

void listInit(list* list, int elementSize, deleteFunction deleteFn, printFunction printFn){
    //list = malloc(sizeof(list));
    list->elementSize = elementSize;
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
    list->deleteFn = deleteFn;
    list->printFn = printFn;
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
    //free(list);
}

void listAppend(list *list, void *element){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = malloc(list->elementSize);
    newNode->next = NULL;

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
        current = current->next;
        if(list->printFn){
            list->printFn(current->data);
        }
    }
}
