#include "board_values.h"

//wylosowanie 10 pól z bombami przy u¿yciu generatora Mersenne Twister
void board_values(vector<Vac>& my_board,int n)
{
    std::random_device rd{};
    std::mt19937 generator{ rd() };
    std::uniform_real_distribution<double> rand{ 0.0, 1.0 };
    int x;
    int y;

    for (int i = 0; i < n; ++i)
    {
        x = rand(generator) * 10;
        y = rand(generator) * 10;

        if (my_board[x][y].value != 9) {
            my_board[x][y].value = 9;
            for (int i = -1; i < 2; ++i)
                for (int j = -1; j < 2; j++)
                    if (x + i < n && y + j < n && x + i >= 0 && y + j >= 0)
                        if (my_board[x + i][y + j].value != 9)
                            my_board[x + i][y + j].value++;
        }
        else
        {
            i--;
        }
    }
}