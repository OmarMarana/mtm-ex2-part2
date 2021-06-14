#ifndef SOLDIER_H
#define SOLDIER_H
#include "Character.h"


namespace mtm
{
    class Soldier : public Character
    {
        public:
            static const int MOV_RANGE      = 3;
            static const int RELOAD         = 3;
            static const int ATT_COST       = 1;
            static const int RANGE_DIVIDER  = 3;
            static const int POWER_DIVIDER  = 2;
            
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
            static void attackCloseCharacters(std::vector<std::vector<std::shared_ptr<Character>>>& game_board,
                                              const GridPoint& dest, const int close_range, const int close_power,
                                              const std::shared_ptr<Character> dest_character, Team self_team);
    };
}

#endif
