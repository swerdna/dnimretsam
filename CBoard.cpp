/**
 * Copyright 2015 Bob Andrews
 */

#include "CBoard.h"
#include <ostream>

namespace NMasterMind
{

//----------------------------------------------------------------------------//

CBoard::CBoard()
{
    m_guesses.reserve( ctMaxRounds );
}

//----------------------------------------------------------------------------//

std::ostream &CBoard::display( std::ostream &ar_str ) const
{
    // First print placeholders for the unplayed rounds
    for (int i = ctMaxRounds; i > m_guesses.size(); --i)
    {
        ar_str << "+---------+---------+\n"
               << "| . . . . | . . . . |\n";
    }

    // Now the played rounds
    auto l_iter = m_guesses.rbegin();
    auto l_endIter = m_guesses.rend();

    for ( ; l_iter != l_endIter; ++l_iter)
    {
        ar_str << "+---------+---------+\n"
               << "| ";

        // Print the guess
        ar_str << std::get<0>(*l_iter);

        ar_str<< "| ";
                
        // Print the result
        ar_str << std::get<1>(*l_iter);

        ar_str<< "|";

        // Indicate the winning row, if there is one.
        if ( std::get<1>(*l_iter).isWinner() )
        {
            ar_str << " <--- You Win, Congratulations!";
        }

        ar_str << '\n';
    }

    ar_str << "+---------+---------+" << std::endl; 

    return ar_str;
}

//----------------------------------------------------------------------------//

void CBoard::updateBoard( const CGuess &a_guess, const CResult &a_result )
{
    // Copies the guess and result into the board.
    const tRound l_round( a_guess, a_result );
    m_guesses.push_back( l_round );
}

//----------------------------------------------------------------------------//
const CResult *CBoard::getLastResult() const
{
    const CResult *l_res = nullptr;
    if ( ! m_guesses.empty() )
    {
        l_res = & std::get<1>(*( m_guesses.rbegin() ));
    }
    return l_res;
}

}

