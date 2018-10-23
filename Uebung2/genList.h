#ifndef genList_h
#define genList_h

typedef void (*deleteFunction) (void *);
typedef void (*printFunction) (void *);
typedef int (*compareFunction) (void *, void *);

typedef struct Node{
    void* data;
    struct Node* next;
}Node;

typedef struct list{
    int elementSize;
    int length;
    Node *head;
    Node *tail;
    deleteFunction deleteFn;
    printFunction printFn;
    compareFunction compareFn;
}list;

void listInit(list *list, int elementSize, deleteFunction deleteFn, printFunction printfn, compareFunction compareFn);
void listDelete(list *list);

void listAppend(list *list, void *element);

void printList(list *list);

void insertSorted(list *list, void *element);

#endif