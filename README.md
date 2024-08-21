**Treasure Hunt Game**

**Overview**

The **Treasure Hunt** game is a simple command-line game developed in C. The objective of the game is to navigate a path in search of hidden treasures while avoiding bombs. The player has a limited number of lives and moves to find as many treasures as possible before the game ends.

**Features**

- **Player Configuration:**
  - Players can choose a symbol to represent themselves.
  - Players can set the number of lives (between 1 and 10).
- **Game Configuration:**
  - Players can set the path length, which must be a multiple of 5, and within a range of 10 to 70.
  - Players can also set the maximum number of moves allowed during the game.
- **Gameplay:**
  - The game board consists of bombs and treasures randomly placed along a path.
  - Players take turns selecting positions along the path to reveal either a bomb, treasure, or nothing.
  - The game ends when the player runs out of lives or moves.

**How to Play**

1. **Setup Player:**
    - Enter a single character to represent the player.
    - Set the number of lives the player will have (must be between 1 and 10).
2. **Configure Game:**
    - Set the length of the path (must be a multiple of 5 and between 10 and 70).
    - Set the maximum number of moves allowed (between 3 and 75% of the path length).
3. **Place Bombs and Treasures:**
    - Enter bomb placements in sets of 5 (1 for a bomb, 0 for no bomb).
    - Enter treasure placements in sets of 5 (1 for a treasure, 0 for no treasure).
4. **Start the Game:**
    - The player will be prompted to enter a position to reveal what is hidden there (bomb, treasure, or nothing).
    - The game continues until the player runs out of lives or moves.
5. **Game Over:**
    - If the player runs out of lives or moves, the game ends, and the final score is displayed.
    - Players are encouraged to play again to beat their previous score.

**Code Structure**

- **PlayerInfo Structure:** Contains player-related information, such as the player's symbol, number of lives, number of treasures found, and game history.
- **GameInfo Structure:** Contains game-related information, such as the path length, bomb locations, and treasure locations.
- **Main Function:**
  - Handles player and game configuration.
  - Manages the game loop where the player makes moves.
  - Displays the game board and updates player stats after each move.

**Compilation and Execution**

To compile and run the game, use the following commands in a terminal:

````

gcc -o treasure_hunt treasure_hunt.c

./treasure_hunt

````

**Example Output**

````

\================================

Treasure Hunt!

\================================

PLAYER Configuration

\--------------------

Enter a single character to represent the player: @

Set the number of lives: 5

Player configuration set-up is complete

GAME Configuration

\------------------

Set the path length (a multiple of 5 between 10-70): 20

Set the limit for number of moves allowed: 15

BOMB Placement

\--------------

Enter the bomb positions in sets of 5 where a value

of 1=BOMB, and 0=NO BOMB. Space-delimit your input.

(Example: 1 0 0 1 1) NOTE: there are 20 to set!

Positions \[ 1- 5\]: 1 0 0 1 1

Positions \[ 6-10\]: 0 1 0 1 0

Positions \[11-15\]: 0 0 1 1 0

Positions \[16-20\]: 0 1 0 0 1

BOMB placement set

TREASURE Placement

\------------------

Enter the treasure placements in sets of 5 where a value

of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.

(Example: 1 0 0 1 1) NOTE: there are 20 to set!

Positions \[ 1- 5\]: 0 0 1 0 1

Positions \[ 6-10\]: 0 1 1 0 1

Positions \[11-15\]: 1 0 0 1 0

Positions \[16-20\]: 1 0 0 0 1

TREASURE placement set

GAME configuration set-up is complete...

\------------------------------------

TREASURE HUNT Configuration Settings

\------------------------------------

Player:

Symbol : @

Lives : 5

Treasure : \[ready for gameplay\]

History : \[ready for gameplay\]

Game:

Path Length: 20

Bombs : 10011010100110010100

Treasure : 00101001101010010001

\====================================

~ Get ready to play TREASURE HUNT! ~

\====================================

...

+---------------------------------------------------+

Lives: 4 | Treasures: 2 | Moves Remaining: 12

+---------------------------------------------------+

...

##################

\# Game over! #

##################

You should play again and try to beat your score!

````

**Authorship and Licensing**

**Author:** Navnoor Singh

**Email:** contactnavnoorsingh@gmail.com
