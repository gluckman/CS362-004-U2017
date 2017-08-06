// David Gluckman
// CS 362 Section 400 Summer 2017
// Assignment 3 - unit testing
// unittest.c

// Template from testUpdateCoins.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int handBefore, handAfter, coinsBefore, coinsAfter;
    int choice1, choice2, choice3;
    int c2Before, c2After, c3Before, c3After;
    int failCount = 0;
    int passCount = 0;
    int seed = 1000;
    int numPlayer = 2;
    int p, r;
    int handPos = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("\n\nTESTING cardEffect() with Steward:\n");
    for (numPlayer = 2; numPlayer <= MAX_PLAYERS; numPlayer++)
    {
        for (p = 0; p < numPlayer; p++)
        {
            for (choice1 = 0; choice1 < 3; choice1++)
            {
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                
                for (choice2 = 0; choice2 < numHandCards(&G); choice2++)
                {
                    for (choice3 = 0; choice3 < numHandCards(&G); choice3++)
                    {
                        if (choice2 != choice3)
                        {
#if (NOISY_TEST == 1)
                            printf("Test player %d with %d-player game, choice 1 = %d, choice2 = %d, choice3 = %d.\n", p, numPlayer, choice1, choice2, choice3);
#endif
                            // Count cards in hand, coins, choice2 in hand, choice3 in hand
                            handBefore = G.handCount[p];
                            coinsBefore = G.coins;
                            c2Before = 0;
                            c3Before = 0;
                            for (i = 0; i < G.handCount[p]; i++)
                            {
                                if (G.hand[p][i] == choice2)
                                {
                                    c2Before++;
                                }
                                else if (G.hand[p][i] == choice3)
                                {
                                    c3Before++;
                                }
                            }
                            
                            cardEffect(steward, choice1, choice2, choice3, &G, handPos, NULL);
                            
                            // Count cards in hand and deck before
                            handAfter = G.handCount[p];
                            coinsAfter = G.coins;
                            c2After = 0;
                            c3After = 0;
                            for (i = 0; i < G.handCount[p]; i++)
                            {
                                if (G.hand[p][i] == choice2)
                                {
                                    c2After++;
                                }
                                else if (G.hand[p][i] == choice3)
                                {
                                    c3After++;
                                }
                            }

            
#if (NOISY_TEST == 1)
                            printf("Hand before = %d, after = %d\n", handBefore, handAfter);
                            printf("Coins before = %d, after = %d\n", coinsBefore, coinsAfter);
                            printf("Card choice 2 before = %d, after = %d\n", c2Before, c2After);
                            printf("Card choice 3 before = %d, after = %d\n", c3Before, c3After);
                            // check that hand and actions change correctly
                            if (choice1 == 1 && handBefore == handAfter - 2 && coinsBefore == coinsAfter && c2Before == c2After && c3Before == c3After)
                            {
                                printf("\tPASS\n");
                                passCount++;
                            }
                            else if (choice1 == 2 && handBefore == handAfter && coinsBefore == coinsAfter - 2 && c2Before == c2After && c3Before == c3After) // check that hand and actions change correctly
                            {
                                printf("\tPASS\n");
                                passCount++;
                            }
                            else if (choice1 == 3 && handBefore == handAfter + 2 && coinsBefore == coinsAfter && c2Before == c2After + 1 && c3Before == c3After + 1) // check that hand and actions change correctly
                            {
                                printf("\tPASS\n");
                                passCount++;
                            }
                            else if (choice1 == 3 && handBefore == handAfter + 1 && coinsBefore == coinsAfter && c2Before == c2After + 1 && c3Before == c3After) // check that hand and actions change correctly
                            {
                                printf("\tPASS\n");
                                passCount++;
                            }
                            else if (choice1 == 3 && handBefore == handAfter + 1 && coinsBefore == coinsAfter && c2Before == c2After && c3Before == c3After + 1) // check that hand and actions change correctly
                            {
                                printf("\tPASS\n");
                                passCount++;
                            }
                            else
                            {
                                printf("\tFAIL\n");
                                failCount++;
                            }
#endif
                        }
                    }
                }
            }
        }
    }
    
    // Print results
    if (failCount == 0)
    {
        printf("All tests passed!\n");
    }
    else{
        printf("PASSED: %d \t FAILED: %d\n", passCount, failCount);
    }
    return 0;
}
