#ifndef MMIND_CBOARD_H_INCLUDED
#define MMIND_CBOARD_H_INCLUDED

/**
 * Copyright 2015 Bob Andrews
 */

#include <iostream>
#include <vector>
#include "MastermindCommonDefines.h"

namespace NMasterMind
{

class CBoard
{
    public:
        CBoard()
        {
            m_guesses.reserve(12);
        }

        void display() const
        {
            for (int i=12; i > m_guesses.size(); --i)
            {
                std::cout << "+---------+---------+\n"
                          << "| . . . . | . . . . |\n";
            }
            auto l_iter = m_guesses.rbegin();
            auto l_endIter = m_guesses.rend();
            for ( ; l_iter != l_endIter; ++l_iter)
            {
                std::cout << "+---------+---------+\n"
                          << "| ";

                for (auto &&j : std::get<0>(*l_iter))
                {
                    std::cout << j << ' ';
                }
                std::cout<< "| ";
                        
                for (auto &&j : std::get<1>(*l_iter).m_result)
                {
                    std::cout << j << ' ';
                }

                std::cout<< "|";
                if (std::get<1>(*l_iter).isWinner())
                {
                    std::cout << " <--- You Win, Congratulations!";
                }
                std::cout << '\n';
            }

            std::cout << "+---------+---------+" << std::endl; 
        }

        void updateBoard( const CGuess &a_guess, const CResult &a_result )
        {
            // Copies the guess and result into the board.
            m_guesses.push_back( std::tuple< const CGuess, const CResult>(a_guess, a_result) );
        }
    private:
        std::vector< std::tuple< const CGuess, const CResult > > m_guesses;

};

}

#endif  // MMIND_CBOARD_H_INCLUDED
