#ifndef MMIND_CCODEBREAKER_H_INCLUDED
#define MMIND_CCODEBREAKER_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include "MastermindCommonDefines.h"

namespace NMasterMind
{

class CBoard;

class CCodeBreaker
{
    public:
        CCodeBreaker( std::shared_ptr<CBoard> a_board)
          : m_board(a_board)
        {}

        CGuess getGuess() const
        {
            std::string l_str;
            do
            {
                std::cout << "Next guess? (4 digits, from 1 to 6): " << std::flush;
                std::cin >> l_str;
            } while (!checkInput( l_str ));

            CGuess l_guess;
            for (int i = 0; i < 4; ++i)
            {
                l_guess[i] = l_str[i];
            }
            return l_guess;
        }

    private:
        static bool checkInput( const std::string &a_input)
        {
            bool l_result = 4 == a_input.size();
            l_result &= std::string::npos == a_input.find_first_not_of( "123456" );
            return l_result;
        }

        const std::shared_ptr<CBoard> m_board;
};

}

#endif  // MMIND_CCODEBREAKER_H_INCLUDED
