#ifndef CHARACTER_H
#define CHARACTER_H
#include "Auxiliaries.h"
#include "Functions.h"
#include "Exception.h"
#include <memory>
#include <vector>


namespace mtm
{
    class Character
    {
        public:
            int att_range, power, ammo, health;
            Team team;

            virtual bool checkMoveLegal(const GridPoint& location , const GridPoint& dest) const = 0;
            
            virtual bool checkAttackLegal(const GridPoint& location, const GridPoint& dest,
                                   const std::shared_ptr<Character>& dest_character) const = 0;
            
            virtual void attack(const GridPoint& location, const GridPoint& dest, 
                                std::vector<std::vector<std::shared_ptr<Character>>> & game_board) = 0;

            
            virtual void reloadCharacter() = 0;
            virtual char getOutPutSymbol() const = 0;

            virtual std::shared_ptr<Character> clone() const = 0;
            virtual ~Character() = default;
    };
}

/* 
move(...)
{
    check legal cell (source)
    check cell empty (source)

    if(mat[i][j]->checkMoveLegal(...))
    {
        if(mat[x][y] == null) check cell is not occupied...
        {
            throw ...

        }

        //Actual move
        mat[x][y] = mat[i][j];
        mat[i][j] = null;
    }
}

attack(...)
{
    check legal cell (source)
    check cell empty (source)

    if(mat[i][j]->checkAttLegal(source, dest, dest_character)) //also check outOfAmmo..
    {
        //do the actual attack:
        mat[i][j]->attack(source, dest, mat&);
    }
}
*/

#endif
