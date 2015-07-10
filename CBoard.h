#ifndef MMIND_CBOARD_H_INCLUDED
#define MMIND_CBOARD_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include <vector>
#include <tuple>
#include "MastermindCommonDefines.h"
#include "CGuess.h"
#include "CResult.h"

namespace NMasterMind
{

class CBoard
{
    public:
        /** Constructor **/
        CBoard();
        
        /**
         * Displays the board, prints to stdout
         *
         * +---------+---------+
         * | . . . . | . . . . |
         * +---------+---------+
         * | 4 3 2 2 | B B B B |  <== You Win!
         * +---------+---------+
         * | 3 4 2 2 | B B W W |
         * +---------+---------+
         * | 1 1 1 1 | . . . . |
         * +---------+---------+
         * | 1 1 2 2 | B B . . |
         * +---------+---------+
         *
         */
        void display() const;

        /**
         * Adds the guess and the result to the board
         *
         * @param a_guess the guess to add
         * @param a_result the evaluation of the guess
         */
        void updateBoard( const CGuess &a_guess, const CResult &a_result );

        /**
         * Returns a handle to the result of the last guess.
         *
         * @return const CResult * last guess
         */
        const CResult *getLastResult() const;

    private:

        /** A "round" in a guess / result **/
        typedef typename std::tuple< const CGuess, const CResult > tRound;

        /** The guesses **/
        std::vector< tRound > m_guesses;
};

}

#endif  // MMIND_CBOARD_H_INCLUDED
