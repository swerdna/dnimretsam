/**
 * Copyright 2015 Bob Andrews
 */

#include "gtest/gtest.h"
#include "CCodeMaster.h"

TEST(CodeMaster, Ops)
{
    using namespace NMasterMind;
    CCodeMaster l_master;

    CGuess l_guess( 1234 );
    l_master.setCode( "1234" );
    ASSERT_EQ( "1 2 3 4 ", l_master.getCode() );

    ASSERT_EQ( CResult(4, 0), l_master.evaluateGuess( l_guess ) );

    CGuess l_guess2( 5656 );
    ASSERT_EQ( CResult(0, 0), l_master.evaluateGuess( l_guess2 ) );

    CGuess l_guess3( 4321 );
    ASSERT_EQ( CResult(0, 4), l_master.evaluateGuess( l_guess3 ) );

    // Note, more comprehensive guess evaluation testing in CGuessTest
}
