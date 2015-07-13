/**
 * Copyright 2015 Bob Andrews
 */

#include "gtest/gtest.h"
#include "CGame.h"
#include "CGame.h"

TEST( Game, Init )
{
    using namespace NMasterMind;

    static_assert( false == std::is_copy_constructible< CGame >::value
                && false == std::is_copy_assignable< CGame >::value, "CGame shouldn't be copyable" );

    {
        // Knuth will always win in <= 5 moves.
        CGame l_game( "1234" );

        ASSERT_NE( nullptr, l_game.m_board );
        ASSERT_NE( nullptr, l_game.m_master );
        ASSERT_NE( nullptr, l_game.m_breaker );

        ASSERT_EQ( CodeBreakerWon, l_game.playGame() );
    }
    {
        CGame l_game( "" );

        ASSERT_NE( nullptr, l_game.m_board );
        ASSERT_NE( nullptr, l_game.m_master );
        ASSERT_NE( nullptr, l_game.m_breaker );
    }
}
