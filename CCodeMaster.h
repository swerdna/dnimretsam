#ifndef MMIND_CCODEMASTER_H_INCLUDED
#define MMIND_CCODEMASTER_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include "MastermindCommonDefines.h"
#include "CGuess.h"
#include "CResult.h"

namespace NMasterMind
{

class CCodeMaster
{
    public:
        CCodeMaster() = default;

        /** Creates and remembers a code **/
        void createCode();

        /**
         * Evaluates a guess, returning 'B' for matching pegs in correct slots,
         * 'W' for pegs that match the code, but are in a wrong location.
         *
         * See wikipedia, Mastermind, for more.
         *
         * @param a_guess 
         * @return CResult the result of the evaluation
         */
        CResult evaluateGuess( const CGuess &a_guess ) const;

        /**
         * Getter for the code, formatted as a string
         *
         * @return std::string the secret code.
         */
        std::string getCode() const;

        /**
         * Setter for a code
         *
         * @param a_code the code to use
         */
        void setCode( const std::string &a_code );

    private:

        // The selected code
        CGuess m_code;
};

}

#endif  // MMIND_CCODEMASTER_H_INCLUDED
