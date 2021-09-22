#ifndef _CAMINHO_H_
#define _CAMINHO_H_

#include "common.h"
#include "maze.h"

class Path
{
    public:
        Path( Maze *maze_ptr, std::pair< int, int > position, std::pair< int, int > exit_position )
        {
            maze = maze_ptr;
            position = position;
            exit_pos = exit_position;
        }
    
        bool solveMaze();

    private:
        void pathfinder();
        void backtracking( std::stack< int > &directions, std::pair< int, int > position, std::set< std::pair< int, int > > &checked );
        void writeFile();

    private:
        Maze *maze; // Maze to solve
        std::stack< int > directions; // Stack of directions to follow to get to the exit
        std::pair< int, int > position; // Snake position
        std::pair< int, int > exit_pos; // Exit position
        bool solved = false; // True if the maze has been solved
};

#endif
