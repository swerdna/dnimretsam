#include "CGame.h"

std::string checkOpts()
{
    std::string l_code;

    while (( c == getopt( argc, argv, "" )) != 1)
    {
        switch (c)
        {
            case 'c':
                l_code = optarg;
                break;
        }
    }
}

int main( int argc, char **argv )
{
    std::string l_code = checkOpts();

    // options: -c <code>   Sets the code, and triggers a machine match

    NMasterMind::CGame l_game( l_code );

    l_game.playGame();

    return 0;
}
