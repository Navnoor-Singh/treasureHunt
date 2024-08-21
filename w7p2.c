/*
*****************************************************************************
                          Workshop - #7 (P2)
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
    int treasureFound;
    int position;
    
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
    int valid, validation, i, j;
    char playerPosition[MAX_PATH_LENGTH] = { 0 };
    const char vacant = '-';
    const char bomb = '!';
    const char treasure = '$';
    const char both = '&';
    const char none = '.';
    
    
    // START
    
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
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
           MULTIPLE_OF, game.pathLength);
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
           "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",
           MULTIPLE_OF, game.pathLength);
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
           "====================================\n\n");

    // Printing game path once...
    
    printf("  ");
    for (i = 0; i < game.pathLength; i++)
    {
    
        if(playerPosition[i] == both)
        {
            printf("%c", both);
        }

        else if(playerPosition[i] == treasure)
        {
            printf("%c", treasure);
        }

        else if(playerPosition[i] == none)
        {
            printf("%c", none);
        }

        else if(playerPosition[i] == bomb)
        {
            printf("%c", bomb);
        }
    
        else
        {
            printf("%c", vacant);
        }
    }

    putchar('\n');

    printf("  ");

    //ruler...
    
    for (i = 1, j = 1; i <= game.pathLength; i++)
    {
        if (i % 10 == 0)
        {
            printf("%d", j);
            j++;
        }
        else
        {
            printf("|");
        }
    }
    
    putchar('\n');
    printf("  ");
    for (i = 1, j = 1; i <= game.pathLength; i++)
    {
        if (i % 10 == 0)
        {
            printf("0");
            j = 1;
        }
        else
        {
            printf("%d", j);
            j++;
        }
    }

    //display board
    putchar('\n');
    printf("+---------------------------------------------------+\n"
           "  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d\n"
           "+---------------------------------------------------+\n",
           player.numberofLives, player.treasureFound, game.maxMoves);
    
    //main game logic...
    
    do{
        do{
        valid = 1;
        validation = 1;
            
            
            
        printf("Next Move [1-%d]: ", game.pathLength);
        scanf("%d", &player.position);
        
        
            if(player.position <= 0 || player.position > game.pathLength)
                
                {
                    printf("  Out of Range!!!\n");
                    validation = 0;
                }
                
            }while(!validation);
        
        
        // bomb and treasure...!!$$
        
        if(game.treasureLocations[player.position - 1] == 1 &&
           game.bombLocations[player.position - 1] == 1)
        {
            putchar('\n');
            printf("===============> [&] !!! BOOOOOM !!! [&]\n"
                   "===============> [&] $$$ Life Insurance Payout!!! [&]\n");
            player.history[player.position - 1] = 1;
            player.numberofLives--;
            player.treasureFound++;
            game.maxMoves--;
            playerPosition[player.position - 1] = both;
            valid = 0;
        }
        
        
        // treasure found..$$
        
        else if(game.treasureLocations[player.position - 1] == 1 &&
                game.bombLocations[player.position - 1] == 0)
        {
            putchar('\n');
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            player.history[player.position - 1] = 1;
            player.treasureFound++;
            game.maxMoves--;
            playerPosition[player.position - 1] = treasure;
            valid = 0;
        }
        
        
        // nothing found....
        
        else if(game.treasureLocations[player.position - 1] == 0 &&
                game.bombLocations[player.position - 1] == 0 &&
                player.history[player.position - 1] == 0)
        {
            putchar('\n');
            printf("===============> [.] ...Nothing found here... [.]\n");
            player.history[player.position - 1] = 1;
            game.maxMoves--;
            playerPosition[player.position - 1] = none;
            valid = 0;
        }
        
        
        // bomb found ..!!
        
        else if(game.treasureLocations[player.position - 1] == 0 &&
                game.bombLocations[player.position - 1] == 1)
        {
            putchar('\n');
            printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            player.history[player.position-1] = 1;
            player.numberofLives--;
            game.maxMoves--;
            playerPosition[player.position - 1] = bomb;
            valid = 0;
        }
        
        
        //visited again..??
        
        else
        {
            putchar('\n');
            printf("===============> Dope! You've been here before!\n");
            player.history[player.position-1] = 0;
            valid = 0;
        }
        
        
        //game killer, if lives run out
        
        if(player.numberofLives == 0)
        {
            printf("\nNo more LIVES remaining!\n");
            valid = 1;
        }
        
        //game killer, if moves run out
        
       else if(game.maxMoves == 0)
       {
           printf("\nNo more MOVES remaining!\n");
           valid = 1;
       }
        
    
        //player position revealer...
        
        putchar('\n');
        printf("  ");
        for (i = 1; i < (player.position + 1); i++)
        {
            if (i != player.position)
            {
                printf(" ");
            }
            else if (player.position == 0)
            {
                printf(" ");
            }
            else
            {
                printf("%c\n", player.playerSymbol);
            }
        }
        
        
        // gamepath logic...
        
            printf("  ");
            for (i = 0; i < game.pathLength; i++)
            {
            
                if(playerPosition[i] == both)
                {
                    printf("%c", both);
                }
        
                else if(playerPosition[i] == treasure)
                {
                    printf("%c", treasure);
                }
        
                else if(playerPosition[i] == none)
                {
                    printf("%c", none);
                }
        
                else if(playerPosition[i] == bomb)
                {
                    printf("%c", bomb);
                }
            
//                else if(player.history[i] == 1 && playerPosition[i] == none)
//                {
//                    printf("%c", none);
//                }
                
                else
                {
                    printf("%c", vacant);
                }
            }

        
    putchar('\n');
        
    printf("  ");
        
        
        // ruler logic...
        
        
        for (i = 1, j = 1; i <= game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", j);
                j++;
            }
            else
            {
                printf("|");
            }
        }
        
        putchar('\n');
        printf("  ");
        for (i = 1, j = 1; i <= game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("0");
                j = 1;
            }
            else
            {
                printf("%d", j);
                j++;
            }
        }
        
        // score board logic...
        putchar('\n');
        printf("+---------------------------------------------------+\n"
               "  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d\n"
               "+---------------------------------------------------+\n",
               player.numberofLives, player.treasureFound, game.maxMoves);
    

    }while(!valid);
    
    // manual resetting history...
    
    for (i = 0; i < game.pathLength; i++)
    {
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
