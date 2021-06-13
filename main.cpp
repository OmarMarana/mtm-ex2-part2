#include "./Characters/Character.h"

using namespace mtm;
using namespace std;
using std::string;
#include <vector>
#include <memory>



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


    for (int x = 0; x < game_board.size(); x++)
    {
        for (int y = 0; y < game_board[x].size(); y++)
        {
            if(game_board[x][y] == nullptr)
            {
                cout << "NULL ";
            }
        }
        cout << endl;
    }
    return 0;
}
