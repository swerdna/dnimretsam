#ifndef MMIND_COMMON_DEFS_H_INCLUDED
#define MMIND_COMMON_DEFS_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include <algorithm>

namespace NMasterMind
{

typedef std::array< char , 4 > CGuess;

struct CResult
{
    CResult()
      : m_result( {{'.', '.', '.', '.'}} )
    {}

    bool isWinner() const
    {
        return m_result.end() ==
            std::find_if_not( m_result.begin(), m_result.end(), []( char i) { return 'B' == i; } );
    }
    char &operator[]( size_t i ) { return m_result[i]; }

    std::array< char , 4 > m_result;
};

}

#endif  // MMIND_CGUESS_H_INCLUDED

