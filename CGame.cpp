/**
 * Copyright 2015 Bob Andrews
 */

#include "CGame.h"
#include "CBoard.h"
#include "CCodeMaster.h"
#include "CKnuthCodeBreaker.h"
#include "CHumanCodeBreaker.h"
#include "MastermindCommonDefines.h"

namespace NMasterMind
{

CGame::CGame( const std::string &a_code )
  : m_board  ( new CBoard )
  , m_master ( new CCodeMaster )
  , m_breaker( new CCodeBreaker( m_board ) )
{
    // TODO: better validation for this input
    // TODO: Could be a factory.
    if (ctSlots == a_code.size())
    {
        m_master->setCode( a_code );
        m_breaker = new CKnuthCodeBreaker( m_board );
    }
    else
    {
        m_breaker = new CCodeBreaker( m_board );
    }

    // TODO: Configuration
}

CGame::~CGame()
{
}

EGameResult CGame::playGame()
{
    m_master->createCode();
    bool l_won = false;

    int i = 0;
    for (; i < 12 && false == l_won; ++i)
    {
        m_board->display();

        CGuess l_guess = m_breaker->getGuess();

        auto l_result = m_master->evaluateGuess( l_guess );

        m_board->updateBoard( l_guess, l_result );

        l_won = l_result.isWinner();
    }

    m_board->display();

    if (false == l_won)
    {
        std::cout << "CodeMaster won! Secret code: " << m_master->getCode() << std::endl;
        // Codemaster gets an extra point if the code was unguessed.
        ++i;
    }
    std::cout << "CodeMaster's score: " << ++i << std::endl;

    return EGameResult::CodeBreakerWon;
}

}
