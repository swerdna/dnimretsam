/**
 * Copyright 2015 Bob Andrews
 */

#include "CBreakerFactory.h"
#include "CKnuthCodeBreaker.h"
#include "CHumanCodeBreaker.h"

namespace NMasterMind
{

//----------------------------------------------------------------------------//
//static 
ICodeBreaker *CBreakerFactory::createBreaker( EBreaker a_breaker )
{
    ICodeBreaker *lp_breaker = nullptr;
    switch (a_breaker)
    {
        case (EBreaker::EHumanCodeBreaker):
            lp_breaker = new CHumanCodeBreaker;
            break;
        case (EBreaker::EKnuthCodeBreaker):
            lp_breaker = new CKnuthCodeBreaker;
            break;
        default:
            break;
    }
    return lp_breaker;
}

}
