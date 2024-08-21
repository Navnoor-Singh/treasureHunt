// Disable secure warnings for C runtime functions
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Constants for game configuration
#define MAX_LIVES 10            // Maximum number of lives a player can have
#define MIN_LIVES 1             // Minimum number of lives a player must have
#define MIN_PATH_LENGTH 10      // Minimum length of the game path
#define MAX_PATH_LENGTH 70      // Maximum length of the game path
#define MIN_MOVES 3             // Minimum number of moves allowed
#define MULTIPLE_OF 5           // Path length must be a multiple of this value
#define MOVES_LIMITER 0.75      // Max moves allowed is 75% of the path length

// Structure to store player information
struct PlayerInfo {
    char playerSymbol;                         // Symbol representing the player
    int numberofLives;                         // Number of lives the player has
    int numberofTreasures;                     // Number of treasures the player has found
    int history[MAX_PATH_LENGTH];              // Array to store the history of player moves
    int treasureFound;                         // Counter for the number of treasures found
    int position;                              // Current position of the player on the path
};

// Structure to store game information
struct GameInfo {
    int maxMoves;                              // Maximum number of moves allowed
    int pathLength;                            // Length of the game path
    int bombLocations[MAX_PATH_LENGTH];        // Array storing bomb locations on the path
    int treasureLocations[MAX_PATH_LENGTH];    // Array storing treasure locations on the path
};

