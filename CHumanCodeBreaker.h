#ifndef MMIND_CHUMANCODEBREAKER_H_INCLUDED
#define MMIND_CHUMANCODEBREAKER_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include "CCodeBreaker.h"
#include "MastermindCommonDefines.h"

namespace NMasterMind
{

class CBoard;

class CHumanCodeBreaker : public CCodeBreaker
{
    public:
        /** Constructor **/
        CHumanCodeBreaker();

        /** Default destructor **/
        ~CHumanCodeBreaker() = default;

        /**
         * Retrieves the next guess from the Code Breaker
         *
         * @param CGuess the guess from the human
         */
        CGuess getGuess() const

    private:
        /**
         * Helper to validate input.
         *
         * @param a_input the string that came from the user
         * @return bool true if the input matches.
         */ 
        static bool checkInput( const std::string &a_input)
};

}

#endif  // MMIND_CCODEBREAKER_H_INCLUDED
