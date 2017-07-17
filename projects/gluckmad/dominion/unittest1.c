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

int main()
{
    int seed = 1000;
    int numPlayer = 2;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("\nTESTING whoseTurn():\n");
    for (numPlayer = 2; numPlayer <= MAX_PLAYERS; numPlayer++)
    {
        for (p = 0; p < numPlayer; p++)
        {
#if (NOISY_TEST == 1)
            printf("Test player %d with %d players total.\n", p + 1, numPlayer);
#endif
            memset(&G, 23, sizeof(struct gameState));   // clear the game state
            r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
            G.whoseTurn = p;
            whoseTurn(&G);
#if (NOISY_TEST == 1)
            printf("G.whoseTurn = %d, expected = %d\n", G.whoseTurn, p);
#endif
            assert(G.whoseTurn == p); // check that the turn is correct
        }
    }

    printf("All tests passed!\n");

    return 0;
}
