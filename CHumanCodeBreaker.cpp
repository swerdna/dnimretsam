/**
 * Copyright 2015 Bob Andrews
 */

#include "CHumanCodeBreaker.h"

namespace NMasterMind
{

//----------------------------------------------------------------------------//

CHumanCodeBreaker::CHumanCodeBreaker( std::shared_ptr<CBoard> a_board )
  : m_board(a_board)
{}

//----------------------------------------------------------------------------//

CGuess CHumanCodeBreaker::getGuess() const
{
    std::string l_str;
    do
    {
        std::cout << "Next guess? (" << ctSlots << " digits, from 1 to 6): " << std::flush;
        std::cin >> l_str;
    } while (!checkInput( l_str ));

    // std::copy ?
    CGuess l_guess;
    for (int i = 0; i < ctSlots; ++i)
    {
        l_guess[i] = l_str[i];
    }
    return l_guess;
}

//----------------------------------------------------------------------------//

//static
bool CHumanCodeBreaker::checkInput( const std::string &a_input )
{
    bool l_result = ctSlots == a_input.size();
    l_result &= std::string::npos == a_input.find_first_not_of( "123456" );
    return l_result;
}

}
