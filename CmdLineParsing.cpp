#include "CmdLineParsing.h"

/**
 * Copyright 2015 Bob Andrews
 */

#include <iostream>
#include "getopt.h"
#include "MastermindCommonDefines.h"

namespace NMasterMind
{

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
    bool l_human = true;

    if (1 < argc)
    {
        int c = 0;
        while (-1 != ( c = getopt( argc, argv, "c:" )))
        {
            switch (c)
            {
                case 'c':
                    l_human = false;
                    l_code = optarg;
                    break;
                default:
                    break;
            }
        }
    }

    bool l_valid = true;
    if (false == l_human)
    {
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
    }

    return std::make_pair( l_valid, l_code );
}



}

