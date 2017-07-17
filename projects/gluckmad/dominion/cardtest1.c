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
    int i, treasureCount, deckSize;
    int passCount = 0;
    int failCount = 0;
    int seed = 1000;
    int numPlayer = 2;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;


    printf ("\n\nTESTING playAdventurer():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (deckSize = 0; deckSize <= MAX_DECK; deckSize++)
        {
            for (treasureCount = 0; treasureCount <= 3; treasureCount++)
            {
#if (NOISY_TEST == 1)
                printf("Test player %d with %d treasure card(s) and deck size %d.\n", p, treasureCount, deckSize);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.deckCount[p] = deckSize;                 // set the number of cards in the deck

                // Count available treasure before
                int treasureBefore = 0;
                
                for (i = 0; i < G.deckCount[p]; i++)
                {
                    if (G.deck[p][i] == copper || G.deck[p][i] == silver || G.deck[p][i] == gold) treasureBefore++;
                }
                playAdventurer(&G);
                
                // Count available treasure before
                int treasureAfter = 0;
                
                for (i = 0; i < G.deckCount[p]; i++)
                {
                    if (G.deck[p][i] == copper || G.deck[p][i] == silver || G.deck[p][i] == gold) treasureAfter++;
                }
                
#if (NOISY_TEST == 1)
                printf("Treasure before = %d, after = %d\n", treasureBefore, treasureAfter);
                if (treasureAfter >= treasureBefore - 2 && treasureAfter <= treasureBefore) // check that correct cost returned
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
