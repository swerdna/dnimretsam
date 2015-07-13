#include "gtest/gtest.h"
#include <array>
#include "CResult.h"
#include "CGuess.h"

using namespace NMasterMind;

TEST(Guess, Init)
{
    CGuess l_guess(1122);

    ASSERT_EQ( std::string("1 1 2 2 "), l_guess.toString() );

    l_guess.fromString("3415");
    ASSERT_EQ( std::string("3 4 1 5 "), l_guess.toString() );

    ++l_guess;
    ASSERT_EQ( std::string("3 4 1 6 "), l_guess.toString() );

    ++l_guess;
    ASSERT_EQ( 6, ctPegs );
    ASSERT_EQ( std::string("3 4 2 1 "), l_guess.toString() );

    ASSERT_EQ( ctSlots, l_guess.size() );
}

TEST(Guess, Compare)
{
    const std::array< std::array<int, 4>, 5 > l_tests = {{
        {{ 1122, 1122, 4, 0 }},
        {{ 1122, 3344, 0, 0 }},
        {{ 1234, 5566, 0, 0 }},
        {{ 1122, 2211, 0, 4 }},
        {{ 1122, 1212, 2, 2 }}
        }};

    for ( auto &&i : l_tests )
    {
        const CGuess l_guess( i[0] );
        const CGuess l_code( i[1] );
        const CResult l_result( i[2], i[3] );

        ASSERT_EQ( l_result, l_guess.compare(l_code) );
    }
}
