#include <utility>
#include <iostream>

void get_player_points(char cell_type, int &row_1, int &row_2)
{
    if (cell_type == 1) {
        row_1++;
        row_2 = 0;
    } else if (cell_type == -1) {
        row_1 = 0;
        row_2++;
    } else {
        row_1 = 0;
        row_2 = 0;
    }
}

int player_win(int row_1, int row_2)
{
    if (row_1 >= 5)
        return 1;
    if (row_2 >= 5)
        return -1;
    return 0;
}

int is_line_win(char line[19])
{
    int row_1 = 0, row_2 = 0;

    for (int i = 0; i < 19; i++) {
        get_player_points(line[i], row_1, row_2);
        if (row_1 >= 5 || row_2 >= 5)
            break;
    }
    return player_win(row_1, row_2);
}

int check_diag_right(char grid[19][19], int x, int y)
{
    char ch = grid[x][y];

    for (int i = 0; i < 5; i++) {
        if (x + i >= 19 || y + i >= 19)
            return 0;
        if (grid[x + i][y + i] != ch)
            return 0;
    }
    return ch;
}

int check_diag_left(char grid[19][19], int x, int y)
{
    char ch = grid[x][y];

    for (int i = 0; i < 5; i++) {
        if (x + i >= 19 || y - i < 0)
            return 0;
        if (grid[x + i][y - i] != ch)
            return 0;
    }
    return ch;
}

int is_diag_win(char grid[19][19], int x, int y)
{
    int c = check_diag_right(grid, x, y);

    return (c != 0) ? c : check_diag_left(grid, x, y);
}

int is_column_win(char grid[19][19], int column)
{
    int row_1 = 0;
    int row_2 = 0;
    
    for (int i = 0; i < 19; i++) {
        get_player_points(grid[i][column], row_1, row_2);
        if (row_1 >= 5 || row_2 >= 5)
            break;
    }
    return player_win(row_1, row_2);
}

int who_won(char grid[19][19])
{
    int win = 0;

    for (int i = 0; i < 19; i++) {
        win = is_line_win(grid[i]);
        if (win != 0)
            return win;
        win = is_column_win(grid, i);
        if (win != 0)
            return win;
    }
    for (int i = 0; i < 19; i++)
        for (int j = 0; j < 19; j++) {
            win = is_diag_win(grid, i, j);
            if (win != 0)
                return win;
        }
    return 0;
}

void print_winner(char grid[19][19])
{
    int w = who_won(grid);

    if (w == 1)
        std::cout << "Player 1 won !\n";
    else if (w == -1)
        std::cout << "Player 2 won !\n";
    else
        return;
    exit(0);
}
