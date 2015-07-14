#ifndef MMIND_CGUESS_H_INCLUDED
#define MMIND_CGUESS_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include <array>

#include "MastermindCommonDefines.h"
#include "CResult.h"

namespace NMasterMind
{

class CGuess
{
    public:
        /** Default constructor **/
        CGuess();

        /**
         * Creates a guess from a number
         *
         * @param a_int the number
         **/
        explicit CGuess(int a_int);

        /**
         * Force a default move constructor, and a copy constructor.
         * Should be implicit.
         */
        CGuess( CGuess && ) = default;
        CGuess( const CGuess & ) = default;
        CGuess &operator=( const CGuess & ) = default;

        /**
         * To support being in an ordered container
         *
         * @param a_rhs the right hand side
         * @return true if this object is logically less than a_rhs
         **/
        bool operator<( const CGuess &a_rhs ) const;

        /**
         * Equality
         *
         * @param a_rhs the right hand side
         * @return true if these objects are equivalent
         **/
        bool operator==( const CGuess &a_rhs ) const;

        /**
         * The number of elements in the underlying array
         *
         * @return the size
         **/
        size_t size() const;

        /**
         * (preincrement) Returns the next guess in the sequence
         * (e.g. from 1111, through 6666, skipping digits 7,8,9).
         *
         * @return this
         **/
        CGuess &operator++();

        /**
         * Returns a string representatoin of this guess.
         * format (e.g.)   "1 1 2 2 "
         *
         * @return formatted string
         */
        std::string toString() const;

        /**
         * populates m_guess from the string.
         * precondition: the string must be 'ctSlots' characters long
         *               and each character is a digit from 1 to 'ctPegs'
         *
         * @param a_str the valid string representing a guess
         */
        void fromString( const std::string &a_str );

        /**
         * Compares two guesses, vis-a-vis mastermind rules
         *
         * @param a_other the other code / guess
         * @return CResult the count of black and white pins.
         */
        CResult compare( const CGuess &a_other ) const;

    private:
       // A friendly outputter
       friend std::ostream &operator <<( std::ostream &a_str, const CGuess &a_guess );

        /** the guess **/
       std::array< char, ctSlots > m_guess;
};

}

#endif  // MMIND_CRESULT_H_INCLUDED
