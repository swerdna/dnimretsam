/**
 * Copyright 2015 Bob Andrews
 */

#include "CKnuthCodeBreaker.h"
#include <list>
#include <algorithm>
#include "CBoard.h"

namespace NMasterMind
{

//----------------------------------------------------------------------------//

constexpr int pow(int n, int exp)
{
    return exp <  1 ? 1 : (n * pow( n, exp - 1 ));
}

//----------------------------------------------------------------------------//

void CKnuthCodeBreaker::initCandidates()
{
    // TODO: use permutations here.
    // nCr, choose 4 from
    // 111122223333444455556666

    const int l_capacity = pow( ctPegs, ctSlots );

    CGuess l_candidate(1111);
    for (int i = 0; i < l_capacity; ++i)
    {
        m_candidates.insert( m_candidates.end(), l_candidate );
        ++l_candidate;
    }
    m_unusedCandidates = m_candidates;
}

//----------------------------------------------------------------------------//

CGuess CKnuthCodeBreaker::getGuess()
{
    if (m_candidates.empty())
    {
        initCandidates();

        m_candidates.erase( CGuess(1122) );

        CGuess l_initialGuess(1122);
        std::swap ( m_lastGuess, l_initialGuess );
    }
    else
    {
        {
            // retrieve the last result from the board
            const CResult *l_lastResult = m_board->getLastResult();

            auto l_iter = m_candidates.begin();

            // prune the candidates
            do
            {
                // If the candidate is the code, does the result match?
                if ( (*l_lastResult) != m_lastGuess.compare( *l_iter ) )
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
        std::pair< int, std::list<CGuess> > l_bestCandidate;
        l_bestCandidate.first = 0;

        std::vector< int > l_eliminationsPerResult;
        l_eliminationsPerResult.reserve( ctSlots * 2 + 2 );

        for (auto&& i : m_unusedCandidates)
        {
            // all the possible results
            for (int l_black = 0; l_black < ctSlots; ++l_black)
            {
                for (int l_white = 0; l_white < ctSlots - l_black; ++l_white)
                {
                    const CResult l_res(l_black, l_white);
                    int l_eliminated = 0;

                    // How many candidates would not give this result?
                    // (and could therefore be eliminated)
                    for (auto&& j : m_candidates)
                    {
                        if ( l_res != j.compare(i) )
                        {
                            ++ l_eliminated;
                        }
                    }

                    l_eliminationsPerResult.push_back( l_eliminated );
                }
            }

            // find the minimum number of eliminations for this selection
            int l_minEliminations = *(std::min_element( l_eliminationsPerResult.begin(), l_eliminationsPerResult.end() ));

            // Is that our new best?
            if (l_bestCandidate.first < l_minEliminations)
            {
                l_bestCandidate.second.clear();
                l_bestCandidate.first = l_minEliminations;
                l_bestCandidate.second.push_back(i);
            }
            else if (l_bestCandidate.first == l_minEliminations)
            {
                l_bestCandidate.second.push_back(i);
            }

            l_eliminationsPerResult.clear();
        }

        // Check if any best guesses are in the 'candidates' set
        m_lastGuess = l_bestCandidate.second.front();

        for (auto&& i : l_bestCandidate.second)
        {
            if (m_candidates.end() != m_candidates.find( i ))
            {
                m_lastGuess = i;
                break;
            }
        }
    }

    m_candidates.erase( m_lastGuess );
    m_unusedCandidates.erase( m_lastGuess );

    return m_lastGuess;
}

};
