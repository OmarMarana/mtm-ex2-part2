#include "Soldier.h"

namespace mtm
{
    Soldier::Soldier(Team team, units_t health, units_t ammo, units_t att_range, units_t power)
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


    Soldier::~Soldier()
    {
    }

    bool Soldier::checkMoveLegal(const GridPoint& location , const GridPoint& dest) const
    {
        return ( GridPoint::distance(location, dest) <= mov_range );
    }

    bool Soldier::checkAttackLegal(const GridPoint& location, const GridPoint& dest,
                                   const std::shared_ptr<Character>& dest_character) const
    {
        /* check same line and range*/
        if( (dest.col != location.col && dest.row != location.row) ||
            GridPoint::distance(location, dest) > att_range)
        {
            throw Exception::OutOfRange();
        }

        
        if(ammo < att_cost)
        {
            throw Exception::OutOfAmmo();
        }

        return true;
    }

    void attack(const GridPoint& location, const GridPoint& dest, 
            std::vector<std::vector<std::shared_ptr<Character>>> & game_board)
    {
        //todo: execute the attack.
        //check if any enemy died from the attack, and remove the dead.
    }

    void Soldier::reloadCharacter()
    {
        ammo += reload;
    }

    char Soldier::getOutPutSymbol() const
    {
        return (team == POWERLIFTERS) ? 'S' : 's';
    }
}