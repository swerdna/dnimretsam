/**
 * Copyright 2015 Bob Andrews
 */

#include "gtest/gtest.h"
#include "CmdLineParsing.h"

TEST(CmdLine, Usage)
{
    // Ensure the program name is written
    std::ostringstream l_ostr;
    const std::string l_progname = "abcdef";
    NMasterMind::usage( l_progname.c_str(), l_ostr );
    ASSERT_NE( std::string::npos, l_ostr.str().find( l_progname ) );

    // clear the output stream
    l_ostr.str("");

    // Check nullptr is sane
    NMasterMind::usage( nullptr, l_ostr );

    ASSERT_EQ(0,0);
}

TEST(CmdLine, Opts)
{
    // Human
    {
        // reset getopt's global (see man getopt)
        optind = 1;

        char *l_argv[] = { strdup("mastermind") };
        auto l_ret = NMasterMind::checkOpts( 1, l_argv );
        free(l_argv[0]);

        ASSERT_EQ( true, l_ret.first );
        ASSERT_EQ( "", l_ret.second );
    }

    // Machine
    {
        // reset getopt's global (see man getopt)
        optind = 1;

        char *l_argv[] = { strdup("mastermind"), strdup("-c"), strdup("1234") };
        auto l_ret = NMasterMind::checkOpts( 3, l_argv );
        for (int i=0; i < 3; ++i)
        {
            free(l_argv[i]);
        }

        ASSERT_EQ( true, l_ret.first );
        ASSERT_EQ( "1234", l_ret.second );
    }

    // Machine, missing code
    {
        // reset getopt's global (see man getopt)
        optind = 1;

        char *l_argv[] = { strdup("mastermind"), strdup("-c") };
        auto l_ret = NMasterMind::checkOpts( 2, l_argv );
        for (int i=0; i < 2; ++i)
        {
            free(l_argv[i]);
        }

        ASSERT_EQ( false, l_ret.first );
        ASSERT_EQ( "", l_ret.second );

    }

    // Machine, bad codes
    {
        const std::vector< const char * > l_badCodes = {{
            "9999", "0123", "1", "98972341324", "12345"
        }};

        char *l_argv[3] = { strdup("mastermind"), strdup("-c"), nullptr };

        for (auto &&i : l_badCodes)
        {
            // reset getopt's global (see man getopt)
            optind = 1;

            l_argv[2] = strdup( i );

            auto l_ret = NMasterMind::checkOpts( 3, l_argv );
            ASSERT_EQ( false, l_ret.first );
            ASSERT_EQ( "", l_ret.second );

            free( l_argv[2] );
            l_argv[2] = nullptr;
        }

        for (int i=0; i < 2; ++i)
        {
            free(l_argv[i]);
        }

    }
}

