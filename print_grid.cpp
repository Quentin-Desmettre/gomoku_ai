#include "gomoku.hpp"

void clear()
{
    system("clear");
}

void print_grid(char grid[SIZE][SIZE])
{
    clear();
    int l = SIZE;
    std::cout << "   ";
    for (int i = 0; i < l; i++)
        std::cout << char('A' + i) << " ";
    std::cout << "\n--";
    for (int i = 0; i < l; i++)
        std::cout <<"--";
    std::cout << "\n";
    for (int i = 0; i < SIZE; i++) {
        if (i < 9)
            std::cout << " ";
        std::cout << i + 1 << "|";
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0)
                std::cout << '.';
            if (grid[i][j] == -1)
                std::cout << 'X';
            if (grid[i][j] == 1)
                std::cout << 'O';
            std::cout << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

}
