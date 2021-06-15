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
    }

    Soldier::~Soldier()
    {
    }

    bool Soldier::checkMoveLegal(const GridPoint& location , const GridPoint& dest) const
    {
        return ( GridPoint::distance(location, dest) <= MOV_RANGE );
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


        if(ammo < ATT_COST)
        {
            throw Exception::OutOfAmmo();
        }

        return true;
    }

    void Soldier::attack(const GridPoint& location, const GridPoint& dest, 
                         std::vector<std::vector<std::shared_ptr<Character>>> & game_board)
    {

        ammo -= ATT_COST;
        std::shared_ptr<Character> dest_character = game_board[dest.row][dest.col];
        
        if(dest_character != nullptr && team != dest_character->team)
        {
            dest_character->health -= this->power;
        }

        int close_range = math::ceil( (float) att_range / RANGE_DIVIDER);
        int close_power = math::ceil( (float) power / POWER_DIVIDER);

        attackCloseCharacters(game_board, dest, close_range, close_power, dest_character, team); 
    }

    void Soldier::reloadCharacter()
    {
        ammo += RELOAD;
    }

    char Soldier::getOutPutSymbol() const
    {
        return (team == POWERLIFTERS) ? SYMBOL_POWER_LIFTERS : SYMBOL_CROSS_FITTERS;
    }

    std::shared_ptr<Character> Soldier::clone() const
    {
        std::shared_ptr<Character> ptr(new Soldier(*this));
        return ptr;
    }

    Soldier::Soldier(const Soldier& other)
    {
        this->team = other.team;
        this->health = other.health;
        this->ammo = other.ammo;
        this->att_range = other.att_range;
        this->power = other.power;
    }

    void Soldier::attackCloseCharacters(std::vector<std::vector<std::shared_ptr<Character>>>& game_board,
                                        const GridPoint& dest, const int close_range, const int close_power,
                                        const std::shared_ptr<Character>& dest_character, Team self_team)
    {
        int top_left_x = dest.row - close_range;
        int top_left_y = dest.col - close_range;
        int width = game_board.size();
        int height = game_board[0].size();

        for (int row = top_left_y; row <= dest.row + close_range; row++)
        {
            if(row < 0 || row >= height)
            {
                continue;
            }

            for (int col = top_left_x; col <= dest.col + close_range; col++)
            {
                if(col < 0 || col >= width)
                {
                    continue;
                }

                /* Check if cell not empty or, same team */
                if(game_board[row][col] == nullptr || game_board[row][col]->team == self_team)
                {
                    continue;
                }

                GridPoint current_point = GridPoint(row, col);
                /* Check if destination is within range */
                if(GridPoint::distance(current_point, dest) > close_range)
                {
                    continue;
                }

                /* Don't over hit the destination character */
                if(game_board[row][col] == dest_character)
                {
                    continue;
                }

                game_board[row][col]->health -= close_power;
                if(game_board[row][col]->health <= 0)
                {
                    game_board[row][col] = NULL;
                }
            }
        }
    }
}