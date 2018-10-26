#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genList.h"

/*
void listInit(List *list, int elementSize, deleteFunction deleteFn, printFunction printFn, compareFunction compareFn) {
  printf("Initialisiere Liste");
  // list = malloc(sizeof(List));
  printf("Speicher allokiert");
  list->elementSize = elementSize;
  list->length = 0;
  list->head = NULL;
  list->tail = NULL;
  list->deleteFn = deleteFn;
  list->printFn = printFn;
  list->compareFn = compareFn;
  printf("Liste initialisiert");
}
*/

/*
 * deleteList() gibt den für die gesamte Liste allokierten Speicher wieder frei,
 * erhält den Anfang der Liste und die deleteFunction, um die einzelenen Elemente zu löschen
 */
void deleteList(Node *head, deleteFunction deleteFn) {
  Node *current;
  while(head != NULL){
    current = head;
    head = current->next;
    if(deleteFn != NULL){
      deleteFn(current->data);
    }
    free(current);
  }
}

/*
 * printList() gibt die gesamte Liste aus, erhält den Anfang der Liste und die printFunction, um
 * die einzelnen Elemente korrekt auszugeben
 */
void printList(Node *head, printFunction printFn) {
  printf("\nVollständige, sortierte Liste:\n");
  Node *current;
  if(head == NULL) {
    printf("Liste ist leer\n");
    return;
  }
  if(printFn != NULL) {
    current = head;
    printFn(current->data);
    while(current->next != NULL){
      current = current->next;
      printFn(current->data);
    }
  }
}

/*
 * insertSorted() fuegt ein neues Element an der korrekten Stelle in die Liste ein, sodass die
 * Liste immer sortiert bleibt, erhält den Anfang der Liste, das einzuguegende Element, die Grösse
 * des Elements und die compareFunction, die das Sortierkriterium festlegt und anwendet,
 * gibt den Anfang der erweiterten Liste zurück
 */
Node *insertSorted(Node *head, void *element, size_t elementSize, compareFunction compareFn) {
  if(NULL == element) {
    perror("Error: Unexpected NULL-Pointer\n");
    return NULL;
  }
  Node *newNode = NULL;
  newNode = malloc(sizeof(Node));
  newNode->data = malloc(elementSize);
  memcpy(newNode->data, element, elementSize);
  if(head == NULL){
    head = newNode;
    return head;
  }
  Node *current = head;
  Node *prev = NULL;
  while(current != NULL) {
    int result = compareFn(element,current->data);
    if( result <= 0) {
      newNode->next = current;
      if(NULL == prev) {
        head = newNode;
        return head;
      }
      prev->next = newNode;
      return head;
    }
    prev = current;
    current = current->next;
  }
  newNode->next = NULL;
  prev->next = newNode;
  return head;
}
