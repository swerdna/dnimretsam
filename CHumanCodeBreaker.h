#ifndef MMIND_CHUMANCODEBREAKER_H_INCLUDED
#define MMIND_CHUMANCODEBREAKER_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include "CCodeBreaker.h"
#include "MastermindCommonDefines.h"

class HumanBreaker_InputValidation_Test;

namespace NMasterMind
{

class CBoard;

class CHumanCodeBreaker : public CCodeBreaker
{
    public:
        /** Constructor **/
        CHumanCodeBreaker() = default;

        /** Default destructor **/
        virtual ~CHumanCodeBreaker() = default;

        /**
         * Retrieves the next guess from the Code Breaker
         *
         * @param CGuess the guess from the human
         */
        CGuess getGuess() override;

    private:
        /**
         * Helper to validate input.
         *
         * @param a_input the string that came from the user
         * @return bool true if the input matches.
         */ 
        static bool checkInput( const std::string &a_input);

        friend class ::HumanBreaker_InputValidation_Test;
};

}

#endif  // MMIND_CCODEBREAKER_H_INCLUDED
