/**
 * Copyright 2015 Bob Andrews
 */

#include "CHumanCodeBreaker.h"
#include <iostream>

namespace NMasterMind
{

//----------------------------------------------------------------------------//

CGuess CHumanCodeBreaker::getGuess()
{
    std::string l_str;
    do
    {
        std::cout << "Next guess? (" << ctSlots << " digits, from 1 to " << (int) ctPegs << "): " << std::flush;
        std::cin >> l_str;
    } while (!checkInput( l_str ));

    // std::copy ?
    CGuess l_guess;
    l_guess.fromString( l_str );
    return l_guess;
}

//----------------------------------------------------------------------------//

//static
bool CHumanCodeBreaker::checkInput( const std::string &a_input )
{
    bool l_result = ctSlots == a_input.size();

    // TODO: Construct a literal at compile time from the defines in MastermindCommonDefines
    l_result &= std::string::npos == a_input.find_first_not_of( "123456" );

    return l_result;
}

}
