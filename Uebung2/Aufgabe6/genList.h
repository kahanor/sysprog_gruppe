#ifndef genList_h
#define genList_h
#include <stdlib.h>

/*
 * Definition der benötigten Funktionspointer fuer die delete-, print-, compareFunction
 */
typedef void (*deleteFunction) (void *);
typedef void (*printFunction) (void *);
typedef int (*compareFunction) (void *, void *);

/*
 * Definition des struct Node für die einzelnen Listenelemente, ohne diese genauer zu definieren
 * bzw. ohne Attribute oder Datentypen festzulegen
 */
typedef struct Node{
  void *data;
  struct Node* next;
} Node;

/*
typedef struct List{
  int elementSize;
  int length;
  Node *head;
  Node *tail;
  deleteFunction deleteFn;
  printFunction printFn;
  compareFunction compareFn;
} List;
void listInit(List *list, int elementSize);
*/

/*
 * Definition der benötigten Funktionen, um die Liste zu verwalten
 */
void deleteList(Node *head, deleteFunction deleteFn);
void printList(Node *head, printFunction printFn);
Node *insertSorted(Node *head, void *element, size_t elementSize, compareFunction compareFn);

#endif
