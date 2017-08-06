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
    int i, j, m;
    int passCount = 0;
    int failCount = 0;
    int seed = 1000;
    int numPlayer = 2;
    int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    // array of all supply piles set to 1
    int piles[27];

    for (i = 0; i < 27; i++)
    {
        piles[i] = 1;
    }

    printf ("\n\nTESTING isGameOver():\n");
    for (numPlayer = 2; numPlayer <= MAX_PLAYERS; numPlayer++)
    {
        for (i = 0; i < sizeof(G.supplyCount)/sizeof(G.supplyCount[0]); i++)
        {
            for (j = 1; j < sizeof(G.supplyCount)/sizeof(G.supplyCount[0]); j++)
            {
                for (m = 25; m < sizeof(G.supplyCount)/sizeof(G.supplyCount[0]); m++)
                {
                    if (i != j && j != m && m != i)
                    {
#if (NOISY_TEST == 1)
                        printf("Test %d-player game with %d, %d, and %d piles depleted.\n", numPlayer, i, j, m);
#endif
                        memset(&G, 23, sizeof(struct gameState));   // clear the game state
                        initializeGame(numPlayer, k, seed, &G); // initialize a new game
                        memcpy(G.supplyCount, piles, sizeof(piles)); // set all the piles to 1
                        // Set three piles to depleted
                        G.supplyCount[i] = 0;
                        G.supplyCount[j] = 0;
                        G.supplyCount[m] = 0;
                        r = isGameOver(&G);
#if (NOISY_TEST == 1)
                        printf("r = %d, expected = %d\n", r, 1);
#endif
                        assert(r == 1);
                        if (r == 1) // check that game over identified
                        {
                            printf("PASS\n");
                            passCount++;
                        }
                        else
                        {
                            printf("FAIL\n");
                            failCount++;
                        }
                    }
                }
            }
        }
    }

    if (failCount == 0)
    {
        printf("All tests passed!\n");
    }
    else{
        printf("PASSED: %d \t FAILED: %d\n", passCount, failCount);
    }
    return 0;
}
