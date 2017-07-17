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
    int handBefore, handAfter, actionsBefore, actionsAfter;
    int failCount = 0;
    int passCount = 0;
    int seed = 1000;
    int numPlayer = 2;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("\n\nTESTING playGreat_Hall():\n");
    for (numPlayer = 2; numPlayer <= MAX_PLAYERS; numPlayer++)
    {
        for (p = 0; p < numPlayer; p++)
        {
#if (NOISY_TEST == 1)
            printf("Test player %d with %d-player game.\n", p, numPlayer);
#endif
            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
            
            // Count cards in hand and deck before
            handBefore = G.handCount[p];
            actionsBefore = G.numActions;
            
            playGreat_Hall(&G);
            
            // Count cards in hand and deck before
            handAfter = G.handCount[p];
            actionsAfter = G.numActions;
            

            
#if (NOISY_TEST == 1)
            printf("Hand before = %d, after = %d\n", handBefore, handAfter);
            printf("Actions before = %d, after = %d\n", actionsBefore, actionsAfter);
            if (handBefore == handAfter - 1 && actionsBefore == actionsAfter - 1) // check that hand and actions change correctly
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
