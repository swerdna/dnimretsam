#ifndef MMIND_CCODEMASTER_H_INCLUDED
#define MMIND_CCODEMASTER_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include "MastermindCommonDefines.h"

namespace NMasterMind
{

class CCodeMaster
{
    public:
        void createCode()
        {
            std::mt19937_64 l_rng;
            l_rng.seed( time(NULL) );

            for ( auto&& i : m_code )
            {
                i = (l_rng() % 6) + '1';
            }
            // m_code = { { '1', '1', '2', '2' } };
        }

        CResult evaluateGuess( const CGuess &a_guess ) const
        {
            size_t l_outputIdx = 0;
            CResult l_res;

            // Take a copy of the answer, and the code on the stack to make temporary modifications
            CGuess l_guess = a_guess;
            CGuess l_code = m_code;

            // Check exact matches first
            for ( size_t i = 0; i < l_code.size(); ++i)
            {
                // Matches, same position and value.
                if (l_guess[i] == l_code[i])
                {
                    l_res[ l_outputIdx++ ] = 'B';
                    // Invalidate this guess so it's not matched again.
                    l_guess[i] = -1;
                    l_code[i] = -2;
                }
            }
            for ( size_t i = 0; i < l_code.size(); ++i)
            {
                for (size_t j = 0; j < l_guess.size(); ++j)
                {
                    if (l_guess[j] == l_code[i])
                    {
                        l_res[ l_outputIdx++ ] = 'W';
                        // Invalidate this guess so it's not matched again.
                        l_guess[j] = -1;
                        l_code[i] = -2;
                        break;
                    }
                }
            }
            return l_res;
        }

        std::string getCode() const
        {
            std::string l_str;
            for ( auto i : m_code )
            {
                l_str += i;
            }
            return l_str;
        }

    private:
        // The selected code
        CGuess m_code;
};

}

#endif  // MMIND_CCODEMASTER_H_INCLUDED
