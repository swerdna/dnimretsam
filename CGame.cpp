/**
 * Copyright 2015 Bob Andrews
 */

#include "CGame.h"

#include <iostream>

#include "CBoard.h"
#include "CCodeMaster.h"
#include "CKnuthCodeBreaker.h"
#include "CHumanCodeBreaker.h"
#include "MastermindCommonDefines.h"

namespace NMasterMind
{

//----------------------------------------------------------------------------//

CGame::CGame( const std::string &a_code )
  : m_board  ( new CBoard )
  , m_master ( new CCodeMaster )
{
    // TODO: better validation for this input
    // TODO: Could be a factory.
    if (ctSlots == a_code.size())
    {
        m_master->setCode( a_code );
        m_breaker.reset(new CKnuthCodeBreaker);
    }
    else
    {
        m_master->createCode();
        m_breaker.reset(new CHumanCodeBreaker);
    }

    m_breaker->setBoard( m_board );
}

//----------------------------------------------------------------------------//

CGame::~CGame()
{
}

//----------------------------------------------------------------------------//

EGameResult CGame::playGame()
{
    bool l_won = false;
    int i = 0;

    for (; i < ctMaxRounds && false == l_won; ++i)
    {
        std::cout << "Round " << i + 1 << std::endl;
        m_board->display( std::cout );

        CGuess l_guess = m_breaker->getGuess();

        auto l_result = m_master->evaluateGuess( l_guess );

        m_board->updateBoard( l_guess, l_result );

        l_won = l_result.isWinner();
    }

    m_board->display( std::cout );

    if (false == l_won)
    {
        std::cout << "CodeMaster won! Secret code: " << m_master->getCode() << std::endl;
        // Codemaster gets an extra point if the code was unguessed.
        ++i;
    }
    std::cout << "CodeMaster's score: " << i << std::endl;

    return l_won ? EGameResult::CodeBreakerWon : EGameResult::CodeMasterWon;
}

}
