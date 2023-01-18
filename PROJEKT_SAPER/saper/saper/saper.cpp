#include "saper.h"
#include "init.h"
#include "board_values.h" 
#include "discovering.h"
#include "win.h"
#include "gameplay.h"


int main()
{
    int n = 10;
    Mac my_board(n, Vac(n));
    init(my_board,n);
    board_values(my_board,n);
    gameplay(my_board,n);



}