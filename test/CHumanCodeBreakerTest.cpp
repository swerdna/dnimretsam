/**
 * Copyright 2015 Bob Andrews
 */

#include "gtest/gtest.h"
#include "CHumanCodeBreaker.h"

TEST(HumanBreaker, InputValidation)
{
    const std::vector< std::string > l_goodStrings( {{ "1234", "1111", "6666", "6543" }} );
    const std::vector< std::string > l_badStrings  {{ "", "111", "1237", "abdc", "ABCD", "12345" }};

    for (auto &&i : l_goodStrings)
    {
        ASSERT_NE(false, NMasterMind::CHumanCodeBreaker::checkInput( i ));
    }

    for (auto &&i : l_badStrings)
    {
        ASSERT_EQ(false, NMasterMind::CHumanCodeBreaker::checkInput( i ));
    }
}
