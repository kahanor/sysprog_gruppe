#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genList.h"
#define MAX 101

/*
 * das struct Person enthält alle Attribute einer Person und ist bei Bedarf beliebig erweiterbar
 */
typedef struct Person {
  char forename[MAX];
  char surname[MAX];
  int birthday;
  int birthmonth;
  int birthyear;
  char city[MAX];
} Person;

/*
 * initPerson() erstellt ein neues Element vom Typ Person, erhält alle notwendigen Attribute,
 * returnt das neu erstellte Element
 */
Person *initPerson(char *fname, char *sname, int bday, int bmonth, int byear, char *city) {
  if (NULL == fname || NULL == sname || NULL == city) {
    perror("Error: Unexpected NULL-Pointer\n");
    return NULL;
  }
  Person *newPerson = malloc(sizeof(Person));
  if (NULL == newPerson) {
    return NULL;
  }
  strncpy(newPerson->forename, fname, MAX);
  strncpy(newPerson->surname, sname, MAX);
  newPerson->birthday = bday;
  newPerson->birthmonth = bmonth;
  newPerson->birthyear = byear;
  strncpy(newPerson->city, city, MAX);
  return newPerson;
}

/*
 * deletePerson() gibt den Speicher eines Person-Elements frei, erhält ein Person-Element als
 * void-Pointer
 */
void deletePerson(void *data) {
  if (NULL == data) {
    perror("Error: Unexpected NULL-Pointer\n");
    return;
  }
  free((Person *) data);
}

/*
 * printPerson() gibt die Attribute eines Person-Elements aus, erhält ein Person-Element als
 * void-Pointer
 */
void printPerson(void *data) {
  if (NULL == data) {
    perror("Error: Unexpected NULL-Pointer\n");
    return;
  }
  Person *p = (Person *) data;
  printf("%s %s %i %i %i %s\n", p->forename, p->surname, p->birthday, p->birthmonth, p->birthyear,
	 p->city);
}

/*
 * compareSurname() vergleicht die Nachnamen zweier Person-Elemente und gibt einen entsprechenden
 * return-Wert als int wieder, der sich am return-Wert der strcmp()-Funktion orientiert,
 * erhält zwei Person-Elemente als void-Pointer
 */
int compareSurname(void *element1, void *element2) {
  if (NULL == element1 || NULL == element2) {
    perror("Error: Unexpected NULL-Pointer\n");
    return EXIT_FAILURE;
  }
  Person *p1 = (Person *) element1;
  Person *p2 = (Person *) element2;
  int result = strcmp(p1->surname, p2->surname);
  if (result == 0) {
    result = strcmp(p1->forename, p2->forename);
  }
  return result;
}

/*
 * compareResidence() vergleicht den Wohnort zweier Person-Elemente und gibt einen entsprechenden
 * return-Wert als int wieder, der sich am return-Wert der strcmp()-Funktion orientiert,
 * erhält zwei Person-Elemente als void-Pointer
 */
int compareResidence(void *element1, void *element2) {
  if (NULL == element1 || NULL == element2) {
    perror("Error: Unexpected NULL-Pointer\n");
    return EXIT_FAILURE;
  }
  Person *p1 = (Person *) element1;
  Person *p2 = (Person *) element2;
  return strcmp(p1->city, p2->city);
}

/*
 * compareBirthdate() vergleicht das Geburtsdatum zweier Person-Elemente und gibt einen
 * int-Wert wieder (element1 > element2: 1)(element1 < element2: -1)(element1 = element2: 0),
 * erhält zwei Person-Elemente als void-Pointer
 */
int compareBirthdate(void *element1, void *element2) {
  if (NULL == element1 || NULL == element2) {
    perror("Error: Unexpected NULL-Pointer\n");
    return EXIT_FAILURE;
  }
  Person *p1 = (Person *) element1;
  Person *p2 = (Person *) element2;
  if (p1->birthyear != p2->birthyear) {
    if (p1->birthyear > p2->birthyear) {
      return 1;
    }
    else {
      return -1;
    }
  }
  if (p1->birthmonth != p2->birthmonth) {
    if (p1->birthmonth > p2->birthmonth) {
      return 1;
    }
    else {
      return -1;
    }
  }
  if (p1->birthday != p2->birthday) {
    if (p1->birthday > p2->birthday) {
      return 1;
    }
    else {
      return -1;
    }
  }
  return 0;
}


int main(int argc, char *argv[]) {
  // Oeffnen der Datendatei:
  char path[MAX];		// Variable für den Dateipfad der Datendatei
  printf("Datei Pfad eingeben: ");
  fgets(path, sizeof(path), stdin);
  strtok(path, "\n");
  printf("Datei %s wird geöffnet\n", path);
  FILE *file;
  file = fopen(path, "r");
  if (file == NULL) {
    printf("FEHLER: Datei konnte nicht gefunden werden ...\n");
    return 0;
  }
  // Abfrage der Sortieroption:
  printf("Sortieroptionen:\n[1] Nachname\n[2] Geburtsdatum\n[3] Wohnort\nEingabe: ");
  char buf[2];
  fgets(buf, 2, stdin);
  int input = atoi(buf);
  if (input != 1 && input != 2 && input != 3) {
    printf("Falsche Eingabe: Nur [1] / [2] / [3] erlaubt");
  }
  // Initialisierung der Variablen zum Einlesen der Daten
  Node *head = NULL;
  char fname[MAX];
  char sname[MAX];
  int bday = 0;
  int bmonth = 0;
  int byear = 0;
  char city[MAX];
  // Einlesen der Daten aus der Datei:
  if (input == 1) {
    printf("Sortiere nach Nachname\n");
    while (fscanf(file, "%s %s %i %i %i %s", fname, sname, &bday, &bmonth, &byear, city) != EOF) {
      Person *newPerson = initPerson(fname, sname, bday, bmonth, byear, city);
      printf("Füge Person ein: ");
      printPerson(newPerson);
      head = insertSorted(head, newPerson, sizeof(Person), &compareSurname);
      free(newPerson);
    }
  }
  if (input == 2) {
    printf("Sortiere nach Geburtsdatum\n");
    while (fscanf(file, "%s %s %i %i %i %s", fname, sname, &bday, &bmonth, &byear, city) != EOF) {
      Person *newPerson = initPerson(fname, sname, bday, bmonth, byear, city);
      printf("Füge Person ein: ");
      printPerson(newPerson);
      head = insertSorted(head, newPerson, sizeof(Person), &compareBirthdate);
      free(newPerson);
    }
  }
  if (input == 3) {
    printf("Sortiere nach Wohnort\n");
    while (fscanf(file, "%s %s %i %i %i %s", fname, sname, &bday, &bmonth, &byear, city) != EOF) {
      Person *newPerson = initPerson(fname, sname, bday, bmonth, byear, city);
      printf("Füge Person ein: ");
      printPerson(newPerson);
      head = insertSorted(head, newPerson, sizeof(Person), &compareResidence);
      free(newPerson);
    }
  }
  printList(head, printPerson);	// Ausgabe der sortierten Liste
  deleteList(head, deletePerson);	// Freigabe des allokierten Speichers
  return EXIT_SUCCESS;
}
