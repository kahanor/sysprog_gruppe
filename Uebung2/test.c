#include <stdio.h>
#include <stdlib.h>
#include "chessboard.h"

struct board_t b;

void main(){
    if (init_board(&b, 5, 0, 0) > 0)
        printf("FAIL");
        return;
    print_board(&b);
}
