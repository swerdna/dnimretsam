#ifndef MMIND_CRESULT_H_INCLUDED
#define MMIND_CRESULT_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include "MastermindCommonDefines.h"
#include <ostream>

namespace NMasterMind
{

class CResult
{
    public:
        /** Constructor **/
        CResult();
 
        /**
         * Initializing constructor
         *
         * @param a_black the number of black pegs
         * @param a_white the number of white pegs
         **/
        CResult( int a_black, int a_white );

        /**
         * Force a default move constructor, and a copy constructor.
         * Should be implicit.
         */
        CResult( CResult && ) = default;
        CResult( const CResult & ) = default;

        /**
         * Inequality operator
         *
         * @param a_rhs the result to compare with
         * @return true if these objects are not equivalent
         **/
        bool operator != (const CResult &a_rhs) const;

        /**
         * Equality operator
         *
         * @param a_rhs the result to compare with
         * @return true if these objects are equivalent
         **/
        bool operator == (const CResult &a_rhs) const;

        /**
         * Do we have a winner?
         *
         * @return true if all blacks
         */
        bool isWinner() const;

        /** Adds a black pin to the result */
        void incrementBlack();

        /** Adds a white pin to the result */
        void incrementWhite();

        /**
         * Getter for the number of white pins
         *
         * @return count of white pins
         */
        int getWhite() const;

        /**
         * Getter for the number of black pins
         *
         * @return count of black pins
         */
        int getBlack() const;

    private:
        // A friendly outputter
        friend std::ostream &operator <<( std::ostream &ar_str, const CResult &a_guess );

        int m_black;
        int m_white;
};

}

#endif  // MMIND_CRESULT_H_INCLUDED

