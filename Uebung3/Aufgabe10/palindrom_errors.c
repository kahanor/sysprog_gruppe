#include <stdio.h>
#include <stdlib.h>
/* Korrektur zu 1 */
#include <string.h>

int palindrom_check1(const char *st1) {
  int st1_len = strlen(st1), i;

  for(i = 0; i < st1_len / 2; i++)
    //Korrektur zu 2
    if (toupper(st1[i]) != toupper(st1[st1_len -1 -i])) return 0;

  return 1;
}

int main(void) {
  char *st1, *st2;
  int st1_len, i;
  //Korrektur zu 3
  char *exit = "exit";

  //Korrektur zu 4
  st1 = malloc(100*sizeof(char));
  st2 = malloc(100*sizeof(char));

  printf("Zum Beenden exit als Eingabe angeben. \n");
  while (1) {
    printf("Eingabe:\n");
    //Korrektur zu 5
    fgets(st1,100,stdin);
    if(st1[strlen(st1)-1] == '\n')
        st1[strlen(st1)-1] = '\0';

    if (strcmp(st1, exit) == 0){
        //Korrektur zu 9
        free(st1);
        free(st2);
        return 0;
    }

    st1_len = strlen(st1);

    for (i=0; i<st1_len; i++) {
      st2[i] = toupper(st1[st1_len -1 -i]);
      //Korrektur zu 8
      st1[i] = toupper(st1[i]);
    }
    //Korrektur zu 6
    st2[st1_len] = '\0';

    if (palindrom_check1(st1)) printf("1. Test: Palindrom \n");
    else printf("1. Test: Kein Palindrom \n");

    //Korrektur zu 7
    if (strcmp(st1,st2) == 0) printf("2. Test: Palindrom\n");
    else printf("2. Test: Kein Palindrom\n");
 }
 return 0;
}
