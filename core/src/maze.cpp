#include "../include/maze.h"
#include "../include/path.h"

char Maze::at( int y, int x )
{
    return Maze::maze[y][x];
}

std::pair< int, int > Maze::sizes()
{
    return {Maze::rows, Maze::cols};
}

bool Maze::solve()
{
    Path caminho( this, Maze::spawn_pos, Maze::exit_pos );
    
    Maze::hasSolution = caminho.solveMaze();

    Maze::generateFile();
    
    return true;
}

void Maze::resetMaze()
{
    for ( auto &i : Maze::maze )
        for ( auto &x : i )
            if ( x == '>' or x == '<' or x == 'v' or x == '^' )
                x = ' ';
}

void Maze::printDirection( int direction, int x, int y )
{
    if (Maze::maze[y][x] == 'E')
        return;

    char directions[] = {' ','^', 'v', '<', '>'};

    Maze::maze[y][x] = directions[direction];
}

void Maze::generateFile()
{
    std::ofstream file( "files/solved.dat", ios::out);

    for ( auto i : Maze::maze )
    {
        for ( auto x : i )
            file << x;
        file << '\n';
    }

    if ( not Maze::hasSolution )
        file << "Não foram encontradas soluções.";

    return;
}
