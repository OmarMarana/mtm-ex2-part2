#ifndef GAME_H
#define GAME_H
#include "Character.h"

namespace mtm
{
    class Game
    {
        private:
            std::vector<std::vector<std::shared_ptr<Character>>> game_board;
            int height, width;

            static const int TEAM_ENUM_RANGE      = 2;
            static const int CHARACTER_ENUM_RANGE = 3;
            static const char EMPTY_CELL_OUTPUT   = ' ';
            

            
            static void checkCellOccupied(const std::vector<std::vector<std::shared_ptr<Character>>> &game_board,
                                       const GridPoint &location);


            
            static void checkIllegalCell(int height, int width, const GridPoint &location);

            static void checkCellEmpty(const std::vector<std::vector<std::shared_ptr<Character>>> &game_board,
                                       const GridPoint &src_coordinates);

        public:
            
            /**
            *  Game: Game constructor.
            *
            * @param height - game board height.
            * @param width  - game board width.
            * @return
            * 	Game with the given parameters
            * @exception
            * 	IllegalArgument   - If one of the parameters is not positive. 
            */
            Game(int height, int width);
            ~Game();
            Game(const Game& other);
            Game& operator=(const Game& other);

            /**
            *  addCharacter: add a character to the game board.
            *
            * @param coordinates - Where to the add the character in the game board.
            * @param character   - The character that needs to be added.
            * @return
            * 	Void
            * @exception
            * 	IllegalCell     - If coordinates isn't in the game board. 
            *   CellOccupied    - If the Destination coordinates are occupied. 
            */
            void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);

            /**
            *  makeCharacter: Make a character.
            *
            * @param type   - Charater type.
            * @param team   - What team the charater is in.
            * @param health - Health value of character.
            * @param ammo   - Ammo amount.
            * @param range  - Attack range.
            * @param power  - How Much Damage is dealt to the attacked player.
            * @return
            * 	returns a shared_ptr<Character> of the player that was created. 
            * @exception
            * 	IllegalArgument   - If one of the parameters is not legal. 
            */
            static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team, units_t health,
            units_t ammo, units_t range, units_t power);

            /**
            *  move: Move Character in the game board.
            *
            * @param src_coordinates - Source coordinates.
            * @param dst_coordinates - Destination coordinates.
            * @return
            * 	Void
            * @exception
            * 	IllegalCell     - If one of the coordinates isn't in the game board. 
            *   CellEmpty       - If the Source coordinates don't have a character in them. 
            *   MoveTooFar      - If the Destination coordinates aren't in the character move range. 
            *   CellOccupied    - If the Destination coordinates are occupied. 
            */
            void move(const GridPoint &src_coordinates,const GridPoint &dst_coordinates);

            /**
            *  attack: Character in src_coordinates attacks the character in dst_coordinates
            *          based on the attacking character characteristics.
            *
            * @param src_coordinates - Source coordinates.
            * @param dst_coordinates - Destination coordinates.
            * @return
            * 	Void
            * @exception
            * 	IllegalCell     - If one of the coordinates isn't in the game board. 
            *   CellEmpty       - If the Source coordinates don't have a character in them. 
            *   OutofRange      - If the Destination coordinates aren't in the character attack range. 
            *   OutOfAmmo       - If the character dosn't have enough ammo to attack. 
            *   
            *   IllegalTarget   - If can't attack for reasons other than those stated above.
            *                     For example, Sniper can't attack an EmptyCell. 
            */
            void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);
            
            /**
            *  reload: Reload ammo for the character in coordinates as stated in the character description.
            *
            * @param coordinates - Coordinates of the character that needs ammo reload.
            * @return
            * 	Void
            * @exception
            * 	IllegalCell     - If the coordinates isn't in the game board. 
            *   CellEmpty       - If the coordinates don't have a character in them. 
            */
            void reload(const GridPoint &coordinates);
            
            /**
            *  isOver: Check if the game is over and save the winning team in winningTeam.
            *
            * @param winningTeam - Source coordinates.
            * @return
            * 	false - If the board dosn't have any players, or has players from both teams.
            * 	true  - If the board has players of one team only.
            * @exception
            * 	None. 
            */
            bool isOver(Team* winningTeam = NULL) const;

            /**
            *  operator<<: Print the game board.
            *
            * @param stream - The Output stream.
            * @param game   - The game that has to be printed.
            * @return
            * 	OutPut stream.
            * @exception
            * 	None. 
            */
            friend std::ostream& operator<<(std::ostream& stream, const Game& game);
    };
}
#endif