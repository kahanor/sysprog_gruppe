#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genList.h"
#define MAX 100


void deleteString(void *data){
    free(*(char **)data);
}

int main(int argc, char* argv[]){
    char path[MAX];
    printf("Datei Pfad eingeben: ");
    scanf("%s", path);

    FILE* file;
    file = fopen(path,"r");
    if(file == NULL){
        printf("FEHLER: Datei konnte nicht gefunden werden ...\n");
        return 0;
    }

    printf("Sortieroptionen:\n[1] Nachname\n[2] Geburtsdatum\n[3] Wohnort\n");
    int input;
    scanf("%i",&input);
    switch(input){
        case 1: printf("Sortiere nach Nachname\n"); break;
        case 2: printf("Sortiere nach Geburtsdatum\n"); break;
        case 3: printf("Sortiere nach Wohnort\n"); break;
        default: break;
    };

    
    const char *names[] = {"Peter", "Olf", "Guenter", "Merlin", "Nemo"};
    list newList;
    listInit(&newList, sizeof(char *), &deleteString);
    char *name;
    for(int i=0; i<5; i++){
        name = strdup(names[i]);
        listAppend(&newList, &name);
    }
    printf("TEST 5\n");

    listDelete(&newList);
    
    list intList;
    listInit(&intList, sizeof(int), NULL);
    for(int i=0; i<10; i++){
        listAppend(&intList, &i);
    }
    listDelete(&intList);

    /*
     *Nach Valgrind kein Memory leak:
     *Speicher wird wieder komplett frei gegeben
     * 
     * Einfuegen muesste auch funktionieren
     * 
     * To Do:
     * -einlesen der Datei
     * -sortieren
     * -ausgeben
     */


}