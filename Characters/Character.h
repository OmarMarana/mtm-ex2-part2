//PURE VISTUAL class....
#ifndef CHARACTER_H
#define CHARACTER_H
#include "../Auxiliaries.h"


namespace mtm
{
    class Character
    {
        protected:
            int range, power, ammo, health;
            Team team;

            //GridPoint location. we want the game board will hold each player location.(using 2d array of Character pointers.)

            virtual void moveCharacter(GridPoint dest) const = 0; //if we will store the GridPoint location, REMOVE THE CONST!!!
            virtual void attackCharacter(GridPoint dest) = 0;
            virtual void reloadCharacter() = 0;

            virtual char getOutPutSymbol() = 0;

        public:
            virtual ~Character() {};
    };
}
#endif
