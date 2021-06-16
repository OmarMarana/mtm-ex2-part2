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

    g.addCharacter(GridPoint(0,0), g.makeCharacter(SOLDIER, POWERLIFTERS, hp, ammo, attack_range, power));
    g.addCharacter(GridPoint(1,1), g.makeCharacter(SNIPER, CROSSFITTERS, hp,ammo, attack_range, power));
    g.addCharacter(GridPoint(1,2), g.makeCharacter(MEDIC, CROSSFITTERS, hp,ammo, attack_range, power));

    cout << g;

    // Team winner = CROSSFITTERS;
    // if(g.isOver(&winner))
    // {
    //     cout << "g2 over" << endl;

    // }
    // else
    // {
    //     cout << "g2 not over" << endl;
    // }

    cout << "Operator << output: " << endl;
    cout << g;

    }

    catch (Exception e)
    {
        cout << e.what() << endl;
    }

    cout << "TEST FINISHED !" << endl;


    return 0;
}