int main(void) {
    
    struct PlayerInfo player = { 0 };          // Initialize player information structure
    struct GameInfo game = { 0 };              // Initialize game information structure
    int valid, validation, i, j;               // Variables for validation and loop control
    char playerPosition[MAX_PATH_LENGTH] = { 0 }; // Array to store player positions on the path
    const char vacant = '-';                   // Character representing a vacant spot
    const char bomb = '!';                     // Character representing a bomb
    const char treasure = '$';                 // Character representing a treasure
    const char both = '&';                     // Character representing both bomb and treasure
    const char none = '.';                     // Character representing an empty spot
    
    // START
    printf("================================\n"
           "         Treasure Hunt!\n"
           "================================\n\n");
    
    // PLAYER Configuration
    printf("PLAYER Configuration\n"
           "--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playerSymbol);

    // Player info validation
    do {
        valid = 1;
        printf("Set the number of lives: ");
        scanf("%d", &player.numberofLives);
        if (player.numberofLives < MIN_LIVES || player.numberofLives > MAX_LIVES) {
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
            valid = 0;
        }
    } while (!valid);
    printf("Player configuration set-up is complete\n");
    
    putchar('\n');
    
    // GAME Configuration
    printf("GAME Configuration\n"
           "------------------\n");
    
    // Path length validation
    do {
        valid = 1;
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE_OF, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.pathLength);
        
        if (((game.pathLength % MULTIPLE_OF)) || game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH) {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE_OF, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
            valid = 0;
        }
    } while (!valid);
    
    // Maximum moves validation
    do {
        valid = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxMoves);
        
        if (game.maxMoves < MIN_MOVES || game.maxMoves > (game.pathLength * MOVES_LIMITER)) {
            printf("    Value must be between %d and %d\n", MIN_MOVES, (int)(game.pathLength * MOVES_LIMITER));
            valid = 0;
        }
    } while (!valid);
    
    putchar('\n');
    
    // BOMB Placement
    printf("BOMB Placement\n"
           "--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n"
           "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
           MULTIPLE_OF, game.pathLength);
    for (i = 0; i < (game.pathLength / MULTIPLE_OF); i++) {
        printf("   Positions [%2d-%2d]: ", (MULTIPLE_OF * i) + 1,
                                           (MULTIPLE_OF * i) + MULTIPLE_OF);
        for (j = (MULTIPLE_OF * i); j < ((MULTIPLE_OF * i) + MULTIPLE_OF); j++) {
            scanf("%d", &game.bombLocations[j]);
        }
    }
    printf("BOMB placement set\n\n");
    
    // TREASURE Placement
    printf("TREASURE Placement\n"
           "------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n"
           "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
           MULTIPLE_OF, game.pathLength);
    for (i = 0; i < (game.pathLength / MULTIPLE_OF); i++) {
        printf("   Positions [%2d-%2d]: ", (MULTIPLE_OF * i) + 1,
                                           (MULTIPLE_OF * i) + MULTIPLE_OF);
        
        for (j = (MULTIPLE_OF * i); j < ((MULTIPLE_OF * i) + MULTIPLE_OF); j++) {
            scanf("%d", &game.treasureLocations[j]);
        }
    }
    
    // Printing selected information
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n"
           "------------------------------------\n"
           "TREASURE HUNT Configuration Settings\n"
           "------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.playerSymbol);
    printf("   Lives      : %d\n", player.numberofLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");
    
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.bombLocations[i]);
    }
    putchar('\n');
    
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++) {
        printf("%d", game.treasureLocations[i]);
    }
    
    putchar('\n');
    putchar('\n');
    
    // Starting the game
    printf("====================================\n"
           "~ Get ready to play TREASURE HUNT! ~\n"
           "====================================\n\n");

    // Printing the game path
    printf("  ");
    for (i = 0; i < game.pathLength; i++) {
        if (playerPosition[i] == both) {
            printf("%c", both);
        } else if (playerPosition[i] == treasure) {
            printf("%c", treasure);
        } else if (playerPosition[i] == none) {
            printf("%c", none);
        } else if (playerPosition[i] == bomb) {
            printf("%c", bomb);
        } else {
            printf("%c", vacant);
        }
    }
    putchar('\n');

    printf("  ");

    // Printing the ruler (to show positions)
    for (i = 1, j = 1; i <= game.pathLength; i++) {
        if (i % 10 == 0) {
            printf("%d", j);
            j++;
        } else {
            printf("|");
        }
    }
    putchar('\n');
    
    // Printing the position numbers
    printf("  ");
    for (i = 1, j = 1; i <= game.pathLength; i++) {
        if (i % 10 == 0) {
            printf("0");
            j = 1;
        } else {
            printf("%d", j);
            j++;
        }
    }

    // Displaying the initial game board
    putchar('\n');
    printf("+---------------------------------------------------+\n"
           "  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d\n"
           "+---------------------------------------------------+\n",
           player.numberofLives, player.treasureFound, game.maxMoves);
    
    // Main game loop
    do {
        do {
            valid = 1;
            validation = 1;

            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &player.position);
            
            // Validate the player position input
            if (player.position <= 0 || player.position > game.pathLength) {
                printf("  Out of Range!!!\n");
                validation = 0;
            }
        } while (!validation);
        
        // Check for bomb and treasure at the current position
        if (game.treasureLocations[player.position - 1] == 1 &&
            game.bombLocations[player.position - 1] == 1) {
            putchar('\n');
            printf("===============> [&] !!! BOOOOOM !!! [&]\n"
                   "===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            player.history[player.position - 1] = 1;
            player.numberofLives--;
            player.treasureFound++;
            game.maxMoves--;
            playerPosition[player.position - 1] = both;
            valid = 0;
        } else if (game.treasureLocations[player.position - 1] == 1 &&
                   game.bombLocations[player.position - 1] == 0) {
            // Treasure found
            putchar('\n');
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            player.history[player.position - 1] = 1;
            player.treasureFound++;
            game.maxMoves--;
            playerPosition[player.position - 1] = treasure;
            valid = 0;
        } else if (game.treasureLocations[player.position - 1] == 0 &&
                   game.bombLocations[player.position - 1] == 0 &&
                   player.history[player.position - 1] == 0) {
            // Nothing found
            putchar('\n');
            printf("===============> [.] ...Nothing found here... [.]\n");
            player.history[player.position - 1] = 1;
            game.maxMoves--;
            playerPosition[player.position - 1] = none;
            valid = 0;
        } else if (game.treasureLocations[player.position - 1] == 0 &&
                   game.bombLocations[player.position - 1] == 1) {
            // Bomb found
            putchar('\n');
            printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            player.history[player.position-1] = 1;
            player.numberofLives--;
            game.maxMoves--;
            playerPosition[player.position - 1] = bomb;
            valid = 0;
        } else {
            // Revisiting a position
            putchar('\n');
            printf("===============> Dope! You've been here before!\n");
            player.history[player.position-1] = 0;
            valid = 0;
        }
        
        // Check if the game should end (either lives or moves are exhausted)
        if (player.numberofLives == 0) {
            printf("\nNo more LIVES remaining!\n");
            valid = 1;
        } else if (game.maxMoves == 0) {
            printf("\nNo more MOVES remaining!\n");
            valid = 1;
        }
        
        // Display the current player position
        putchar('\n');
        printf("  ");
        for (i = 1; i < (player.position + 1); i++) {
            if (i != player.position) {
                printf(" ");
            } else if (player.position == 0) {
                printf(" ");
            } else {
                printf("%c\n", player.playerSymbol);
            }
        }
        
        // Reprint the game path with updates
        printf("  ");
        for (i = 0; i < game.pathLength; i++) {
            if (playerPosition[i] == both) {
                printf("%c", both);
            } else if (playerPosition[i] == treasure) {
                printf("%c", treasure);
            } else if (playerPosition[i] == none) {
                printf("%c", none);
            } else if (playerPosition[i] == bomb) {
                printf("%c", bomb);
            } else {
                printf("%c", vacant);
            }
        }
        
        // Reprint the ruler
        putchar('\n');
        printf("  ");
        for (i = 1, j = 1; i <= game.pathLength; i++) {
            if (i % 10 == 0) {
                printf("%d", j);
                j++;
            } else {
                printf("|");
            }
        }
        
        // Reprint the position numbers
        putchar('\n');
        printf("  ");
        for (i = 1, j = 1; i <= game.pathLength; i++) {
            if (i % 10 == 0) {
                printf("0");
                j = 1;
            } else {
                printf("%d", j);
                j++;
            }
        }
        
        // Display the updated scoreboard
        putchar('\n');
        printf("+---------------------------------------------------+\n"
               "  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d\n"
               "+---------------------------------------------------+\n",
               player.numberofLives, player.treasureFound, game.maxMoves);

    } while (!valid);
    
    // Reset the player's history for a new game
    for (i = 0; i < game.pathLength; i++) {
        player.history[i] = 0;
    }

    // END
    putchar('\n');
    printf("##################\n"
           "#   Game over!   #\n"
           "##################\n\n");
    
    printf("You should play again and try to beat your score!\n");
    
    return 0;
}
