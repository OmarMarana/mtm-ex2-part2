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

    bool Soldier::checkMoveLegal(GridPoint location ,GridPoint dest) const
    {
        return ( GridPoint::distance(location, dest) <= mov_range );
    }

    bool Soldier::checkAttackLegal(GridPoint location, GridPoint dest, std::shared_ptr<Character> dest_character) const
    {
        if( (dest.col != location.col && dest.row != location.row))
        {
            throw Excpections::OutOfAmmo();
        }
        return false;
    }

    void Soldier::reloadCharacter()
    {
        ammo += reload;
    }

    char Soldier::getOutPutSymbol()
    {
        return 'S';
    }
}