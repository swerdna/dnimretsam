/**
 * Copyright 2015 Bob Andrews
 */

#include "CKnuthCodeBreaker.h"

namespace NMasterMind
{


//----------------------------------------------------------------------------//

constexpr int pow(int n, int exp)
{
    return exp <  1 ? 1 : (n * pow( n, exp - 1 ));
}

//----------------------------------------------------------------------------//

CKnuthCodeBreaker::CKnuthCodeBreaker()
{
}

//----------------------------------------------------------------------------//

void CKnuthCodeBreaker::initCandidates()
{
    const int l_capacity = pow( ctPegs, ctSlots );

    // populate the set of candidates
    m_candidates.reserve( l_capacity );

    for ( size_t i = 0 ; i < l_capacity; ++i )
    {
        // hint end insertion
        m_candidates.insert( m_candidates.end(), CGuess(i) );
    }

    m_unusedCandidates = m_candidates;
}

CResult evaluateGuess( const CGuess &a_guess )
{
    size_t l_outputIdx = 0;
    CResult l_res;

    // Take a copy of the answer, and the code on the stack to make temporary modifications
    CGuess l_guess = a_guess;
    CGuess l_code = m_code;

    // Check exact matches first
    for ( size_t i = 0; i < l_code.size(); ++i )
    {
        // Matches, same position and value.
        if ( l_guess[ i ] == l_code[ i ] )
        {
            l_res[ l_outputIdx++ ] = ctMatchChar;

            // Invalidate this guess so it's not matched again.
            l_guess[ i ] = -1;
            l_code[ i ]  = -2;
        }
    }

    // Check for pegs that match the code, but are transposed
    for ( auto&& l_codePeg : l_code )
    {
        for ( auto&& l_guessPeg : l_guess )
        {
            if ( l_guessPeg == l_codePeg )
            {
                l_res[ l_outputIdx++ ] = ctTransposeChar;

                // Invalidate this guess so it's not matched again.
                l_guessPeg = -1;
                l_codePeg  = -2;
                break;
            }
        }
    }
    return l_res;
}

CGuess CKnuthCodeBreaker::getGuess() const
{
    if (m_candidates.empty())
    {
        initCandidates();

        m_candidates.erase( 1122 );

        m_lastGuess = {{ '1', '1', '2', '2' }};
    }
    else
    {
        {
            // retrieve the last result from the board
            CResult l_lastResult = m_board->getLastResult();

            auto l_iter = m_candidates.begin();

            do
            {
                // If the candidate is the code, does the result match?
                if ( l_lastResult != evaluateGuess( m_lastGuess, *l_iter ) )
                {
                    l_iter = m_candidates.erase( l_iter );
                }
                else
                {
                    ++l_iter;
                }
            }
            while (m_candidates.end() != l_iter);
        }

        // walk through again - perform minimax
        // for each remaining candidate, find the un-guessed
        // combination that eliminates the most candidates
        for (auto&& i : m_candidates)
        {
            int results[2][4] = {0};
            for (auto&& j : m_unusedCandidates)
            {
                CResult l_res = evaluateGuess( i, j );
                ++ results[ l_res.first() ] [ l_res.second() ];
            }
        }
    }
    return m_lastGuess;
}

};
