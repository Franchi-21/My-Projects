#include <iostream>
#include <cstdlib>
#include <ctime>


class Table 
{
    char tab[3][3], winner;
    void print() 
    {
        system("cls");
        for (size_t r = 0; r < 3; ++r) {
            for (size_t c = 0; c < 3; ++c) {
               std::printf("[%c]", tab[r][c]);
            }
            std::cout << '\n';
        }
    }
    void set(const char letter, const unsigned short pos) 
    {
        bool loop_end = false;
        for (size_t r = 0; !loop_end and r < 3; ++r) {
            for (size_t c = 0; c < 3; ++c) {
                if (tab[r][c] == pos) {
                    loop_end = true;
                    tab[r][c] = letter;
                    break;
                }
            }
        }
    }
    bool win() 
    {
        bool end_game = true;
        if (tab[0][0] == tab[1][1] and tab[1][1] == tab[2][2])
            winner = tab[0][0];
        else if (tab[0][2] == tab[1][1] and tab[1][1] == tab[2][0])
            winner = tab[0][2];
        else if (tab[0][0] == tab[0][1] and tab[0][1] == tab[0][2])
            winner = tab[0][0];
        else if (tab[1][0] == tab[1][1] and tab[1][1] == tab[1][2])
            winner = tab[1][0];
        else if (tab[2][0] == tab[2][1] and tab[2][1] == tab[2][2])
            winner = tab[2][0];
        else if (tab[0][0] == tab[1][0] and tab[1][0] == tab[2][0])
            winner = tab[0][0];
        else if (tab[0][1] == tab[1][1] and tab[1][1] == tab[2][1])
            winner = tab[0][1];
        else if (tab[0][2] == tab[1][2] and tab[1][2] == tab[2][2])
            winner = tab[0][2];
        else
            end_game = false;
        return end_game;
    }
    void bot_play() 
    {
       srand(time(NULL));
       char nought_pos = (rand() % (57 - 49 + 1)) + 49;
       set('o', nought_pos);
    }
    public:
        Table() 
        {
            winner = 'a';
            unsigned short row_enum = 49;
            for (size_t r = 0; r < 3; ++r)
                for (size_t c = 0; c < 3; ++c)
                    tab[r][c] = row_enum++;
        }
        void start() 
        {
            size_t turn_count = 0;
            while (!win()) {
                print();
                char pos;
                std::cout << "Ingresa una posicion: ";
                std::cin >> pos;
                std::cin.get();
                set('x', pos);
                print();
                bot_play();
                print();
            }
            (winner == 'x') ? (std::cout << "Ganaste") : (std::cout << "Perdiste");
        }
};


int main() 
{
    Table *game = new Table();
    game->start();
    delete game;
}
