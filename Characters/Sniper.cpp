#include "Sniper.h"

namespace mtm
{
    Sniper::Sniper(Team team, units_t health, units_t ammo, units_t att_range, units_t power)
    {
        this->team = team;
        this->health = health;
        this->ammo = ammo;
        this->att_range = att_range;
        this->power = power;

        this->reload = RELOAD;
        this->mov_range = MOV_RANGE;
        this->att_cost = ATT_COST;
    }


    Sniper::~Sniper()
    {
    }

    bool Sniper::checkMoveLegal(GridPoint location ,GridPoint dest) const
    {
        return ( GridPoint::distance(location, dest) <= mov_range );
    }

    bool Sniper::checkAttackLegal(GridPoint location, GridPoint dest, std::shared_ptr<Character> dest_character) const
    {
        /*should check for IllegalCell in attack function since its the same for all characters.
        this should also prevent code duplication.*/ 
         

        /*should check for CellEmpty in attack function since the gameBoard will be a
        private field of game.
        this should also prevent code duplication.*/  
 

        int min_range = ceil(att_range/2);
        int max_range = att_range;        
        int distance = GridPoint::distance(location, dest) <= mov_range;

        if( distance  < min_range || distance > max_range)
        {
            throw Excpections::OutOfRange();
        }

        if(ammo < 1)
        {
            throw Excpections::OutOfAmmo();
        }

        if(dest_character == NULL)
        {
            throw Excpections::IllegalTarget();
        }

        /*dest_character isn't null*/
        if(dest_character->team == this->team)
        {
            throw Excpections::IllegalTarget();
        }


        
    
    }

    void Sniper::reloadCharacter()
    {

    }


    char Sniper::getOutPutSymbol()
    {
        return 'N';
    }


    /*this function may cause bugs due to numerical errors*/
    int ceil(float num) 
    {
        int inum = (int)num;
        if (num == (float)inum) {
            return inum;
        }
        return inum + 1;
    }
}