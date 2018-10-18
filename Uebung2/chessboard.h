#include <stdio.h>
#include <stdlib.h>

struct board_t{
    int n;
    int startpos_x;
    int startpos_y;
    int **fields;
};

int visited_fields(struct board_t *b){
    int output = 0;
    //Gehe durch gesamtes Brett
    int x;
    for(x = 0; x < b->n; x++){
        int y;
        for(y = 0; y < b->n; y++){
            //Falls Feld besucht worden ist, erhöhe Anzahl
            if(b->fields[x][y] != 0)
                output++;
        }
    }
    return output;
}

int new_jump(struct board_t *b, int x, int y){
    int vfs = visited_fields(b);
    //Suche nach alter Position
    int pos_x;
    for(pos_x = 0; pos_x < b->n; pos_x++){
        int pos_y;
        for(pos_y = 0; pos_y < b->n; pos_y++){
            if(b->fields[pos_x][pos_y] == vfs){
                //Neues Feld markieren
                b->fields[pos_x+x][pos_y+y] = vfs+1;
                return 1;
            }
        }
    }
    return 0;
}

int remove_jump(struct board_t *b, int x, int y){
    int vfs = visited_fields(b);
    //Suche nach alter Position
    int pos_x;
    for(pos_x = 0; pos_x < b->n; pos_x++){
        int pos_y;
        for(pos_y = 0; pos_y < b->n; pos_y++){
            if(b->fields[pos_x][pos_y] == vfs){
                //Zurücksetzen der Markierung
                b->fields[pos_x][pos_y] = 0;
                return 1;
            }
        }
    }
    return 0;
}

int isfree(struct board_t *b, int x, int y){
    int vfs = visited_fields(b);
    //Suche nach alter Position
    int pos_x;
    for(pos_x = 0; pos_x < b->n; pos_x++){
        int pos_y;
        for(pos_y = 0; pos_y < b->n; pos_y++){
            //Prüfen ob Ziel innerhalb des Bretts liegt
            if(b->fields[pos_x][pos_y] == vfs && pos_x+x < b->n && pos_y+y < b->n){
                //Prüfen ob Feld besucht wurde
                if(b->fields[pos_x+x][pos_y+y] == 0)
                    return 1;
            }
        }
    }
    return 0;
}

void print_board(struct board_t *b){
    int x;
    for(x = 0; x < b->n; x++){
        //Horizontaler Strich
        int y;
        for(y = 0; y < b->n; y++){
            printf("+---");
        }
        printf("+\n");

        //Zeile mit Feldern
        for(y = 0; y < b->n; y++){
            printf("+%3i",b->fields[x][y]);
        }
        printf("+\n");
    }
    //Letzter Strich
    for(x = 0; x < b->n; x++){
        printf("+---");
    }
    printf("+\n");
}

int init_board(struct board_t *b, int n, int x, int y){
    //Prüfen ob Startposition im Brett liegt
    if(x >= n || y >= n)
        return 1;

    //Speicherplatzreservierung für Pointer auf Brett(?)
    b = malloc(sizeof(struct board*));

    //Initialisierung der Variablen von b
    b->n = n;
    b->startpos_x = x;
    b->startpos_y = y;

    //Speicherplatzreservierung für Double Pointer
    b->fields = malloc(n*sizeof(int*));

    int pos_x;
    for(pos_x = 0; pos_x < n; pos_x ++){
        //Speicherplatzreservierung für Arrays im Double Pointer
        b->fields[pos_x] = malloc(n*sizeof(int));
        int pos_y;
        for(pos_y = 0; pos_y < n; pos_y++){
            //Setze alle Felder auf unbesucht
            b->fields[pos_x][pos_y] = 0;
        }
    }
    //Setze Startfeld als erstes besuchtes Feld
    b->fields[x][y] = 1;
    return 0;
}

void free_board(struct board_t *b){
    int i;
    for(i = 0; i < b->n; i++){
        //Gib Speicher aller Arrays im Double Pointer frei
        free(b->fields[i]);
    }
    //Gib Speicher des Double Pointers frei
    free(b->fields);

    //Gib Speicher des Brett-Pointers frei(?)
    free(b);
}
