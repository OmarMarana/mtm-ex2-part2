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
            

            /*yontatan: make all the paramaters const if they don't change in the functions...*/
            static void checkCellOccupied(std::vector<std::vector<std::shared_ptr<Character>>> &game_board,
                                       const GridPoint &location);


            
            static void checkIllegalCell(int height, int width, const GridPoint &location);

            static void checkCellEmpty(std::vector<std::vector<std::shared_ptr<Character>>> &game_board,
                                       const GridPoint &src_coordinates);

        public:
            Game(int height, int width);
            ~Game();
            Game(const Game& other);
            Game& operator=(const Game& other);

            void addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character);

            static std::shared_ptr<Character> makeCharacter(CharacterType type, Team team, units_t health,
            units_t ammo, units_t range, units_t power);

            void move(const GridPoint &src_coordinates,const GridPoint &dst_coordinates);

            void attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates);

            void reload(const GridPoint &coordinates);

            bool isOver(Team* winningTeam = NULL) const;

            friend std::ostream& operator<<(std::ostream& stream, const Game& game);
    };
}
#endif