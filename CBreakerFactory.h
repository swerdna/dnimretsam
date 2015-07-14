#ifndef MMIND_CBREAKERFACTORY_H_INCLUDED
#define MMIND_CBREAKERFACTORY_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include "ICodeBreaker.h"

namespace NMasterMind
{

enum class EBreaker
{
    EHumanCodeBreaker,
    EKnuthCodeBreaker
};

/**
 * A class to encapsulate the static creation function
 */
class CBreakerFactory
{
    public:
        static ICodeBreaker *createBreaker( EBreaker a_breaker );

        CBreakerFactory() = delete;
        ~CBreakerFactory() = delete;
        CBreakerFactory(const CBreakerFactory &) = delete;
};

}

#endif  // MMIND_CBREAKERFACTORY_H_INCLUDED
