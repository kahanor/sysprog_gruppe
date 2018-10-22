#ifndef genList_h
#define genList_h

typedef struct Node{
    void* data;
    struct Node* next;
}Node;

typedef struct list{
    int elementSize;
    Node* head;
    Node* tail;
}list;

void listInit(list *list, int elementSize);
void listDestroy(list *list);

void listAppend(list *list, void *element);

void InsertSorted(list* list, void *element, int option);

void printList(list *list);

void sortLastname(list *list, void *element);

void sortBirthDate(list *list, void *element);

void sortResidence(list *list, void *element);

#endif