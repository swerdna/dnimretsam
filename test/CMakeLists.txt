cmake_minimum_required( VERSION 2.8.3 )

project( testMastermind )

set ( MMIND_TEST_SRCS
      ${CMAKE_CURRENT_LIST_DIR}/CGameTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CBoardTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CCodeMasterTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CHumanCodeBreakerTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CKnuthCodeBreakerTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CResultTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CGuessTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CmdLineParsingTest.cpp
# Including the sources from parent here.
# We could build these as a library
      ${CMAKE_CURRENT_LIST_DIR}/../CGame.cpp
      ${CMAKE_CURRENT_LIST_DIR}/../CBoard.cpp
      ${CMAKE_CURRENT_LIST_DIR}/../CmdLineParsing.cpp
      ${CMAKE_CURRENT_LIST_DIR}/../CCodeMaster.cpp
      ${CMAKE_CURRENT_LIST_DIR}/../CHumanCodeBreaker.cpp
      ${CMAKE_CURRENT_LIST_DIR}/../CKnuthCodeBreaker.cpp
      ${CMAKE_CURRENT_LIST_DIR}/../CResult.cpp
      ${CMAKE_CURRENT_LIST_DIR}/../CGuess.cpp
    )

include_directories( ${CMAKE_CURRENT_LIST_DIR}/../3rdparty/gtest/include
                     ${CMAKE_CURRENT_LIST_DIR}/..
                   )
link_directories( ${CMAKE_CURRENT_LIST_DIR}/../3rdparty/gtest/lib )

add_executable( testMastermind ${MMIND_TEST_SRCS} )

target_link_libraries( testMastermind gtest gtest_main pthread )

add_test( testsuite testMastermind )
