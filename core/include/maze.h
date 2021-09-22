#ifndef _MAPA_H_
#define _MAPA_H_

#include "common.h"

using namespace std;

class Maze
{
    public:
        Maze() {};

        template <typename It>
        Maze( It begin, It end, string inputFileName )
        {
            int i = 0;
            do
            {
                int j = 0;
                std::vector< char > to_add;
                for ( auto item : *begin )
                {
                    to_add.push_back( item );

                    if ( item == 'P' )
                        spawn_pos = {i , j};    

                    else if ( item == 'E' )
                        exit_pos = {i, j};

                    ++j;
                }
                maze.push_back( to_add );
                ++i;
            }
            while( ++begin != end );

            rows  = maze.size();
            cols = maze[0].size();
            fileName = inputFileName;
        }
        
        char at( int y, int x );
        std::pair< int, int > sizes();
        bool solve();
        void resetMaze();
        void printDirection( int direction, int x, int y );
        void generateFile();

    private:
        vector<vector<char>> maze; // 2D vector of chars representing the maze
        pair<int, int> spawn_pos; // position of the spawn point
        pair<int, int> exit_pos; // position of the end point
        int rows; // number of lines
        int cols; // number of columns
        bool hasSolution = false; // true if the maze has a solution
        string fileName; // name of the read file
};

#endif
