#ifndef SOLDIER_H
#define SOLDIER_H
#include "Character.h"


namespace mtm
{
    class Soldier : public Character
    {
        public:
            static const int MOV_RANGE             = 3;
            static const int RELOAD                = 3;
            static const int ATT_COST              = 1;
            static const int RANGE_DIVIDER         = 3;
            static const int POWER_DIVIDER         = 2;
            static const char SYMBOL_POWER_LIFTERS = 'S';
            static const char SYMBOL_CROSS_FITTERS = 's';
            
            Soldier(Team team, units_t health, units_t ammo, units_t att_range, units_t power);
            ~Soldier() override;

            bool checkMoveLegal(const GridPoint& location , const GridPoint& dest) const override;

            bool checkAttackLegal(const GridPoint& location, const GridPoint& dest,
                                  const std::shared_ptr<Character>& dest_character) const override;

            void attack(const GridPoint& location, const GridPoint& dest, 
                        std::vector<std::vector<std::shared_ptr<Character>>> & game_board) override;
            
            void reloadCharacter() override;

            char getOutPutSymbol() const override;

            std::shared_ptr<Character> clone() const override;

        private:
            Soldier(const Soldier& other); //copy constructor


            /**
            *  attackCloseCharacters: Deal damage to the characters that are in ceil(range/3) from
            *                         cell that soldier attacked.
            *
            * @param game_board      - game board.
            * @param dest            - Destination coordinates.
            * @param close_range     - the range that damage should be dealt to.
            * @param close_power     - the damage that should be dealt to players in close_range.
            * @param dest_character  - the character that soldier attacked.
            * @param self_team       - the team of the attacker.
            * @return
            * 	Void
            * @exception
            * 	None.
            */
            static void attackCloseCharacters(std::vector<std::vector<std::shared_ptr<Character>>>& game_board,
                                              const GridPoint& dest, const int close_range, const int close_power,
                                              const std::shared_ptr<Character>& dest_character, Team self_team);
    };
}

#endif
