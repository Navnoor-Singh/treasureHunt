/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : Navnoor Singh
Student ID#: 160821211
Email      : nsingh391@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LIVES 10
#define MIN_LIVES 1
#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70
#define MIN_MOVES 3
#define MULTIPLE_OF 5
#define MOVES_LIMITER 0.75

//structures...

struct PlayerInfo
{
    char playerSymbol;
    int numberofLives;
    int numberofTreasures;
    int history[MAX_PATH_LENGTH];
    
};

struct GameInfo
{
    int maxMoves;
    int pathLength;
    int bombLocations[MAX_PATH_LENGTH];
    int treasureLocations[MAX_PATH_LENGTH];
    
};

int main(void)
{
    
    struct PlayerInfo player = { 0 };
    struct GameInfo game = { 0 };
    int valid, i, j;
    
    
    printf("================================\n"
           "         Treasure Hunt!\n"
           "================================\n\n");
    
    printf("PLAYER Configuration\n"
           "--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playerSymbol);

    //player info validation
    do{
        valid = 1;
        printf("Set the number of lives: ");
        scanf("%d", &player.numberofLives);
        if(player.numberofLives < MIN_LIVES || player.numberofLives > MAX_LIVES)
        {
            printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
            valid = 0;
        }
        
    }while(!valid);
    printf("Player configuration set-up is complete\n");
    
    putchar('\n');
    
    printf("GAME Configuration\n"
           "------------------\n");
    
    do{
        valid = 1;
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE_OF, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        scanf("%d", &game.pathLength);
        
        if(((game.pathLength % MULTIPLE_OF)) || game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH)
        {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE_OF, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
            valid = 0;
        }
        
    }while(!valid);
    
    do{
        valid = 1;
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.maxMoves);
        
        if(game.maxMoves < MIN_MOVES || game.maxMoves >( game.pathLength * MOVES_LIMITER))
        {
            printf("    Value must be between %d and %d\n", MIN_MOVES, (int)(game.pathLength * MOVES_LIMITER));
            valid = 0;
        }
        
    }while(!valid);
    
    putchar('\n');
    
    
    //game info validation
    printf("BOMB Placement\n"
           "--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n"
           "of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", MULTIPLE_OF, game.pathLength);
    for (i = 0; i < (game.pathLength / MULTIPLE_OF); i++)
    {
        printf("   Positions [%2d-%2d]: ", (MULTIPLE_OF * i) + 1,
                                           (MULTIPLE_OF * i) + MULTIPLE_OF);
        for (j = (MULTIPLE_OF * i); j < ((MULTIPLE_OF * i) + MULTIPLE_OF); j++)
        {
            scanf("%d", &game.bombLocations[j]);
        }
    }
    printf("BOMB placement set\n\n");
    
    
    printf("TREASURE Placement\n"
           "------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n"
           "of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", MULTIPLE_OF, game.pathLength);
    for (i = 0; i < (game.pathLength / MULTIPLE_OF); i++)
    {
        printf("   Positions [%2d-%2d]: ", (MULTIPLE_OF * i) + 1,
                                           (MULTIPLE_OF * i) + MULTIPLE_OF);
        
        for (j = (MULTIPLE_OF * i); j < ((MULTIPLE_OF * i) + MULTIPLE_OF); j++)
        {
            scanf("%d", &game.treasureLocations[j]);
        }
    }
    
    
    //printing selected information
    
    printf("TREASURE placement set\n\n");
    
    printf("GAME configuration set-up is complete...\n\n"
           "------------------------------------\n"
           "TREASURE HUNT Configuration Settings\n"
           "------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.playerSymbol);
    printf("   Lives      : %d\n", player.numberofLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");\
    
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");

    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombLocations[i]);
    }
    
    putchar('\n');
    
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasureLocations[i]);
    }
    putchar('\n');
    putchar('\n');
    
    printf("====================================\n"
           "~ Get ready to play TREASURE HUNT! ~\n"
           "====================================\n");

    return 0;
}
