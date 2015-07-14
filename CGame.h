#ifndef MMIND_CGAME_H_INCLUDED
#define MMIND_CGAME_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include <memory>

class Game_Init_Test;

namespace NMasterMind
{

class CBoard;
class ICodeBreaker;
class CCodeMaster;

enum EGameResult
{
    CodeBreakerWon,
    CodeMasterWon
};

class CGame
{
    public:
        /** Constructor **/
        CGame( const std::string &a_code );

        /** Destructor **/
        ~CGame();

        /** Disallow copying, assignment **/
        CGame( CGame const & ) = delete;
        void operator=( CGame const & ) = delete;

        /**
         * Runs a game.  The return value is the winner.
         *
         * @return EGameResult - the result of the game
         */
        EGameResult playGame();

    private:
        /** The board **/
        std::shared_ptr< CBoard > m_board;

        /** The codemaster **/
        std::unique_ptr< CCodeMaster > m_master;

        /** The codebreaker **/
        std::unique_ptr< ICodeBreaker > m_breaker;

        friend class ::Game_Init_Test;
};

}

#endif  // MMIND_CGAME_H_INCLUDED
