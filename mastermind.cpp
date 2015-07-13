#include "CGame.h"
#include "CmdLineParsing.h"
#include <iostream>

//----------------------------------------------------------------------------//

int main( int argc, char **argv )
{
    auto l_params = NMasterMind::checkOpts( argc, argv );

    if (false == l_params.first)
    {
        NMasterMind::usage(argv[0], std::cout);
    }
    else
    {
        // Pass the user-indicated code to the game.
        // The code may be empty.
        NMasterMind::CGame l_game( l_params.second );

        l_game.playGame();
    }

    // TODO: we could return the number of points earnt by the codemaster.

    return l_params.first ? 0 : -1;
}
