#ifndef MMIND_CGUESS_H_INCLUDED
#define MMIND_CGUESS_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

namespace NMasterMind
{

/**
 * A POD representing a guess
 */
struct CGuess
{
    std::array< int , 4 > m_guess;
};

}

#endif  // MMIND_CGUESS_H_INCLUDED
