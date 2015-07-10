#include "getopt.h"
#include "CGame.h"
#include "MastermindCommonDefines.h"
#include <iostream>

//----------------------------------------------------------------------------//
void usage( const char *a_progName)
{
    std::cout << "usage: " << a_progName << " [-c code]" << std::endl
              << " where code is " << NMasterMind::ctSlots << " digits long, and contains only the"
              << " digits from 1 to " << NMasterMind::ctPegs << std::endl;
}

//----------------------------------------------------------------------------//

std::pair<bool, std::string> checkOpts( int argc, char **argv )
{
    std::string l_code;

    if (1 < argc)
    {
        int c = 0;
        while (-1 != ( c = getopt( argc, argv, "c:" )))
        {
            switch (c)
            {
                case 'c':
                    l_code = optarg;
                    break;
                default:
                    break;
            }
        }
    }

    bool l_valid = true;
    if (NMasterMind::ctSlots != l_code.size())
    {
        l_valid = false;
        l_code.clear();
    }
    else
    {
        for (auto c : l_code)
        {
            if (c < '1' || c > ('0' + NMasterMind::ctPegs))
            {
                l_valid = false;
                l_code.clear();
                break;
            }
        }
    }

    return std::make_pair( l_valid, l_code );
}

//----------------------------------------------------------------------------//

int main( int argc, char **argv )
{
    auto l_params = checkOpts( argc, argv );

    if (false == l_params.first)
    {
        usage(argv[0]);
    }
    else
    {
        // options: -c <code>   Sets the code, and triggers a machine match

        NMasterMind::CGame l_game( l_params.second );

        l_game.playGame();
    }

    return l_params.first ? 0 : -1;
}
