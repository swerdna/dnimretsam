/**
 * Copyright 2015 Bob Andrews
 */

#include "gtest/gtest.h"
#include "CBreakerFactory.h"
#include "CHumanCodeBreaker.h"
#include "CKnuthCodeBreaker.h"

TEST(BreakerFactory, Creation)
{
    using namespace NMasterMind;
    static_assert( false == std::is_constructible< NMasterMind::CBreakerFactory >::value, "The factory shouldn't be constructible" );
    // human
    {
        ICodeBreaker *lp_breaker = CBreakerFactory::createBreaker( EBreaker::EHumanCodeBreaker );

        EXPECT_NE(nullptr, lp_breaker);
        ASSERT_NE(nullptr, dynamic_cast< CHumanCodeBreaker * >(lp_breaker) );
    }
    // algorithm
    {
        ICodeBreaker *lp_breaker = CBreakerFactory::createBreaker( EBreaker::EKnuthCodeBreaker );

        EXPECT_NE(nullptr, lp_breaker);
        ASSERT_NE(nullptr, dynamic_cast< CKnuthCodeBreaker * >( lp_breaker ));
    }
}

