#ifndef MMIND_CKNUTHCODEBREAKER_H_INCLUDED
#define MMIND_CKNUTHCODEBREAKER_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */
#include <set>

#include "ICodeBreaker.h"
#include "MastermindCommonDefines.h"
#include "CGuess.h"

class KnuthBreaker_Init_Test;
class KnuthBreaker_Guess_Test;

namespace NMasterMind
{

class CKnuthCodeBreaker : public ICodeBreaker
{
    public:
        CKnuthCodeBreaker() = default;

        /** Default destructor **/
        ~CKnuthCodeBreaker() = default;

        /**
         * Retrieves the next guess from the Code Breaker
         *
         * @param CGuess the guess from the human
         */
        CGuess getGuess(const CResult &) override;

    private:

        /**
         * Initialize the candidates
         */
        void initCandidates();

        // The remaining candidates
        std::set< CGuess > m_candidates;

        // The unused candidates
        std::set< CGuess > m_unusedCandidates;

        CGuess m_lastGuess;

        friend class ::KnuthBreaker_Init_Test;
        friend class ::KnuthBreaker_Guess_Test;
};

}

#endif  // MMIND_CKNUTHCODEBREAKER_H_INCLUDED
