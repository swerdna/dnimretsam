/**
 * Copyright 2015 Bob Andrews
 */

#include "CBoard.h"
#include <iostream>

namespace NMasterMind
{

//----------------------------------------------------------------------------//

CBoard::CBoard()
{
    m_guesses.reserve( ctMaxRounds );
}

//----------------------------------------------------------------------------//

void CBoard::display() const
{
    // First print placeholders for the unplayed rounds
    for (int i = ctMaxRounds; i > m_guesses.size(); --i)
    {
        std::cout << "+---------+---------+\n"
                  << "| . . . . | . . . . |\n";
    }

    // Now the played rounds
    auto l_iter = m_guesses.rbegin();
    auto l_endIter = m_guesses.rend();

    for ( ; l_iter != l_endIter; ++l_iter)
    {
        std::cout << "+---------+---------+\n"
                  << "| ";

        // Print the guess
        std::cout << std::get<0>(*l_iter);

        std::cout<< "| ";
                
        // Print the result
        std::cout << std::get<1>(*l_iter);

        std::cout<< "|";

        // Indicate the winning row, if there is one.
        if ( std::get<1>(*l_iter).isWinner() )
        {
            std::cout << " <--- You Win, Congratulations!";
        }

        std::cout << '\n';
    }

    std::cout << "+---------+---------+" << std::endl; 
}

//----------------------------------------------------------------------------//

void CBoard::updateBoard( const CGuess &a_guess, const CResult &a_result )
{
    // Copies the guess and result into the board.
    tRound l_round( a_guess, a_result );
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

