#ifndef GAME_H
#define GAME_H
#include ".\Characters\Character.h"

namespace mtm
{
    class Game
    {
        //std::shared_ptr<Character> game_board; //**** probably we will use this.... ****

        //Character** game_board; //maybe change to std::share_ptr...
        private:
            std::vector<std::vector<std::shared_ptr<Character>>>  game_board;
            
            int height, width;

            static void checkIllegalCell(int height, int width, const GridPoint &src_coordinates,
                                         const GridPoint &dst_coordinates);
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

            std::ostream& operator<<(std::ostream& stream) const;

            bool isOver(Team* winningTeam = NULL) const;
    };
}

#endif