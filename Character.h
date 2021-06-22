#ifndef CHARACTER_H
#define CHARACTER_H
#include "Auxiliaries.h"
#include "Exceptions.h"
#include <memory>
#include <vector>
#include <cmath>


namespace mtm
{
    class Character
    {
        public:
            int att_range, power, ammo, health;
            Team team;

            /**
            *  checkMoveLegal: Check if the move is within character move range.
            *
            * @param location - Source coordinates.
            * @param dest     - Destination coordinates.
            * @return
            * 	true  - if the move is within range
            * 	false - if the move isn't within range
            * @exception
            * 	None.
            */
            virtual bool checkMoveLegal(const GridPoint& location , const GridPoint& dest) const = 0;
            
            /**
            *  checkAttackLegal: Check if the attack is legal based on the character
            *                    characteristics.
            *
            * @param location         - Location of the attacker.
            * @param dest             - Destination of the character that is attacked.
            * @param dest_character   - The character that is to be attacked.
            * @return
            * 	true  - if the attack is legal
            * 	false - if the attack isn't legal
            * @exception
            *   OutofRange      - If the Destination coordinates aren't in the character attack range. 
            *   OutOfAmmo       - If the character dosn't have enough ammo to attack. 
            *   IllegalTarget   - If can't attack for reasons other than those stated above.
            *                     For example, Sniper can't attack an EmptyCell. 
            */
            virtual bool checkAttackLegal(const GridPoint& location, const GridPoint& dest,
                                   const std::shared_ptr<Character>& dest_character) const = 0;
            
            /**
            *  attack: do the attack based on the attacker's characteristics.
            *
            * @param location         - Location of the attacker.
            * @param dest             - Destination of the character that is attacked.
            * @param game_board       - The game board.
            * @return
            * 	void
            * @exception
            *   None.
            */
            virtual void attack(const GridPoint& location, const GridPoint& dest, 
                                std::vector<std::vector<std::shared_ptr<Character>>> & game_board) = 0;

            /**
            *  reloadCharacter: do the reload based on the character's characteristics.
            *
            * @param  - None.
            * @return
            * 	void
            * @exception
            *   None.
            */
            virtual void reloadCharacter() = 0;
            
            /**
            *  getOutPutSymbol: return the symbol that should be in the game board. 
            *
            * @param  - None.
            * @return
            * 	'N' - if character is Sniper and powerlifter
            * 	'S' - if character is Soldier and powerlifter
            * 	'M' - if character is Medic and powerlifter
            * 	'n' - if character is Sniper and crossfitter
            * 	's' - if character is Sniper and crossfitter
            * 	'm' - if character is Sniper and crossfitter
            * @exception
            *   None.
            */
            virtual char getOutPutSymbol() const = 0;

            /**
            *  clone: create an exact copy of the character. 
            *
            * @param  - None.
            * @return
            * 	a shared_ptr<Character> to the clone character
            * @exception
            *   None.
            */            
            virtual std::shared_ptr<Character> clone() const = 0;
            virtual ~Character() = default;
    };
}


#endif
