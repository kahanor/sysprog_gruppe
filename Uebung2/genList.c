#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genList.h"

void listInit(list* list, int elementSize){
    list = malloc(sizeof(list));
    list->elementSize = elementSize;
    list->head = NULL;
    list->tail = NULL;
}

void listAppend(list* list, void *element){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = malloc(list->elementSize);
    newNode->next = NULL;
    strncpy(newNode->data, element, list->elementSize);

    if(list->head == NULL){
        list->head = list->tail = newNode;
    }
    list->tail->next = newNode;
    list->tail = newNode;
}

void printList(list* list){
    Node* current = list->head;
    while(current != NULL){
        printf("%s\n",*((char*)current->data));
        current = current->next;
    }
}