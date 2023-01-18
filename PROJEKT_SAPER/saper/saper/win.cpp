#include "win.h"

//sprawdzenie czy liczba pól nieodkrytych jest równa liczbie pól z bombami, co swiadczy o potencjalnej wygranej
bool win(vector<Vac>& my_board, int n)
{
    int how = 0;
    int how2 = 0;
    int win = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if ((my_board[i][j].discovered == 0 || my_board[i][j].discovered == 3) && my_board[i][j].value == 9)
                how++;

            if (my_board[i][j].discovered == 0 || my_board[i][j].discovered == 3)
                how2++;
        }

    if (how == how2)
        return true;
    else
        return false;
}