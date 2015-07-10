cmake_minimum_required( VERSION 2.8.3 )

project( mastermind )
set ( MMIND_SRCS
      CGame.cpp
      CBoard.cpp
      CCodeMaster.cpp
      CCodeBreaker.cpp
      mastermind.cpp
      CHumanCodeBreaker.cpp
      CKnuthCodeBreaker.cpp
      CResult.cpp
      CGuess.cpp
    )

add_executable( mastermind ${MMIND_SRCS} )
