/**
 * Copyright 2015 Bob Andrews
 */

#include "CCodeMaster.h"
#include <utility>
#include <random>

namespace NMasterMind
{

//----------------------------------------------------------------------------//

void CCodeMaster::createCode()
{
    // The mersenne twister may be overkill?
    std::mt19937_64 l_rng;

    l_rng.seed( time(nullptr) );

    int l_code = 0;
    for (int i = 0; i < ctSlots; ++i )
    {
        l_code *= 10;
        l_code += 1 + l_rng() % ctPegs;
    }

    CGuess l_guess( l_code );

    std::swap( m_code, l_guess );
}

//----------------------------------------------------------------------------//

CResult CCodeMaster::evaluateGuess( const CGuess &a_guess ) const
{
    return m_code.compare( a_guess );
}

//----------------------------------------------------------------------------//

std::string CCodeMaster::getCode() const
{
    return m_code.toString();
}

//----------------------------------------------------------------------------//

void CCodeMaster::setCode( const std::string &a_code )
{
    m_code.fromString( a_code );
}

}

