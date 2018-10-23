#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genList.h"
#define MAX 100


void deleteString(void *data){
    free(*(char **)data);
}
void printString(void *data){
    printf("%s \n",*(char **)data);
}

void printInt(void *data){
    printf("%i \n", *(int **)data);
}

int compareSurname(void *element1, void * element2){
    printf("comp1: %s\n",(char *)element1);
    printf("comp2: %s\n",(char*)element2);
    char *comp1 = (char *)element1;
    char *comp2 = (char *)element2;
    
    char *sur1;
    char *for1;
    for1 = strtok(comp1," ");
    sur1 = strtok(NULL," ");
    char *sur2;
    char *for2;
    for2 = strtok(comp2," ");
    sur2 = strtok(NULL," ");
    puts("comp test");
    return strcmp(sur1,sur2);


}
/*
int compareResidence(void *element1, void * element2){
    
}

int compareBirthDate(void *element1, void * element2){
    
}
*/

int main(int argc, char* argv[]){
    /*
    char path[MAX];
    printf("Datei Pfad eingeben: ");
    scanf("%s", path);

    FILE* file;
    file = fopen(path,"r");
    if(file == NULL){
        printf("FEHLER: Datei konnte nicht gefunden werden ...\n");
        return 0;
    }
    puts("Test 1");
    list sList;
    listInit(&sList, sizeof(char *), &deleteString, &printString, &compareSurname);
    char line[100];
    

    /*
    while(fscanf(file, "%s", line) != EOF){
        puts("Test 2");
        insertSorted(&sList, &line);
    }
    */

   /*
   while(fgets(line, 100, file)!= NULL){
       puts("Test 2");
       insertSorted(&sList, line);
   }
    puts("Test 3");
    printList(&sList);
    puts("test4");
    listDelete(&sList);
    puts("test5");
    */

    /*
    printf("Sortieroptionen:\n[1] Nachname\n[2] Geburtsdatum\n[3] Wohnort\n");
    int input;
    scanf("%i",&input);
    switch(input){
        case 1: printf("Sortiere nach Nachname\n"); break;
        case 2: printf("Sortiere nach Geburtsdatum\n"); break;
        case 3: printf("Sortiere nach Wohnort\n"); break;
        default: break;
    };*/


    
    const char *names[] = {"Peteristeinsehrlangername asadsda adsads 12121", "Olfadssaassasadsadsdasdasdadsasad dsdssdsd", "Guenteradsasas jkjkjkjk", "Merlinasdadssa 1322132", "Nemosadasdsadsd 113221321"};
    list newList;
    listInit(&newList, sizeof(char *), &deleteString, &printString, &compareSurname);
    char *name;
    for(int i=0; i<5; i++){
        name = strdup(names[i]);
        listAppend(&newList, &name);//Anstelle &name kommt dann &<sortierFn>
        //insertSorted(&newList, name);
    }
    printList(&newList);



    listDelete(&newList);
    
    
    list list2;
    listInit(&list2, sizeof(int), NULL, &printInt, &compareSurname);
    for(int i=0; i<10; i++){
        listAppend(&list2, &i);
    }
    printList(&list2);
    listDelete(&list2);
    
    /*
    

    /*
     *Nach Valgrind kein Memory leak:
     *Speicher wird wieder komplett frei gegeben
     * Einfuegen(Append) funktioniert
     * Ausgeben funktioniert
     * sortier einfuegen funktioniert nicht !!!
     * compare funktioniert nicht
     * 
     * To Do:
     * -sortieren
     *    ->dazu comparen
     * 
     */


}