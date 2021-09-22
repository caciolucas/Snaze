#include "../include/common.h"
#include "../include/maze.h"

using namespace std;

optional<vector<vector<char>>> readValidateFile(string filePath)
{
    ifstream file( filePath );
    int row, col;
    string line;

    if ( file >> row >> col )
    {
        if ( row < 1 || col < 1 )
        {
            cout << "Arquivo inválido. Quantidade de linhas e colunas deve ser maior que 0." << endl;
            return {};
        }
        
        // Starts the booleans to auxiliate the validation
        bool hasSpawn = false, hasEnd = false; 
        // Skip the first line
        getline(file, line); 
        // Starts the map (2D vector of chars)
        vector<vector<char>> mapa;

        // Reads line by line
        for ( int i = 0 ; i < row; ++i )
        {
            getline( file, line ); // Reads the line
            vector< char > vet_linha; // Creates a new vector of chars to store the line

            for ( int j = 0; j < col; ++j )
            {
                if ( line[j] == '#' || line[j] == ' ' || line[j] == 'P' || line[j] == 'E'){
                    vet_linha.push_back( line[j] );
                    if ( line[j] == 'P' )
                        // Found the spawn point
                        hasSpawn = true; 
                    if ( line[j] == 'E' )
                        // Found the end point
                        hasEnd = true; 
                }

                else
                {
                    cout << "Arquivo inválido. Caractere estranho na posição: (" << i << "," << j << ")." << endl;
                    return { };
                }                       
            }

            if ( vet_linha.size() != col )
            {
                cout << "Arquivo inválido. O número de elementos encontrados na linha " << i << " não condiz com o número de colunas previsto pelo arquivo." 
                          << " Esperava " << col << ", recebeu " << vet_linha.size() << "."
                          << endl;
            }

            mapa.push_back( vet_linha );
        }
        
        if ( mapa.size() != row )
        {
            cout << "Arquivo inválido. O número de linhas não condiz com o número previsto pelo arquivo. Esperava " << row << ", recebeu " << mapa.size() << "." << endl;
            return { };
        }

        if ( not hasSpawn || not hasEnd )
        {
            cout << "Arquivo inválido. Faltando ponto ou ponto inicial ou ponto final" << endl;
            return { };
        }

        return mapa;
    }
    else
    {
        cout << "Arquivo inválido. Faltando quantidades de linhas e colunas no início!" << endl;
        return { };
    }

    return { };
}

int main(int argc, char *argv[])
{
    if (argc < 2){
        cout << "Por favor, informe o arquivo com o labirinto!" << endl;
        return 1;
    }
    
    // If the file is valid, the map is created
    auto map = readValidateFile(argv[1]);
    // If the function returns an empty optional, the file is invalid, skip the rest of the code
    if (map){
        Maze mapa_obj(map->begin(), map->end(), argv[1]);
        mapa_obj.solve();
    }

    return 0;
}
