/**
 * Copyright 2015 Bob Andrews
 */

#include "gtest/gtest.h"
#include "CBoard.h"
#include "CResult.h"
#include "CGuess.h"

using namespace NMasterMind;

TEST(Board, Init)
{
    NMasterMind::CBoard l_board;
    ASSERT_EQ( 0, l_board.m_guesses.size() );

    // display, just to ensure no crash
    // capture in a string, to avoid polluting console
    std::ostringstream l_oss;
    l_board.display( l_oss );
}

TEST(Board, Updates)
{
    NMasterMind::CBoard l_board;

    ASSERT_EQ( 0, l_board.m_guesses.size() );

    l_board.updateBoard( CGuess(1122), CResult(4,0) );

    ASSERT_NE( nullptr, l_board.getLastResult() );

    const CResult *lp_lastResult = l_board.getLastResult();

    ASSERT_EQ( 4, lp_lastResult->getBlack() );
    ASSERT_EQ( 0, lp_lastResult->getWhite() );
}
