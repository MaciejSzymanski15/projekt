#include "discovering.h"
//funkcja odkrywania planszy, poprzez rekurencyjne sprawdzanie czy pole mie�ci si� w zakresie planszy, je�eli tak to czy jego warto�c jest 0, czyli "puste" lub
//czy s�siaduje lub jest bombom, je�eli jest puste to rekurencyjnie sprawdza to samo dla p�l s�siaduj�cych, je�eli ma jak�� warto�c to tylko jest odkyrwane bez wykonywania dla p�l s�siaduj�cych
void discovering(vector<Vac>& my_board, int x, int y)
{

    if (x > 9 || x < 0)
        return;
    if (y > 9 || y < 0)
        return;
    if (my_board[x][y].discovered == 0)
        my_board[x][y].discovered = 1;
    else
        return;
    if (my_board[x][y].value != 0)
        return;
    discovering(my_board, x - 1, y - 1);
    discovering(my_board, x, y - 1);
    discovering(my_board, x - 1, y);
    discovering(my_board, x + 1, y + 1);
    discovering(my_board, x - 1, y + 1);
    discovering(my_board, x + 1, y - 1);
    discovering(my_board, x + 1, y);
    discovering(my_board, x, y + 1);



}