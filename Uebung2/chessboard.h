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
            //Falls Feld besucht worden ist, erh�he Anzahl
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
                //Zur�cksetzen der Markierung
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
            //Pr�fen ob Ziel innerhalb des Bretts liegt
            if(b->fields[pos_x][pos_y] == vfs && pos_x+x < b->n && pos_y+y < b->n && pos_x+x >= 0 && pos_y+y >= 0){
                //Pr�fen ob Feld besucht wurde
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
    //Pr�fen ob Startposition im Brett liegt
    if(x >= n || y >= n)
        return 1;

    //Initialisierung und Speicherplatzreservierung f�r neuen, vor�bergehenden Pointer auf Brett
    struct board_t *tmp = malloc(sizeof(struct board_t));
    if(tmp == NULL)
        return 1;

    //Initialisierung der Variablen von b
    tmp->n = n;
    tmp->startpos_x = x;
    tmp->startpos_y = y;

    //Speicherplatzreservierung f�r Double Pointer
    tmp->fields = malloc(n*sizeof(int*));
    if(tmp->fields == NULL){
        free(tmp);
        return 1;
    }
    int pos_x;
    for(pos_x = 0; pos_x < n; pos_x ++){
        //Speicherplatzreservierung f�r Arrays im Double Pointer
        tmp->fields[pos_x] = malloc(n*sizeof(int));
        if(tmp->fields[pos_x] == NULL){
            free(tmp->fields);
            free(tmp);
            return 1;
        }
        int pos_y;
        for(pos_y = 0; pos_y < n; pos_y++){
            //Setze alle Felder auf unbesucht
            tmp->fields[pos_x][pos_y] = 0;
        }
    }
    //Setze Startfeld als erstes besuchtes Feld
    tmp->fields[x][y] = 1;

    //Setze Inhalt des urspr�nglichen Brett-Pointers auf den des vor�bergehenden Pointers und gib von Letzterem den Speicher frei
    *b = *tmp;
    free(tmp);
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
}
