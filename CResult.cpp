/**
 * Copyright 2015 Bob Andrews
 */

#include "CResult.h"

namespace NMasterMind
{

//----------------------------------------------------------------------------//

CResult::CResult()
    : m_black(0)
    , m_white(0)
{
}

//----------------------------------------------------------------------------//

CResult::CResult( int a_black, int a_white )
    : m_black(a_black)
    , m_white(a_white)
{
}

//----------------------------------------------------------------------------//

bool CResult::operator != (const CResult &a_rhs) const
{
    return m_black != a_rhs.m_black
        || m_white != a_rhs.m_white;
}

//----------------------------------------------------------------------------//

bool CResult::isWinner() const
{
    return m_black == ctSlots;
}

//----------------------------------------------------------------------------//

void CResult::incrementBlack()
{
    ++m_black;
}

//----------------------------------------------------------------------------//

void CResult::incrementWhite()
{
    ++m_white;
}

//----------------------------------------------------------------------------//

std::ostream &operator <<( std::ostream &ar_str, const CResult &a_res )
{
    for (int i = 0; i < a_res.m_black; ++i)
    {
        ar_str << ctMatchChar << ' ';
    }
    for (int i = 0; i < a_res.m_white; ++i)
    {
        ar_str << ctTransposeChar << ' ';
    }
    for (int i = ctSlots - a_res.m_white - a_res.m_black; i > 0; --i)
    {
        ar_str << ctPadChar << ' ';
    }
    return ar_str;
}

int CResult::getWhite() const
{
    return m_white;
}

int CResult::getBlack() const
{
    return m_black;
}

}

