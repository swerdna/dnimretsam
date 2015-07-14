#ifndef MMIND_ICODEBREAKER_H_INCLUDED
#define MMIND_ICODEBREAKER_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

namespace NMasterMind
{

class CGuess;
class CResult;

class ICodeBreaker
{
    public:
        /** Default destructor **/
        virtual ~ICodeBreaker() = default;

        /**
         * Retrieves the next guess from the Code Breaker
         *
         * @param CGuess the guess from the human
         */
        virtual CGuess getGuess(const CResult &) = 0;
};

}

#endif  // MMIND_ICODEBREAKER_H_INCLUDED
