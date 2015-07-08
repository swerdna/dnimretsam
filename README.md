# Devlog

20150708 - sketched out thoughts, initial constraints, UI, rough design.

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

# Design

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
```

# Technical debt / backlog

* Out of source builds.
