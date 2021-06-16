#ifndef MEDIC_H
#define MEDIC_H_
#include "Character.h"


namespace mtm
{
    class Medic : public Character
    {
        public:
            static const int MOV_RANGE             = 5;
            static const int RELOAD                = 5;
            static const int ATT_COST              = 1;
            static const char SYMBOL_POWER_LIFTERS = 'M';
            static const char SYMBOL_CROSS_FITTERS = 'm';

            
            Medic(Team team, units_t health, units_t ammo, units_t att_range, units_t power);
            ~Medic() override;

            bool checkMoveLegal(const GridPoint& location , const GridPoint& dest) const override;

            bool checkAttackLegal(const GridPoint& location, const GridPoint& dest,
                                  const std::shared_ptr<Character>& dest_character) const override;

            void attack(const GridPoint& location, const GridPoint& dest, 
                        std::vector<std::vector<std::shared_ptr<Character>>> & game_board) override;
            
            void reloadCharacter() override;

            char getOutPutSymbol() const override;

            std::shared_ptr<Character> clone() const override;

        private:
            Medic(const Medic& other);
    };
}
#endif
