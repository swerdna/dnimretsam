/**
 * Copyright 2015 Bob Andrews
 */

#include "CGuess.h"
#include <cmath>

namespace NMasterMind
{

//----------------------------------------------------------------------------//

CGuess::CGuess()
{
    // leave m_guess uninitialized
}

//----------------------------------------------------------------------------//

CGuess::CGuess(int a_int)
{
    int l_divisor = pow(10, ctSlots - 1);
    for ( auto&& i : m_guess )
    {
        i = '0' + a_int / l_divisor;
        a_int %= l_divisor;
        l_divisor /= 10;
    }
}

//----------------------------------------------------------------------------//

void CGuess::fromString( const std::string &a_str )
{
    // TODO: str validation.
    for ( int i = 0; i < ctSlots; ++i )
    {
        m_guess[i] = a_str[i];
    }
}

//----------------------------------------------------------------------------//

bool CGuess::operator<( const CGuess &a_rhs ) const
{
    for (int i = ctSlots - 1; i >= 0; --i)
    {
        if (m_guess[i] > a_rhs.m_guess[i])
        {
            return false;
        }
        else if (m_guess[i] < a_rhs.m_guess[i])
        {
            return true;
        }
    }
    // equal
    return false;
}

//----------------------------------------------------------------------------//

size_t CGuess::size() const
{
    return ctSlots;
}

//----------------------------------------------------------------------------//

std::string CGuess::toString() const
{
    std::string l_str;
    for (auto i : m_guess)
    {
        l_str += i;
        l_str += ' ';
    }
    return l_str;
}

//----------------------------------------------------------------------------//

CResult CGuess::compare( const CGuess &a_other ) const
{
    CResult l_res;

    // Take a copy of the answer, and the code on the stack to make temporary modifications
    CGuess l_guess = a_other;
    CGuess l_code = *this;

    // Check exact matches first
    for ( size_t i = 0; i < l_code.size(); ++i )
    {
        // Matches, same position and value.
        if ( l_guess.m_guess[ i ] == l_code.m_guess[ i ] )
        {
            l_res.incrementBlack();

            // Invalidate this guess so it's not matched again.
            l_guess.m_guess[ i ] = -1;
            l_code.m_guess[ i ]  = -2;
        }
    }

    // Check for pegs that match the code, but are transposed
    for ( int i = 0; i < ctSlots; ++i)
    {
        char &l_codePeg = l_code.m_guess[i];
        for (int j = 0; j < l_guess.size(); ++j)
        {
            char &l_guessPeg = l_guess.m_guess[j];
            if ( l_guessPeg == l_codePeg )
            {
                l_res.incrementWhite();

                // Invalidate this guess so it's not matched again.
                l_guessPeg = -1;
                l_codePeg  = -2;
                break;
            }
        }
    }
    return l_res;
}

//----------------------------------------------------------------------------//

std::ostream &operator <<( std::ostream &a_str, const CGuess &a_res )
{
    a_str << a_res.toString();
    return a_str;
}

//----------------------------------------------------------------------------//

CGuess &CGuess::operator++()
{
    auto l_iter = m_guess.rbegin();
    auto l_endIter = m_guess.rend();

    do
    {
        ++(*l_iter);
        if (ctPegs < (*l_iter) - '0')
        {
            *l_iter = '1';
        }
        else
        {
            break;
        }
    }
    while (++l_iter != l_endIter);
    return *this;
}

}

