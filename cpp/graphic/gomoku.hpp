#ifndef GOMOKU_H
    #define GOMOKU_H
    #include <utility>
    #include <vector>
    #include <cstdarg>
    #include <cstring>
    #include <cstdio>
    #include <cstdlib>
    #include <iostream>
static const int SIZE = 19;

typedef std::pair<int, int> move_t;
typedef std::vector<move_t> move_list;

int who_won(char **grid);
void print_winner(char **grid);
unsigned eval_shape(unsigned count, unsigned open_ends, bool currentTurn);
int analyze_grid_for_color(char **grid, int color, bool is_my_turn);
move_list possible_moves(char **grid);
void print_grid(char **grid);
move_t calculateNextMove(char **grid, int depth);

#endif
