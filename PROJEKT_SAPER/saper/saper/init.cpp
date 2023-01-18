
#include "init.h"
#include "saper.h"

void init(vector<Vac>& my_board, int n)//nadawanie wartoœci pocz¹tkowych planszy
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            my_board[i][j].value = 0;
            my_board[i][j].discovered = 0;
        }

}