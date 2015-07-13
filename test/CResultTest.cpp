#include "gtest/gtest.h"
#include <vector>
#include <utility>
#include "CResult.h"

using namespace NMasterMind;

TEST(Result, Init)
{
    // Default constructor
    {
        CResult l_result;
        ASSERT_EQ( 0, l_result.getBlack() );
        ASSERT_EQ( 0, l_result.getWhite() );
    }

    // value construction
    std::vector< std::pair< int, int > > l_tests = {{
        std::make_pair( 0, 0 ),
        std::make_pair( 4, 0 ),
        std::make_pair( 0, 4 ),
        std::make_pair( 2, 2 )
    }};

    for (auto &&i : l_tests )
    {
        CResult l_result( i.first, i.second );
        ASSERT_EQ( i.first, l_result.getBlack() );
        ASSERT_EQ( i.second, l_result.getWhite() );
    }
}

TEST(Result, Operators)
{
    // == and != comparisons
    std::vector< std::tuple< CResult, CResult, bool > > l_tests = {{
        std::make_tuple( CResult(0, 0), CResult(0, 0), true ),
        std::make_tuple( CResult(0, 4), CResult(0, 0), false ),
        std::make_tuple( CResult(0, 4), CResult(0, 4), true ),
        std::make_tuple( CResult(3, 1), CResult(3, 0), false ),
        std::make_tuple( CResult(3, 1), CResult(3, 1), true )
    }};

    for (auto &&i : l_tests)
    {
        ASSERT_EQ( std::get<2>(i), std::get<0>(i) == std::get<1>(i) );
        ASSERT_NE( !(std::get<2>(i)), std::get<0>(i) == std::get<1>(i) );
    }
}

TEST(Result, Winner)
{
    CResult l_result(4,0);
    ASSERT_NE( false, l_result.isWinner() );
}

TEST(Result, Modifiers)
{
    CResult l_result(0,0);

    l_result.incrementBlack();

    ASSERT_EQ(1, l_result.getBlack());
    ASSERT_EQ(0, l_result.getWhite());

    l_result.incrementWhite();
    l_result.incrementWhite();

    ASSERT_EQ(1, l_result.getBlack());
    ASSERT_EQ(2, l_result.getWhite());

}
