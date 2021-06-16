#include "Medic.h"

namespace mtm
{
    Medic::Medic(Team team, units_t health, units_t ammo, units_t att_range, units_t power)
    {
        this->team = team;
        this->health = health;
        this->ammo = ammo;
        this->att_range = att_range;
        this->power = power;
    }


    Medic::~Medic()
    {
    }

    bool Medic::checkMoveLegal(const GridPoint& location , const GridPoint& dest) const
    {
        return ( GridPoint::distance(location, dest) <= MOV_RANGE );
    }

    bool Medic::checkAttackLegal(const GridPoint& location, const GridPoint& dest,
                                   const std::shared_ptr<Character>& dest_character) const
    {
        /* check range*/
        if(GridPoint::distance(location, dest) > att_range)
        {
            throw OutOfRange();
        }

        /* check ammo ONLY if target is an enemy character*/
        if(dest_character != nullptr && dest_character->team != team && ammo < ATT_COST)
        {
            throw OutOfAmmo();
        }

        /* check if cell is empty. self attack is not allowed. */
        if(dest_character == nullptr || location == dest)
        {
            throw IllegalTarget();
        }

        return true;
    }

    void Medic::attack(const GridPoint& location, const GridPoint& dest, 
                         std::vector<std::vector<std::shared_ptr<Character>>> & game_board)
    {
        std::shared_ptr<Character> dest_character = game_board[dest.row][dest.col];
        
        if(team != dest_character->team)
        {
            ammo -= ATT_COST;
            dest_character->health -= this->power;
        }
        else
        {
            dest_character->health += this->power;
        }
    }

    void Medic::reloadCharacter()
    {
        ammo += RELOAD;
    }

    char Medic::getOutPutSymbol() const
    {
        return (team == POWERLIFTERS) ? SYMBOL_POWER_LIFTERS : SYMBOL_CROSS_FITTERS;
    }

    std::shared_ptr<Character> Medic::clone() const
    {
        std::shared_ptr<Character> ptr(new Medic(*this));
        return ptr;
    }

    Medic::Medic(const Medic& other)
    {
        this->team = other.team;
        this->health = other.health;
        this->ammo = other.ammo;
        this->att_range = other.att_range;
        this->power = other.power;
    }
}