#include "gameplay.h"
RenderWindow app(VideoMode(320, 320), "Saper"); //utworzenie okna aplikacji z saperem
RenderWindow menu(VideoMode(500, 707), "MENU"); //utworzenie okna menu

void display(vector<Vac>& my_board, Sprite s,int n)//wyœwietlanie aplikacji planszy
{

    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (my_board[i][j].discovered == 1)
                s.setTextureRect(IntRect(my_board[i][j].value * 32, 0, 32, 32));
            else if (my_board[i][j].discovered == 0) {

                s.setTextureRect(IntRect(10 * 32, 0, 32, 32));
            }
            else if (my_board[i][j].discovered == 3)
                s.setTextureRect(IntRect(11 * 32, 0, 32, 32));
            else if (my_board[i][j].discovered == 4)
                s.setTextureRect(IntRect(12 * 32, 0, 32, 32));
            else if (my_board[i][j].discovered == 5)
                s.setTextureRect(IntRect(13 * 32, 0, 32, 32));



            s.setPosition(i * 32, j * 32);
            app.draw(s);
        }
    app.display();
}

void gameplay(vector<Vac>& my_board,int n)
{
    Texture t;
    Texture m;
    t.loadFromFile("images/pola.jpg");
    m.loadFromFile("images/menu1.jpg");
    Sprite s(t);
    Sprite s2(m);
    menu.draw(s2);
    menu.display();
    bool if_loss = false;

    while (menu.isOpen())
    {
        Event menu_end;
        while (menu.pollEvent(menu_end))

        {
            if (menu_end.type == Event::Closed) {
                menu.close();
                while (app.isOpen())
                {
                    Event click;
                    Vector2i pos = Mouse::getPosition(app);//uzyskanie po³o¿enia myszki
                    int x = pos.x / 32;//podzielenie przez bok kwadracika z polem, ¿eby uzyskaæ po³o¿enie na polu
                    int y = pos.y / 32;//podzielenie przez bok kwadracika z polem, ¿eby uzyskaæ po³o¿enie na polu


                    while (app.pollEvent(click))
                    {

                        if (click.type == Event::Closed)
                            app.close();

                        if (click.type == Event::MouseButtonPressed)
                        {
                            if (click.key.code == Mouse::Left)
                            {
                                if (my_board[x][y].value == 9)//sprawdzenie czy klikniêta wartoœæ nie jest bomb¹ 
                                {



                                    for (int i = 0; i < n; ++i)
                                        for (int j = 0; j < n; ++j)
                                        {
                                            my_board[i][j].discovered = 1;//odkrycie wszystkich pól prze naciœnienie bomby
                                        }
                                    my_board[x][y].discovered = 4;//wskazanie pola przez smutn¹ buŸkê, które "wybuch³o"
                                    if_loss = true;


                                }

                                discovering(my_board, x, y);
                            }

                            if (click.key.code == Mouse::Right) {
                                if (my_board[x][y].discovered == 3)//sprawdzenie czy pole nie jest ju¿ flag¹
                                    my_board[x][y].discovered = 0; //je¿eli ju¿ jest, to powrót do dawnej pozycji ukrytej
                                else if (my_board[x][y].discovered == 0)
                                    my_board[x][y].discovered = 3; // je¿eli nie jest odkryte oraz nie jest ju¿ flag¹, to zaznaczenie pola jako falga
                            }


                        }
                        if (click.type == Event::KeyPressed)
                            if (click.key.code == Keyboard::R)
                            {
                                init(my_board,n);
                                board_values(my_board,n);
                                if_loss = false;
                            }


                    }

                    bool if_win = win(my_board,n);
                    
                    if (if_win == true && if_loss == false)//sprawdznie czy gracz wygra³
                    {
                        for (int i = 0; i < n; ++i)
                            for (int j = 0; j < n; ++j)
                            {
                                if (my_board[i][j].value == 9)
                                    my_board[i][j].discovered = 5;//ukazanie po wygranej pól z bombami jako uœmiechniête buŸki
                            }
                    }
                    display(my_board, s,n);//wyœwietlenie planszy
                }
            }
        }
    }
}