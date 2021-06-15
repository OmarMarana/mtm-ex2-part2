#ifndef SNIPER_H
#define SNIPER_H
#include "Character.h"


namespace mtm
{
    class Sniper : public Character
    {
        public:
            static const int MOV_RANGE             = 4;
            static const int RELOAD                = 2;
            static const int ATT_COST              = 1;
            static const char SYMBOL_POWER_LIFTERS = 'N';
            static const char SYMBOL_CROSS_FITTERS = 'n';
            static const int TRIPLE_HIT            = 3;
            static const int DOUBLE_POWER          = 2;
            
            Sniper(Team team, units_t health, units_t ammo, units_t att_range, units_t power);
            ~Sniper() override;

            bool checkMoveLegal(const GridPoint& location , const GridPoint& dest) const override;

            bool checkAttackLegal(const GridPoint& location, const GridPoint& dest,
                                  const std::shared_ptr<Character>& dest_character) const override;

            void attack(const GridPoint& location, const GridPoint& dest, 
                        std::vector<std::vector<std::shared_ptr<Character>>> & game_board) override;
            
            void reloadCharacter() override;

            char getOutPutSymbol() const override;

            std::shared_ptr<Character> clone() const override;


        private:
            int hit_count =0;      // check if this works
            Sniper(const Sniper& other); //copy constructor
            /* private functions for logics for sniper class...*/
    };
}

#endif
