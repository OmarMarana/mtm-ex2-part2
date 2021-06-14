#include "./Characters/Character.h"
#include <cmath>

using namespace mtm;
using namespace std;
using std::string;


void print_vector(vector<vector<shared_ptr<int>>> & game_board);
void change_vector(vector<vector<shared_ptr<int>>> & game_board);

int main()
{
    cout << "HEY" << endl;

     int width = 5, height = 2, num = 0;

    vector<vector< shared_ptr<int>> > game_board;


    for (int i = 0; i < height; i++)
    {
        // Vector to store column elements
        vector< shared_ptr<int> > v1;
  
        for (int j = 0; j < width; j++)
        {
            v1.push_back(nullptr);
        }
  
        // Pushing back above 1D vector
        // to create the 2D vector
        game_board.push_back(v1); 
    }
    
    int x = 7;
    shared_ptr<int> ptr(&x);
    game_board[0][9] = ptr;
    
    print_vector(game_board);

    change_vector(game_board);

    print_vector(game_board);

    return 0;
}

void change_vector(vector<vector<shared_ptr<int>>> & game_board)
{
    shared_ptr<int> ptr(new int(101));
    
    game_board[1][0] = ptr;
}

void print_vector(vector<vector<shared_ptr<int>>> & game_board)
{
    for (int x = 0; x < game_board.size(); x++)
    {
        for (int y = 0; y < game_board[x].size(); y++)
        {
            if(game_board[x][y] == nullptr)
            {
                cout << "NULL ";
            }
            else
            {
                cout << *game_board[x][y] << " ";
            }
        }
        cout << endl;
    }
}