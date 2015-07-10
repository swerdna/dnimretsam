#ifndef MMIND_CCODEBREAKER_H_INCLUDED
#define MMIND_CCODEBREAKER_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include <memory>
#include "MastermindCommonDefines.h"
#include "CGuess.h"

namespace NMasterMind
{

class CBoard;

class CCodeBreaker
{
    public:
        /** Constructor **/
        CCodeBreaker() = default;

        /** Default destructor **/
        virtual ~CCodeBreaker() = default;

        /**
         * Retrieves the next guess from the Code Breaker
         *
         * @param CGuess the guess from the human
         */
        virtual CGuess getGuess() = 0;

        /**
         * Sets the board.
         *
         * @param a_board handle to the board
         */
        void setBoard( std::shared_ptr<CBoard> a_board );

    protected:
        std::shared_ptr< CBoard > m_board;
};

}

#endif  // MMIND_CCODEBREAKER_H_INCLUDED
