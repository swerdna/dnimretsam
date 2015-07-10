#ifndef MMIND_CCODEBREAKER_H_INCLUDED
#define MMIND_CCODEBREAKER_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

namespace NMasterMind
{

/**
 * Abstract, but does contain one data member
 */
class CCodeBreaker
{
    public:
        /** Default destructor **/
        virtual ~CCodeBreaker() = default;

        /**
         * Retrieves the next guess from the Code Breaker
         *
         * @param CGuess the guess
         */
        virtual CGuess getGuess() const = 0;

        /**
         * Sets a handle to the board.
         *
         * @param a_board the board.
         */
        virtual void setBoard( std::shared_ptr<CBoard> a_board );
    protected:
        
        /** Handle to the board **/
        const std::shared_ptr<CBoard> m_board;
};

}

#endif  // MMIND_CCODEBREAKER_H_INCLUDED
