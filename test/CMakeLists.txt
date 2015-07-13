cmake_minimum_required( VERSION 2.8.3 )

project( testMastermind )

set ( MMIND_TEST_SRCS
      ${CMAKE_CURRENT_LIST_DIR}/CGameTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CBoardTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CCodeMasterTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CCodeBreakerTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/mastermindTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CHumanCodeBreakerTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CKnuthCodeBreakerTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CResultTest.cpp
      ${CMAKE_CURRENT_LIST_DIR}/CGuessTest.cpp
    )

include_directories( ${CMAKE_CURRENT_LIST_DIR}/../3rdparty/gtest/include )
link_directories( ${CMAKE_CURRENT_LIST_DIR}/../3rdparty/gtest/lib )

add_executable( testMastermind ${MMIND_TEST_SRCS} )

target_link_libraries( testMastermind gtest gtest_main pthread )

add_test( testsuite testMastermind )
