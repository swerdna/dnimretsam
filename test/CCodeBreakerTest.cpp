/**
 * Copyright 2015 Bob Andrews
 */

#include "gtest/gtest.h"
#include "CHumanCodeBreaker.h"
#include "CBoard.h"
#include <memory>

TEST(CodeBreaker, SetBoard)
{
    using namespace NMasterMind;
    std::shared_ptr< CBoard > lp_board ( new CBoard );

    // CodeBreaker is abstract, but has one implemented function - setBoard
    CHumanCodeBreaker l_human;
    l_human.setBoard( lp_board );

    CCodeBreaker *lp_parent = dynamic_cast<CCodeBreaker*>(&l_human);

    ASSERT_NE(nullptr, lp_parent);
    ASSERT_EQ( lp_board, lp_parent->m_board );
}
