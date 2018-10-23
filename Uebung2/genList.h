#ifndef genList_h
#define genList_h

typedef void (*deleteFunction) (void *);

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
}list;

void listInit(list *list, int elementSize, deleteFunction deleteFn);
void listDelete(list *list);

void listAppend(list *list, void *element);

#endif