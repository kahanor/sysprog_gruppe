#ifndef chessboard_h
#define chessboard_h
#include <stdio.h>
#include <stdlib.h>

struct board_t {
  int n;
  int startpos_x;
  int startpos_y;
  int **fields;
};

int visited_fields(struct board_t *b);

int new_jump(struct board_t *b, int x, int y);

int remove_jump(struct board_t *b, int x, int y);

int isfree(struct board_t *b, int x, int y);

void print_board(struct board_t *b);

int init_board(struct board_t *b, int n, int x, int y);

void free_board(struct board_t *b);

#endif
