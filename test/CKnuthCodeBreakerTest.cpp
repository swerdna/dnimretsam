/**
 * Copyright 2015 Bob Andrews
 */

#include "gtest/gtest.h"
#include <cmath>
#include "CKnuthCodeBreaker.h"
#include "CBoard.h"

TEST( KnuthBreaker, Init )
{
    using namespace NMasterMind;

    CKnuthCodeBreaker l_knuth;

    ASSERT_EQ( 0, l_knuth.m_candidates.size() );
    ASSERT_EQ( 0, l_knuth.m_unusedCandidates.size() );

    l_knuth.initCandidates();

    // The number of candidates
    const int l_capacity = pow( ctPegs, ctSlots );

    ASSERT_EQ( l_capacity, l_knuth.m_candidates.size() );
    ASSERT_EQ( l_capacity, l_knuth.m_unusedCandidates.size() );
}

TEST( KnuthBreaker, Guess )
{
    using namespace NMasterMind;

    // Check we can find '1123'
    {
        std::shared_ptr<CBoard> l_board( new CBoard );
        CKnuthCodeBreaker l_knuth;

        l_knuth.setBoard(l_board);

        ASSERT_EQ( 0, l_knuth.m_candidates.size() );
        ASSERT_EQ( 0, l_knuth.m_unusedCandidates.size() );

        // The first guess is always "1122"
        CGuess l_guess = l_knuth.getGuess();

        // Check that the guess is 1122
        ASSERT_EQ(CGuess(1122), l_guess);

        // The number of candidates after the first guess
        int l_candidates = pow( ctPegs, ctSlots ) - 1;

        ASSERT_EQ( l_candidates, l_knuth.m_candidates.size() );
        ASSERT_EQ( l_candidates, l_knuth.m_unusedCandidates.size() );

        // arbitrarily choose "1123" as the target
        l_board->updateBoard( l_guess, CResult(3,0) );

        l_guess = l_knuth.getGuess();
        ASSERT_EQ(CGuess(3121), l_guess);
        ASSERT_EQ( --l_candidates, l_knuth.m_unusedCandidates.size() );

        l_board->updateBoard( l_guess, CResult(2,2) );

        l_guess = l_knuth.getGuess();

        ASSERT_EQ( --l_candidates, l_knuth.m_unusedCandidates.size() );
        ASSERT_EQ(CGuess(1123), l_guess);
    }
}
