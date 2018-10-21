#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

/*
 * struct für die Einträge in der dynamischen Liste. Jeder
 * Eintrag hat zwei char-Arrays für Vor- und Nachnamen und einen
 * Pointer auf den nächsten Eintrag
 */
  typedef struct node {
  struct node *succ;
  char forename[MAX];
  char surname[MAX];
} node;

/*
 * insertNode() fügt einen neuen Eintrag an der korrekten Stelle
 * (alphabetisch nach Nachnamen sortiert) ein; bekommt das erste
 * Listenelement und den Namen, der eingetragen werden soll als
 * zwei char-Pointer übergeben; returnt wieder das erste Element
 * der Liste
 */
node *insertNode(node *head, char *fname, char *sname) {
  node *newNode = malloc(sizeof(node));
  strcpy(newNode->forename, fname);
  strcpy(newNode->surname, sname);
  if (head == NULL) {
    newNode->succ = NULL;
    return newNode;
  }
  node *current = head;
  node *prev = NULL;
  while (current != NULL) {
    int result = strcmp(current->surname, newNode->surname);
    if (result == 0) {
      result = strcmp(current->forename, newNode->forename);
    }
    if (result > 0) {
      newNode->succ = current;
      if (prev == NULL) {
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

/*
 * printList() gibt die gesamte Liste aus; bekommt das erste
 * Element der Liste übergeben
 */
void printList(node *head) {
  node *cursor = head;
  while (cursor != NULL) {
    printf("%s, %s\n", cursor->surname, cursor->forename);
    cursor = cursor->succ;
  }
}

/*
 * freeList() gibt den gesamten Speicher, der für die Liste
 * allokiert wurde, wieder frei; bekommt das erste Listenelement
 * übergeben
 */
void freeList(node *head) {
  node *temp = head;
  while (temp != NULL) {
    head = head->succ;
    free(temp);
    temp = head;
  }
}

/*
 * das Programm fragt zuerst nach einer Datei, in der eine
 * Namensliste enthalten ist, liesst die Datei ein, speichert die
 * Namen sortiert nach Nachnamen in einer Liste, gibt die Liste aus
 * und gibt danach den Speicher wieder frei
 */
int main() {
  char filename[MAX];
  printf
    ("Dateinamen eingeben (Datei sollte sich im gleichen Verzeichnis befinden wie das Programm): ");
  scanf("%s", filename);
  printf("Datei %s wird geöffnet:\n\n", filename);
  FILE *file;
  file = fopen(filename, "r");
  if (file == NULL) {
    puts("Fehler beim oeffnen der Datei!\n");
    return 0;
  }
  node *list = NULL;
  char fname[MAX];
  char sname[MAX];
  while (fscanf(file, "%s %s", fname, sname) != EOF) {
    list = insertNode(list, fname, sname);
  }
  printList(list);
  freeList(list);
  fclose(file);
  return 0;
}
