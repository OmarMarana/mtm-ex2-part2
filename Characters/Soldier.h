#ifndef SOLDIER_H
#define SOLDIER_H
#include "Character.h"


namespace mtm
{
    class Soldier : public Character
    {
        public:
            const int MOV_RANGE = 3;
            const int RELOAD = 3;
            const int ATT_COST = 1;
            
            Soldier(Team team, units_t health, units_t ammo, units_t att_range, units_t power);
            ~Soldier() override;

            bool checkMoveLegal(const GridPoint& location , const GridPoint& dest) const override;

            bool checkAttackLegal(const GridPoint& location, const GridPoint& dest,
                                  const std::shared_ptr<Character>& dest_character) const override;

            void attack(const GridPoint& location, const GridPoint& dest, 
                        std::vector<std::vector<std::shared_ptr<Character>>> & game_board) override;
            
            void reloadCharacter() override;

            char getOutPutSymbol() const override;

        private:
            /* private functions for logics for soldier class...*/
    };
}

#endif
