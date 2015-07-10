#ifndef MMIND_CKNUTHCODEBREAKER_H_INCLUDED
#define MMIND_CKNUTHCODEBREAKER_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include "CCodeBreaker.h"
#include "MastermindCommonDefines.h"

namespace NMasterMind
{

class CKnuthCodeBreaker : public CCodeBreaker
{
    public:
        CKnuthCodeBreaker();

        /** Default destructor **/
        ~CKnuthCodeBreaker() = default;

        /**
         * Retrieves the next guess from the Code Breaker
         *
         * @param CGuess the guess from the human
         */
        CGuess getGuess() const

    private:

        /**
         * Initialize the candidates
         */
        void initCandidates();

        // The remaining candidates (S)
        std::set< CGuess > m_candidates;

        // The unused candidates
        std::set< CGuess > m_unusedCandidates;

        CGuess m_lastGuess;
};

}
