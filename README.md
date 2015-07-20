# Devlog

20150720
* Updated this README

20150714
* More unit tests (should cover all classes)
* More refactoring

20150713
* Unit tests added (for most classes)
* Added factory for Breaker

20150710
* Ready for running.  Not the neatest, but should do for now.
* Tidied up yesterdays tidy ups.
* Implemented Knuth
* Tested manually a bit
* Modified the result and guess classes.

20150709
* No compiler access today.  Some minor cleanups.

20150708

* sketched out thoughts, initial constraints, UI, rough design.
* implemented first pass prototype

# Thoughts

* This game has many variants (number of spaces on the board, number of colors, letters instead of colors).
* This guessing game involves a Master and a guesser.
* The game involves up to n rounds (12 for vanilla).
* The game starts by the Master choosing 4 pegs.  Pegs are not unique; multiple pegs of the same value (color/number) may be chosen.
* The guesser then makes a guess, by populating the next free row of pegs with pegs indicating their guess.
* The master evaluates the guess, and places up to 4 key pegs next to the guess.  A black key peg for each correct value in the correct position and a white key peg for each correct value in the wrong position.

# Initial constraints

* For a first iteration, the human will be the guesser, and the computer will be the Master.
* No configuration.
* Values will be chosen from 1 through 6, inclusive.
* 12 rounds comprise a game.
* W and B will be used for the key pegs.

# UI Design

```
Codemaster score: 4
+---------+---------+
| 4 3 2 2 | B B B B |  <== You Win!
+---------+---------+
| 3 4 2 2 | B B W W |
+---------+---------+
| 1 1 1 1 |         |
+---------+---------+
| 1 1 2 2 | B B     |
+---------+---------+

Next guess: 
```

# Rough Design

```
Round  comprises Guess and Result

Guess

Result

Codebreaker
    getNextGuess

Codemaster
    createCode
    evaluateCode

Board
    display
    addRound

Game
    Board
    Codebreaker
    Codemaster
    play
```

# Technical debt / backlog

* Out of source builds.
* Observer for CodeBreaker / board maybe
* Other algorithms as code breakers
* Template metaprogramming solver based on Knuth
* Command line invocation parameters: select algorithm
* Support variants
* Remove hardcoding / maybe wrap the common definitions in a class
* Tidy up comments
* More compile-time computation

