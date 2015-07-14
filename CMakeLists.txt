cmake_minimum_required( VERSION 2.8.3 )

project( mastermind )

set ( MMIND_SRCS
      ${CMAKE_CURRENT_LIST_DIR}/CGame.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CBoard.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CCodeMaster.cpp
      ${CMAKE_CURRENT_LIST_DIR}/mastermind.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CHumanCodeBreaker.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CKnuthCodeBreaker.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CResult.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CGuess.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CmdLineParsing.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CBreakerFactory.cpp
    )

add_executable( mastermind ${MMIND_SRCS} )

enable_testing()

include( ${CMAKE_CURRENT_LIST_DIR}/test/CMakeLists.txt )

