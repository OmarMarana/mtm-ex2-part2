#ifndef CHARACTER_H
#define CHARACTER_H
#include "../Auxiliaries.h"
#include "../Functions.h"
#include "../Excpections.h"
#include <memory>


namespace mtm
{
    class Character
    {
        public:
            int att_range, power, ammo, health;
            int mov_range, reload, att_cost;
            Team team;

            virtual bool checkMoveLegal(GridPoint location ,GridPoint dest) const = 0;
            virtual bool checkAttackLegal(GridPoint location, GridPoint dest, std::shared_ptr<Character> dest_character) const = 0;

            
            virtual void reloadCharacter() = 0;
            virtual char getOutPutSymbol() const = 0;

            virtual Character* clone() const = 0;
            
            virtual ~Character() = default;
    };
}
#endif
