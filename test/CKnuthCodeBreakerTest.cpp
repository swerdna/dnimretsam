/**
 * Copyright 2015 Bob Andrews
 */

#include "gtest/gtest.h"
#include <cmath>
#include "CKnuthCodeBreaker.h"

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
        CKnuthCodeBreaker l_knuth;

        ASSERT_EQ( 0, l_knuth.m_candidates.size() );
        ASSERT_EQ( 0, l_knuth.m_unusedCandidates.size() );

        // The first guess is always "1122"
        CGuess l_guess = l_knuth.getGuess( CResult(0,0) );

        // Check that the guess is 1122
        ASSERT_EQ(CGuess(1122), l_guess);

        // The number of candidates after the first guess
        int l_candidates = pow( ctPegs, ctSlots ) - 1;

        ASSERT_EQ( l_candidates, l_knuth.m_candidates.size() );
        ASSERT_EQ( l_candidates, l_knuth.m_unusedCandidates.size() );

        // arbitrarily choose "1123" as the target

        l_guess = l_knuth.getGuess( CResult(3,0) );

        ASSERT_EQ(CGuess(3121), l_guess);
        ASSERT_EQ( --l_candidates, l_knuth.m_unusedCandidates.size() );

        l_guess = l_knuth.getGuess( CResult(2,2) );

        ASSERT_EQ( --l_candidates, l_knuth.m_unusedCandidates.size() );
        ASSERT_EQ(CGuess(1123), l_guess);
    }
}
