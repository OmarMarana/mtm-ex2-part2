#ifndef SNIPER_H
#define SNIPER_H
#include "Character.h"


namespace mtm
{
    class Sniper : public Character
    {
        public:
            const int MOV_RANGE = 4;
            const int RELOAD = 2;
            const int ATT_COST = 1;
            
            Sniper(Team team, units_t health, units_t ammo, units_t att_range, units_t power);
            ~Sniper() override;

            /*maybe should be private (pdf page 11, 4.4 )*/
            bool checkMoveLegal(GridPoint location ,GridPoint dest) const override;
            bool checkAttackLegal(GridPoint location, GridPoint dest, std::shared_ptr<Character> dest_character) const override;

            void reloadCharacter() override;
            char getOutPutSymbol() override;

            static int ceil(float num);


        private:
            int hit_count =0;

            /* private functions for logics for sniper class...*/
    };
}

#endif
