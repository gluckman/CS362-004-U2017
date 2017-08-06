// David Gluckman
// CS 362 Section 400 Summer 2017
// Assignment 4 - Random Testing
// Random test for adventurerEffect
// randomtestadventurer.c

// Adapted from testDrawCard.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

int randomTestAdventurer(int p, struct gameState *post, int *failCount, int *passCount) {
    // Copy starting game state
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    
    int r;
    printf ("Adventurer PRE : p %d HC %d DeC %d DiC %d\n",
            p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
    
    //printf("START\n");
    //fflush(stdout);
    
    r = adventurerEffect(post);
    
    //printf("DONE\n");
    //fflush(stdout);
    
    printf ("Adventurer POST: p %d HC %d DeC %d DiC %d\n",
            p, post->handCount[p], post->deckCount[p], post->discardCount[p]);
    
    // Mimic changes in pre
    int shuffled = 0;
    int treasureCount = 0;
    int nextCard;
    
    // Draw cards until one or two treasure found
    while (treasureCount < 2)
    {
        // Handle empty deck if necessary
        if (pre.deckCount[p] < 1 && shuffled == 0) {
            memcpy(pre.deck[p], post->deck[p], sizeof(int) * pre.discardCount[p]);
            memcpy(pre.discard[p], post->discard[p], sizeof(int)*pre.discardCount[p]);
            pre.deckCount[p] = pre.discardCount[p];
            pre.discardCount[p] = 0;
            shuffled++;
            printf("SHUFFLED\n");
        }
        
        nextCard = pre.deck[p][pre.deckCount[p] - 1];
        pre.deckCount[p]--;
        if (nextCard == copper || nextCard == silver || nextCard == gold)
        {
            pre.hand[p][pre.handCount[p]] = nextCard;
            pre.handCount[p]++;
            treasureCount++;
            printf("Found card: %d\n", nextCard);
        }
        else
        {
            pre.discard[p][pre.discardCount[p]] = nextCard;
            pre.discardCount[p]++;
        }
        
        if (pre.deckCount[p] < 1 && shuffled == 1)
        {
            treasureCount = 2;
            printf("WOULD HAVE SHUFFLED\n");
        }
    }
    
    memcpy(pre.discard[p], post->discard[p], sizeof(int)*pre.discardCount[p]);
    
    
    printf ("Adventurer PRE2: p %d HC %d DeC %d DiC %d\n",
            p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
    
    // Check if card is treasure
    
    // Count each treasure card type before
    
    
    // If card(s) left in deck
    /*if (pre.deckCount[p] > 0) {
     pre.handCount[p]++;
     pre.hand[p][pre.handCount[p]-1] = pre.deck[p][pre.deckCount[p]-1];
     pre.deckCount[p]--;
     }
     // Else if card(s) in discard pile
     else if (pre.discardCount[p] > 0) {
     memcpy(pre.deck[p], post->deck[p], sizeof(int) * pre.discardCount[p]);
     memcpy(pre.discard[p], post->discard[p], sizeof(int)*pre.discardCount[p]);
     pre.hand[p][post->handCount[p]-1] = post->hand[p][post->handCount[p]-1];
     pre.handCount[p]++;
     pre.deckCount[p] = pre.discardCount[p]-1;
     pre.discardCount[p] = 0;
     }
     */
    
    // Check for expected results
    
    assert (r == 0);
    
    if (memcmp(&pre, post, sizeof(struct gameState)) == 0) {
        (*passCount)++;
    }
    else {
        (*failCount)++;
        printf("<------FAILURE------>\n\n");
    }
    return 0;
}

int main () {
    
    // Declare variables
    int i, n, p;
    int failCount = 0;
    int passCount = 0;
    //int deckCount, discardCount, handCount;
    struct gameState G;
    
    printf ("Random testing adventurerEffect():\n");
    
    SelectStream(2);
    PutSeed(3);
    
    int testRuns = 10000;
    int cardTypes = 27;
    
    // Multiple iterations of random test
    for (n = 0; n < testRuns; n++) {
        // Clear the game struct
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        
        // Set relevant variables
        p = floor(Random() * 2);
        G.deckCount[p] = floor(Random() * MAX_DECK);
        G.discardCount[p] = floor(Random() * MAX_DECK);
        G.handCount[p] = floor(Random() * MAX_HAND);
        
        // Set cards in deck, hand, discard randomly
        for (i = 0; i < G.deckCount[p]; i++) {
            G.deck[p][i] = floor(Random() * cardTypes);
        }
        for (i = 0; i < G.handCount[p]; i++) {
            G.hand[p][i] = floor(Random() * cardTypes);
        }
        for (i = 0; i < G.discardCount[p]; i++) {
            G.discard[p][i] = floor(Random() * cardTypes);
        }
        
        // Set current player
        G.whoseTurn = p;
        
        printf("\n");
        fflush(stdout);
        
        // Pass to test function
        randomTestAdventurer(p, &G, &failCount, &passCount);
    }
    
    if (failCount == 0) {
        printf ("ALL TESTS OK\n\n");
        
    }
    else {
        printf("Passed: %d, failed: %d\n\n", passCount, failCount);
    }
    
    return 0;
}
