#include <stdio.h>
#include <stdlib.h>

struct board_t {
  int n;
  int startpos_x;
  int startpos_y;
  int **fields;
};

int visited_fields(struct board_t *b) {
  if(b == NULL)
    return -1;
  int output = 0;
  // Gehe durch gesamtes Brett
  int x;
  for (x = 0; x < b->n; x++) {
    int y;
    for (y = 0; y < b->n; y++) {
      // Falls Feld besucht worden ist, erhoehe Anzahl
      if (b->fields[x][y] != 0) {
        output++;
      }
    }
  }
  return output;
}

int new_jump(struct board_t *b, int x, int y) {
  if(b == NULL)
    return 0;
  int vfs = visited_fields(b);
  // Suche nach alter Position
  int pos_x;
  for (pos_x = 0; pos_x < b->n; pos_x++) {
    int pos_y;
    for (pos_y = 0; pos_y < b->n; pos_y++) {
      if (b->fields[pos_x][pos_y] == vfs) {
	      // Neues Feld markieren
	      b->fields[pos_x + x][pos_y + y] = vfs + 1;
	      return 1;
      }
    }
  }
  return 0;
}

int remove_jump(struct board_t *b, int x, int y) {
  if(b == NULL)
    return 0;
  int vfs = visited_fields(b);
  // Suche nach alter Position
  int pos_x;
  for (pos_x = 0; pos_x < b->n; pos_x++) {
    int pos_y;
    for (pos_y = 0; pos_y < b->n; pos_y++) {
      if (b->fields[pos_x][pos_y] == vfs) {
	      // Zuruecksetzen der Markierung
	      b->fields[pos_x][pos_y] = 0;
	      return 1;
      }
    }
  }
  return 0;
}

int isfree(struct board_t *b, int x, int y) {
  if(b == NULL)
    return 0;
  int vfs = visited_fields(b);
  // Suche nach alter Position
  int pos_x;
  for (pos_x = 0; pos_x < b->n; pos_x++) {
    int pos_y;
    for (pos_y = 0; pos_y < b->n; pos_y++) {
      // Pruefen ob Ziel innerhalb des Bretts liegt
      if (b->fields[pos_x][pos_y] == vfs && pos_x + x < b->n && pos_y + y < b->n && pos_x + x >= 0
	        && pos_y + y >= 0) {
	      // Pruefen ob Feld besucht wurde
	      if (b->fields[pos_x + x][pos_y + y] == 0) {
	        return 1;
        }
      }
    }
  }
  return 0;
}

void print_board(struct board_t *b) {
  if(b == NULL)
    puts("Fehler: Parameter b ist NULL");
    return;
  int x;
  for (x = 0; x < b->n; x++) {
    // Horizontaler Strich
    int y;
    for (y = 0; y < b->n; y++) {
      printf("+---");
    }
    printf("+\n");

    // Zeile mit Feldern
    for (y = 0; y < b->n; y++) {
      printf("+%3i", b->fields[x][y]);
    }
    printf("+\n");
  }
  // Letzter Strich
  for (x = 0; x < b->n; x++) {
    printf("+---");
  }
  printf("+\n");
}

int init_board(struct board_t *b, int n, int x, int y) {
  // Pruefen ob Startposition im Brett liegt und board_t-Pointer nicht NULL ist
  if (x >= n || y >= n || b == NULL)
    return 1;

  // Initialisierung und Speicherplatzreservierung fuer neuen, voruebergehenden Pointer auf Brett
  struct board_t *tmp = (struct board_t *) malloc(sizeof(struct board_t));
  if (tmp == NULL) {
    return 1;
  }

  // Initialisierung der Variablen von b
  tmp->n = n;
  tmp->startpos_x = x;
  tmp->startpos_y = y;

  // Speicherplatzreservierung fuer Double Pointer
  tmp->fields = (int **) malloc(n * sizeof(int *));
  if (tmp->fields == NULL) {
    free(tmp);
    return 1;
  }
  int pos_x;
  for (pos_x = 0; pos_x < n; pos_x++) {
    // Speicherplatzreservierung fuer Arrays im Double Pointer
    tmp->fields[pos_x] = (int *) malloc(n * sizeof(int));
    if (tmp->fields[pos_x] == NULL) {
      free(tmp->fields);
      free(tmp);
      return 1;
    }
    int pos_y;
    for (pos_y = 0; pos_y < n; pos_y++) {
      // Setze alle Felder auf unbesucht
      tmp->fields[pos_x][pos_y] = 0;
    }
  }
  // Setze Startfeld als erstes besuchtes Feld
  tmp->fields[x][y] = 1;

  // Setze Inhalt des urspruenglichen Brett-Pointers auf den des voruebergehenden Pointers und gib
  // von Letzterem den Speicher frei
  *b = *tmp;
  free(tmp);
  return 0;
}

void free_board(struct board_t *b) {
  if(b == NULL)
    puts("Fehler: Parameter b ist NULL");
    return;
  int i;
  for (i = 0; i < b->n; i++) {
    // Gib Speicher aller Arrays im Double Pointer frei
    free(b->fields[i]);
  }
  // Gib Speicher des Double Pointers frei
  free(b->fields);
}
