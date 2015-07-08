cmake_minimum_required( VERSION 2.8.3 )

project( mastermind )
set ( MMIND_SRCS
      CGame.cpp
      mastermind.cpp
    )

add_executable( mastermind ${MMIND_SRCS} )
