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
        if(GridPoint::distance(location, dest) > MOV_RANGE)
        {
            throw Exception::MoveTooFar();
        }
        
        return true;
    }

    bool Sniper::checkAttackLegal(const GridPoint& location, const GridPoint& dest,
                                  const std::shared_ptr<Character>& dest_character) const{


        int min_range = ceil(att_range/2);
        int max_range = att_range;        
        int distance = GridPoint::distance(location, dest) <= MOV_RANGE;

        if( distance  < min_range || distance > max_range)
        {
            throw Exception::OutOfRange();
        }

        if(ammo < 1)
        {
            throw Exception::OutOfAmmo();
        }

        if(dest_character == NULL)
        {
            throw Exception::IllegalTarget();
        }

        /*dest_character isn't null*/
        if(dest_character->team == this->team)
        {
            throw Exception::IllegalTarget();
        }

        return true;
    }

    void Sniper::attack(const GridPoint& location, const GridPoint& dest, 
                        std::vector<std::vector<std::shared_ptr<Character>>> & game_board)
    {
        if( (hit_count + 1) % 3 == 0)
        {
            game_board[dest.row][dest.col]->health -= power *2;
        }

        game_board[dest.row][dest.col]->health -= power; 
        
    }

    void Sniper::reloadCharacter()
    {
        ammo += RELOAD;
    }


    char Sniper::getOutPutSymbol() const
    {
        return (team == POWERLIFTERS) ? 'N' : 'n';
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