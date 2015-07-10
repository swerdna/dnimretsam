/**
 * Copyright 2015 Bob Andrews
 */

#include "CCodeMaster.h"

namespace NMasterMind
{

//----------------------------------------------------------------------------//

void CCodeMaster::createCode()
{
    // The mersenne twister may be overkill?
    std::mt19937_64 l_rng;

    l_rng.seed( time(nullptr) );

    for ( auto&& i : m_code )
    {
        i = ( l_rng() % ctPegs ) + '1';
    }
}

//----------------------------------------------------------------------------//

CResult CCodeMaster::evaluateGuess( const CGuess &a_guess ) const
{
    size_t l_outputIdx = 0;
    CResult l_res;

    // Take a copy of the answer, and the code on the stack to make temporary modifications
    CGuess l_guess = a_guess;
    CGuess l_code = m_code;

    // Check exact matches first
    for ( size_t i = 0; i < l_code.size(); ++i )
    {
        // Matches, same position and value.
        if ( l_guess[ i ] == l_code[ i ] )
        {
            l_res[ l_outputIdx++ ] = ctMatchChar;

            // Invalidate this guess so it's not matched again.
            l_guess[ i ] = -1;
            l_code[ i ]  = -2;
        }
    }

    // Check for pegs that match the code, but are transposed
    for ( auto&& l_codePeg : l_code )
    {
        for ( auto&& l_guessPeg : l_guess )
        {
            if ( l_guessPeg == l_codePeg )
            {
                l_res[ l_outputIdx++ ] = ctTransposeChar;

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

std::string CCodeMaster::getCode() const
{
    std::string l_str;
    for ( auto i : m_code )
    {
        l_str += i;
    }
    return l_str;
}

//----------------------------------------------------------------------------//

void CCodeMaster::setCode( const std::string &a_code )
{
    for ( int i = 0; i < ctSlots; ++i )
    {
        m_code[i] = a_code[i];
    }
}

}

