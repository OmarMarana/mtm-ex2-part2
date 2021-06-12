#ifndef GAME_H
#define GAME_H
#include ".\Characters\Character.h"
#include <memory>

namespace mtm
{
    class Game
    {
        //std::shared_ptr<Character> game_board; //**** probably we will use this.... ****

        Character** game_board; //maybe change to std::share_ptr...

        public:
            Game(int height, int width); //constructor.
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