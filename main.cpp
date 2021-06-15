#include "./Characters/Character.h"
#include "Auxiliaries.h"
#include "Game.h"
#include <cmath>

using namespace mtm;
using namespace std;
using std::string;


void print_board(vector<vector<shared_ptr<Character>>> & game_board);

int main()
{
    cout << "TEST STARTED !" << endl;
    int width = 5, height = 5;

    int hp = 10, ammo = 50, power = 100, attack_range = 2;

    try
    {
    Game g = Game(height, width);
    
    const GridPoint topLeft = GridPoint(0, 0);
    const GridPoint botRight = GridPoint(4, 4);

    g.addCharacter(topLeft, g.makeCharacter(SOLDIER, POWERLIFTERS, hp, ammo, attack_range, power));

    g.addCharacter(GridPoint(1,1), g.makeCharacter(SNIPER, CROSSFITTERS, hp,ammo, attack_range, power));
    g.addCharacter(GridPoint(1,2), g.makeCharacter(MEDIC, CROSSFITTERS, hp,ammo, attack_range, power));
    
    print_board(g.game_board);


    g.attack(topLeft, GridPoint(0,2));
    cout << "attacking... " << endl;

    print_board(g.game_board);

    }
    catch (Exception::MoveTooFar e)
    {
        cout << e.what() << endl;
    }

    cout << "TEST FINISHED !" << endl;


    /*shared_ptr<Character> ptr = g[i][j] */

    return 0;
}

void print_board(vector<vector<shared_ptr<Character>>> & game_board)
{
    cout<<endl;
    for (int x = 0; x < game_board.size(); x++)
    {
        for (int y = 0; y < game_board[x].size(); y++)
        {
            if(game_board[x][y] == nullptr)
            {
                cout << "- ";
            }
            else
            {
                cout << game_board[x][y]->getOutPutSymbol() << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}