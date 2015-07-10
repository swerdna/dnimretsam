#ifndef MMIND_COMMON_DEFS_H_INCLUDED
#define MMIND_COMMON_DEFS_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include <algorithm>

namespace NMasterMind
{

// Static defines / constants
static const size_t ctMaxRounds     = 12;
static const size_t ctSlots         = 4;
static const int    ctPegs          = 6;
static const char   ctPadChar       = '.';
static const char   ctMatchChar     = 'B';
static const char   ctTransposeChar = 'W';

typedef std::array< char , ctSlots > CGuess;

struct CResult
{
    CResult()
    {
        std::fill( m_result.begin(), m_result.end(), ctPadChar );
    }

    bool isWinner() const
    {
        // If this result only contains 'B's, we have a winner.
        return m_result.end() ==
            std::find_if_not( m_result.begin(), m_result.end(),
                              []( char i) { return ctMatchChar == i ; }
                            );
    }

    char &operator[]( size_t i ) { return m_result[i]; }

    std::array< char , ctSlots > m_result;
};

}

#endif  // MMIND_CGUESS_H_INCLUDED

