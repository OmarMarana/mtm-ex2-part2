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
    }

    Sniper::~Sniper()
    {
    }

    bool Sniper::checkMoveLegal(const GridPoint& location , const GridPoint& dest) const
    {
        return ( GridPoint::distance(location, dest) <= MOV_RANGE );
    }

    bool Sniper::checkAttackLegal(const GridPoint& location, const GridPoint& dest,
                                  const std::shared_ptr<Character>& dest_character) const
    {
        int min_range = math::ceil((float)att_range / 2);
        int max_range = att_range;        
        int distance = GridPoint::distance(location, dest) <= MOV_RANGE;

        if( distance  < min_range || distance > max_range)
        {
            throw OutOfRange();
        }

        if(ammo < 1)
        {
            throw OutOfAmmo();
        }

        if(dest_character == NULL)
        {
            throw IllegalTarget();
        }

        /*dest_character isn't null*/
        if(dest_character->team == this->team)
        {
            throw IllegalTarget();
        }

        return true;
    }

    void Sniper::attack(const GridPoint& location, const GridPoint& dest, 
                        std::vector<std::vector<std::shared_ptr<Character>>> & game_board)
    {
        int real_power = power;

        if( (hit_count + 1) % TRIPLE_HIT == 0)
        {
            real_power = power * DOUBLE_POWER;
        }

        // game_board[dest.row][dest.col]->health -= power; // old
        game_board[dest.row][dest.col]->health -= real_power;  // Omar 
        if(game_board[dest.row][dest.col]->health <= 0)
        {
            game_board[dest.row][dest.col] = NULL;
        }
    }

    void Sniper::reloadCharacter()
    {
        ammo += RELOAD;
    }


    char Sniper::getOutPutSymbol() const
    {
        return (team == POWERLIFTERS) ? SYMBOL_POWER_LIFTERS : SYMBOL_CROSS_FITTERS;
    }

    std::shared_ptr<Character> Sniper::clone() const
    {
        std::shared_ptr<Character> ptr(new Sniper(*this));
        return ptr;
    }

    Sniper::Sniper(const Sniper& other)
    {
        this->team = other.team;
        this->health = other.health;
        this->ammo = other.ammo;
        this->att_range = other.att_range;
        this->power = other.power;
    }
}