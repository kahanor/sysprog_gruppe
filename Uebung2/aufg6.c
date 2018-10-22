#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genList.h"
#define MAX 100

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



}