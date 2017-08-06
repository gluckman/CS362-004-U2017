// David Gluckman
// CS 362 Section 400 Summer 2017
// Assignment 3 - unit testing
// unittest3.c

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
    int passCount = 0;
    int failCount = 0;
    int seed = 1000;
    int numPlayer = 2;
    int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("\n\nTESTING getCost():\n");
    for (numPlayer = 2; numPlayer <= MAX_PLAYERS; numPlayer++)
    {
#if (NOISY_TEST == 1)
        printf("Test %d-player game.\n", numPlayer);
#endif
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, &G); // initialize a new game

        // Test curse
        r = getCost(curse);
#if (NOISY_TEST == 1)
        printf("Curse cost = %d, expected = %d\n", r, 0);
        if (r == 0) // check that correct cost returned
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

        // Test estate
        r = getCost(estate);
#if (NOISY_TEST == 1)
        printf("estate cost = %d, expected = %d\n", r, 2);
        if (r == 2) // check that correct cost returned
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
        
        // Test duchy
        r = getCost(duchy);
#if (NOISY_TEST == 1)
        printf("duchy cost = %d, expected = %d\n", r, 5);
        if (r == 5) // check that correct cost returned
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
        
        // Test province
        r = getCost(province);
#if (NOISY_TEST == 1)
        printf("province cost = %d, expected = %d\n", r, 8);
        if (r == 8) // check that correct cost returned
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
        
        // Test copper
        r = getCost(copper);
#if (NOISY_TEST == 1)
        printf("copper cost = %d, expected = %d\n", r, 0);
        if (r == 0) // check that correct cost returned
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
        
        // Test silver
        r = getCost(silver);
#if (NOISY_TEST == 1)
        printf("silver cost = %d, expected = %d\n", r, 3);
        if (r == 3) // check that correct cost returned
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
        
        // Test gold
        r = getCost(gold);
#if (NOISY_TEST == 1)
        printf("gold cost = %d, expected = %d\n", r, 6);
        if (r == 6) // check that correct cost returned
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
        
        // Test adventurer
        r = getCost(adventurer);
#if (NOISY_TEST == 1)
        printf("adventurer cost = %d, expected = %d\n", r, 6);
        if (r == 6) // check that correct cost returned
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
        
        // Test council_room
        r = getCost(council_room);
#if (NOISY_TEST == 1)
        printf("council_room cost = %d, expected = %d\n", r, 5);
        if (r == 5) // check that correct cost returned
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
        
        // Test feast
        r = getCost(feast);
#if (NOISY_TEST == 1)
        printf("feast cost = %d, expected = %d\n", r, 4);
        if (r == 4) // check that correct cost returned
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
        
        // Test gardens
        r = getCost(gardens);
#if (NOISY_TEST == 1)
        printf("gardens cost = %d, expected = %d\n", r, 4);
        if (r == 4) // check that correct cost returned
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
        
        // Test mine
        r = getCost(mine);
#if (NOISY_TEST == 1)
        printf("mine cost = %d, expected = %d\n", r, 5);
        if (r == 5) // check that correct cost returned
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
        
        // Test remodel
        r = getCost(remodel);
#if (NOISY_TEST == 1)
        printf("remodel cost = %d, expected = %d\n", r, 4);
        if (r == 4) // check that correct cost returned
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
        
        // Test smithy
        r = getCost(smithy);
#if (NOISY_TEST == 1)
        printf("smithy cost = %d, expected = %d\n", r, 4);
        if (r == 4) // check that correct cost returned
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
        
        // Test village
        r = getCost(village);
#if (NOISY_TEST == 1)
        printf("village cost = %d, expected = %d\n", r, 3);
        if (r == 3) // check that correct cost returned
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
        
        // Test baron
        r = getCost(baron);
#if (NOISY_TEST == 1)
        printf("baron cost = %d, expected = %d\n", r, 4);
        if (r == 4) // check that correct cost returned
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
        
        // Test great_hall
        r = getCost(great_hall);
#if (NOISY_TEST == 1)
        printf("great_hall cost = %d, expected = %d\n", r, 3);
        if (r == 3) // check that correct cost returned
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
        
        // Test minion
        r = getCost(minion);
#if (NOISY_TEST == 1)
        printf("minion cost = %d, expected = %d\n", r, 5);
        if (r == 5) // check that correct cost returned
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
        
        // Test steward
        r = getCost(steward);
#if (NOISY_TEST == 1)
        printf("steward cost = %d, expected = %d\n", r, 3);
        if (r == 3) // check that correct cost returned
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
        
        // Test tribute
        r = getCost(tribute);
#if (NOISY_TEST == 1)
        printf("tribute cost = %d, expected = %d\n", r, 5);
        if (r == 5) // check that correct cost returned
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
        
        // Test ambassador
        r = getCost(ambassador);
#if (NOISY_TEST == 1)
        printf("ambassador cost = %d, expected = %d\n", r, 3);
        if (r == 3) // check that correct cost returned
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
        
        // Test cutpurse
        r = getCost(cutpurse);
#if (NOISY_TEST == 1)
        printf("cutpurse cost = %d, expected = %d\n", r, 4);
        if (r == 4) // check that correct cost returned
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
        
        // Test embargo
        r = getCost(embargo);
#if (NOISY_TEST == 1)
        printf("embargo cost = %d, expected = %d\n", r, 2);
        if (r == 2) // check that correct cost returned
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
        
        // Test outpost
        r = getCost(outpost);
#if (NOISY_TEST == 1)
        printf("outpost cost = %d, expected = %d\n", r, 5);
        if (r == 5) // check that correct cost returned
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
        
        // Test salvager
        r = getCost(salvager);
#if (NOISY_TEST == 1)
        printf("salvager cost = %d, expected = %d\n", r, 4);
        if (r == 4) // check that correct cost returned
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
        
        // Test sea_hag
        r = getCost(sea_hag);
#if (NOISY_TEST == 1)
        printf("sea_hag cost = %d, expected = %d\n", r, 4);
        if (r == 4) // check that correct cost returned
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
        
        // Test treasure_map
        r = getCost(treasure_map);
#if (NOISY_TEST == 1)
        printf("treasure_map cost = %d, expected = %d\n", r, 4);
        if (r == 4) // check that correct cost returned
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
