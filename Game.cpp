#include "Game.h"
#include "Character.h"
#include "Sniper.h"
#include "Medic.h"
#include "Soldier.h"


namespace mtm
{
    
    Game::Game(int height, int width) : height(height) , width(width)
    {
        if(height <=0 || width <=0 )
        {
            throw IllegalArgument();
        }

        for (int i = 0; i < height; i++)
        {
            std::vector<std::shared_ptr<Character>> v1;

            for (int j = 0; j < width; j++)
            {
                std::shared_ptr<Character> ptr(NULL);
                v1.push_back(ptr);
            }
            
            game_board.push_back(v1); 
        }
    }
    
    
    Game::Game(const Game& other) : height(other.height) , width(other.width)
    {
        for (int i = 0; i < other.height; i++)
        {
            std::vector<std::shared_ptr<Character>> v1;

            for (int j = 0; j < other.width; j++)
            {
                std::shared_ptr<Character> ptr;
                if(other.game_board[i][j] == NULL)
                {
                    ptr = NULL;
                }
                else
                {
                    ptr = other.game_board[i][j]->clone();
                }
                
                v1.push_back(ptr);
                
            }
            this->game_board.push_back(v1); 
        }

    }

    Game::~Game()
    {

    }

    Game& Game::operator=(const Game& other)
    {
        height = other.height;
        width = other.width;
        
        game_board.clear();

        for (int i = 0; i < other.height; i++)
        {
            std::vector<std::shared_ptr<Character>> v1; 

            for (int j = 0; j < other.width; j++)
            {
                std::shared_ptr<Character> ptr; 
                if(other.game_board[i][j] == NULL)
                {
                    ptr = NULL;
                }
                else
                {
                    ptr = other.game_board[i][j]->clone();
                }
                
                v1.push_back(ptr);
                
            }
            this->game_board.push_back(v1); 
        }

        return *this;
    }

    void Game::move(const GridPoint &src_coordinates,const GridPoint &dst_coordinates)
    {
        checkIllegalCell( height, width, src_coordinates);
        checkIllegalCell( height, width, dst_coordinates);

        checkCellEmpty(game_board, src_coordinates);
                                       

        if(game_board[src_coordinates.row][src_coordinates.col]->checkMoveLegal(src_coordinates,dst_coordinates))
        {
            
            checkCellOccupied(game_board, dst_coordinates);

            game_board[dst_coordinates.row][dst_coordinates.col] = 
            game_board[src_coordinates.row][src_coordinates.col];

            
            game_board[src_coordinates.row][src_coordinates.col] = NULL;
        }
        else
        {
            throw MoveTooFar();
        }

    }


    void Game::attack(const GridPoint & src_coordinates, const GridPoint & dst_coordinates)
    {
        checkIllegalCell( height, width, src_coordinates);
        checkIllegalCell( height, width, dst_coordinates);

        checkCellEmpty(game_board, src_coordinates);

        if(game_board[src_coordinates.row][src_coordinates.col]->checkAttackLegal(src_coordinates,dst_coordinates,
        game_board[dst_coordinates.row][dst_coordinates.col]))
        {
            game_board[src_coordinates.row][src_coordinates.col]->attack(src_coordinates,dst_coordinates,
            game_board);
        }

    }

    void Game::reload(const GridPoint &coordinates)
    {
        checkIllegalCell(height, width, coordinates);
        
        checkCellEmpty(game_board, coordinates);

        game_board[coordinates.row][coordinates.col]->reloadCharacter();


    }

    std::ostream& operator<<(std::ostream& stream, const Game& game)
    {
        std::string str= "";

        for (int i = 0; i < game.height; i++)
        { 
            for (int j = 0; j < game.width; j++)
            {
                if(game.game_board[i][j] == NULL)
                {
                    str.push_back(Game::EMPTY_CELL_OUTPUT);
                }
                else
                {
                    str.push_back(game.game_board[i][j]->getOutPutSymbol());
                }
            } 
        }

        const char * begin = str.data();
        const char * end = begin + str.size();
            
        return printGameBoard(stream, begin, end, game.width); 
    }

    bool Game::isOver(Team* winningTeam) const
    {
        bool cross_fitter_found =false, power_lifter_found =false;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if(game_board[i][j] == NULL)
                {
                    continue;
                }
                
                if(game_board[i][j]->team == CROSSFITTERS)
                {
                    cross_fitter_found = true;
                }
                
                if(game_board[i][j]->team == POWERLIFTERS)
                {
                    power_lifter_found = true;
                }
            }
        }
        
        /*if the board is empty, or members of the two teams are present,
        then there is no winner*/
        if( (cross_fitter_found && power_lifter_found) ||
            (!cross_fitter_found && !power_lifter_found))
        {
            return false;
        }

        /*if reached here then there is a winner and the game is over.
        The question is whether winninfTeam is null or not*/

        if( winningTeam != NULL)
        {
            if(cross_fitter_found)
            {
                *winningTeam = CROSSFITTERS;
            }
            else
            {
                *winningTeam = POWERLIFTERS;
            }
        }

        return true;

    }


    void Game::addCharacter(const GridPoint& coordinates, std::shared_ptr<Character> character)
    {
        checkIllegalCell(height, width, coordinates);
        
        checkCellOccupied(game_board, coordinates);

        game_board[coordinates.row][coordinates.col] = character;

    }

    std::shared_ptr<Character> Game::makeCharacter(CharacterType type, Team team, units_t health,
            units_t ammo, units_t range, units_t power)
    {
        if(health <= 0 || range < 0 || team < 0 || type < 0 || ammo < 0 ||
			power < 0 || type >= CHARACTER_ENUM_RANGE || team >= TEAM_ENUM_RANGE)
        {
            throw IllegalArgument();
        }

        switch (type)
        {
        case SNIPER:
        {
                std::shared_ptr<Character> ptr( new Sniper(team, health, ammo, range, power) );
                return ptr;
        }
        case MEDIC:
        {
                std::shared_ptr<Character> ptr( new Medic(team, health, ammo, range, power) );
                return ptr;
        }   
        case SOLDIER:
        {
                std::shared_ptr<Character> ptr( new Soldier(team, health, ammo, range, power) );
                return ptr;
        }   
        default:
            return NULL;
        }
    }



    /***********************************/
    /*******STATIC FUNCS****************/
    /***********************************/

    void Game::checkIllegalCell(int height, int width, const GridPoint &location)
    {
        if(location.row >= height || location.row < 0 ||
           location.col >= width || location.col < 0 )
        {
            throw IllegalCell();
        }
    }

    void Game::checkCellEmpty(const std::vector<std::vector<std::shared_ptr<Character>>> &game_board,
                              const GridPoint &src_coordinates)
    {
        if(game_board[src_coordinates.row][src_coordinates.col] == NULL)
        {
            throw CellEmpty();
        }
    }

    void Game::checkCellOccupied(const std::vector<std::vector<std::shared_ptr<Character>>> &game_board,
                                 const GridPoint &location)
    {
        if(game_board[location.row][location.col] != NULL)
        {
            throw CellOccupied();
        }
    }


}
