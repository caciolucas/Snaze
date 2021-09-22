#include "../include/path.h"

void Path::pathfinder()
{
    std::set< std::pair< int, int > > checked = { Path::position };
    std::stack< int > directions;
    Path::backtracking( directions, Path::position, checked );

    // Reverse the stack
    while ( not directions.empty() )
    {
        Path::directions.push( directions.top() );
        directions.pop();
    }
}

void Path::backtracking( std::stack< int > &directions, std::pair< int, int > position, std::set< std::pair< int, int > > &checked )
{
    if ( position == Path::exit_pos ) // caso base
    {
        Path::solved = true;
        return;
    }


    // Try each possible direction in turn (up, down, left, right)
    // If we can move in that direction, do so and recurse
    // The directions are stored in a stack, so we can backtrack later

    // Cima

    // If the X position is greater than zero, and the space to the top is not a wall
    if ( position.first - 1 >= 0 and Path::maze->at( position.first - 1, position.second ) != '#' )
    {
        // If the space above is not in the set of visited spaces
        if ( checked.find( {position.first - 1, position.second} ) == checked.end() )
        {
            // Add the space above to the stack of visited spaces
            directions.push( 1 );
            // Print the direction
            Path::maze->printDirection( 1, position.second, position.first - 1);
            // Insert the direction in the set of visited spaces
            checked.insert( {position.first - 1, position.second} );
            // Recurse
            Path::backtracking( directions, {position.first - 1, position.second}, checked );
            // If the solution was found, stop recursing and return
            if ( Path::solved )
                return;
            // If the solution was not found, remove the direction from the stack
            directions.pop();
        }
    }

    // Baixo

    // If the X position is less than the heigh of the map, and the space to the bottom is not a wall
    if ( position.first + 1 < Path::maze->sizes().first and Path::maze->at( position.first + 1, position.second ) != '#' )
    {
        // If the space below is not in the set of visited spaces
        if ( checked.find( {position.first + 1, position.second} ) == checked.end() )
        {
            // Add the space below to the stack of visited spaces
            directions.push( 2 );
            // Print the direction
            Path::maze->printDirection( 2, position.second, position.first + 1);
            // Insert the direction in the set of visited spaces
            checked.insert( {position.first + 1, position.second} );
            // Recurse
            Path::backtracking( directions, {position.first + 1, position.second}, checked );
            // If the solution was found, stop recursing and return
            if ( Path::solved )
                return;
            // If the solution was not found, remove the direction from the stack
            directions.pop();
        }
    }

    // Esquerda

    // If the Y position is greater than zero, and the space to the left is not a wall
    if ( position.second - 1 > 0 and Path::maze->at( position.first, position.second - 1 ) != '#' )
    {
        // If the space to the left is not in the set of visited spaces
        if ( checked.find( {position.first, position.second - 1} ) == checked.end() )
        {
            // Add the space to the left to the stack of visited spaces
            directions.push( 3 );
            // Print the direction
            Path::maze->printDirection( 3, position.second - 1, position.first );
            // Insert the direction in the set of visited spaces
            checked.insert( {position.first, position.second - 1} );
            // Recurse
            Path::backtracking( directions, {position.first, position.second - 1}, checked );
            // If the solution was found, stop recursing and return
            if ( Path::solved )
                return;
            // If the solution was not found, remove the direction from the stack
            directions.pop();
        }
    }

    // Direita

    // If the Y position is less than the width of the map, and the space to the right is not a wall
    if ( position.second + 1 < Path::maze->sizes().second and Path::maze->at( position.first, position.second + 1 ) != '#' )
    {
        // If the space to the right is not in the set of visited spaces
        if ( checked.find( {position.first, position.second + 1} ) == checked.end() )
        {
            // Add the space to the right to the stack of visited spaces
            directions.push( 4 );
            // Print the direction
            Path::maze->printDirection( 4, position.second + 1, position.first );
            // Insert the direction in the set of visited spaces
            checked.insert( {position.first, position.second + 1} );
            // Recurse
            Path::backtracking( directions, {position.first, position.second + 1}, checked );
            // If the solution was found, stop recursing and return
            if ( Path::solved )
                return;
            // If the solution was not found, remove the direction from the stack
            directions.pop();
        }
    }
}

bool Path::solveMaze()
{
    Path::pathfinder();

    if ( Path::solved )
    {
        // Reset the maze to keep only the solution
        Path::maze->resetMaze();
        Path::writeFile();
        return true;
    }

    return false;
}

void Path::writeFile()
{
    while ( not Path::directions.empty() )
    {
        switch ( Path::directions.top() )
        {
            case 1:
            {
                Path::maze->printDirection( 1, Path::position.second, --Path::position.first );
                break;
            }

            case 2:
            {
                Path::maze->printDirection( 2, Path::position.second, ++Path::position.first );
                break;
            }

            case 3:
            {
                Path::maze->printDirection( 3, --Path::position.second, Path::position.first );
                break;
            }

            case 4:
            {
                Path::maze->printDirection( 4, ++Path::position.second, Path::position.first );
                break;
            }
        }

        Path::directions.pop();
    }
}
