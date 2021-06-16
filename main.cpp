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
    int width = 5, height = 10;

    int hp = 10, ammo = 50, power = 100, attack_range = 100;

    try
    {
    Game g = Game(height, width);
    
    const GridPoint topLeft = GridPoint(0, 0);
    const GridPoint botRight = GridPoint(4, 4);

    g.addCharacter(topLeft, g.makeCharacter(SOLDIER, POWERLIFTERS, hp, ammo, attack_range, power));

    g.addCharacter(GridPoint(1,1), g.makeCharacter(SNIPER, CROSSFITTERS, hp,ammo, attack_range, power));
    g.addCharacter(GridPoint(1,2), g.makeCharacter(MEDIC, CROSSFITTERS, hp,ammo, attack_range, power));
    
    print_board(g.game_board);

    Game g2 = Game(4,4);
    
    cout << "g2 AFTER CONSTRUCTOR ... \n" << endl;
    print_board(g2.game_board);

    g2 = g; 

    cout << "g2 is ... \n" << endl;
    print_board(g2.game_board);

    g2.addCharacter(GridPoint(2,3), g.makeCharacter(MEDIC, POWERLIFTERS, hp,ammo, attack_range, power));

    cout << "g2 after  is ... \n" << endl;
    print_board(g2.game_board);

    
    cout << "g after  is ... \n" << endl;
    print_board(g.game_board);


    cout << "@@@@@@@@\n" << endl;
    g2.attack(topLeft, GridPoint(0,2));
    cout << "attacking... \n" << endl;

    print_board(g2.game_board);


    // Game g3 = Game(5,5);

    Team winner = CROSSFITTERS;
    if(g2.isOver(&winner))
    {
        cout << "g2 over" << endl;

    }
    else
    {
        cout << "g2 not over" << endl;
    }





    // g.attack(topLeft, GridPoint(0,2));
    // cout << "attacking... \n" << endl;

    // print_board(g.game_board);


    // g.game_board.clear();

    // cout << "after clear \n" << endl;
    
    // cout << "size " << g.game_board.size() << endl;
    // print_board(g.game_board);


    // cout << "check print \n" << g << endl;

    // cout << g << endl;

    


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