#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct node{
    struct node* succ;
    char forename[MAX];
    char surname[MAX];
}node;

node* insertNode(node* head, char* fname, char *sname){
    node* newNode = malloc(sizeof(node));
    strcpy(newNode->forename, fname);
    strcpy(newNode->surname, sname);

    if(head == NULL){
        newNode->succ = NULL;
        return newNode;
    }
    node* current = head;
    node* prev = NULL;
    while(current != NULL){
        int result = strcmp(current->surname, newNode->surname);
        if(result == 0){
            result = strcmp(current->forename, newNode->forename);
        }
        if(result > 0){
            newNode->succ = current;
            if(prev == NULL){
                return newNode;
            }
            prev->succ = newNode;
            return head;
        }
        prev = current;
        current = current->succ;
    }
    newNode->succ = NULL;
    prev->succ = newNode;
    return head;
}

void printList(node* head){
    node* cursor = head;
    while (cursor != NULL)
    {
        printf("%s, %s\n",cursor->surname, cursor->forename);
        cursor = cursor->succ;
    }
}

void freeList(node *head){
    node* temp= head;
    while(temp != NULL){
        head = head->succ;
        free(temp);
        temp = head;
    }
}

int main(){
    char filename[MAX];
    printf("Filename input (file has to be in the same directory as the executable or you have to put in the full path): ");
    scanf("%s",filename);
    printf("Datei %s wird geöffnet:\n\n",filename);
    FILE *file;
    file = fopen(filename, "r");
    if(file == NULL){
        puts("Fehler beim oeffnen der Datei!\n");
        return 0;
    }
    node* list = NULL;

    char fname[MAX];
    char sname[MAX];

    while(fscanf(file, "%s %s",fname, sname) != EOF){
        list = insertNode(list, fname, sname);
    }
    printList(list);
    freeList(list);
    fclose(file);
    return 0;
}
