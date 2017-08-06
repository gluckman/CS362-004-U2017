// David Gluckman
// CS 362 Section 400 Summer 2017
// Assignment 4 - Random Testing
// Random test for playGreat_Hall
// randomtestcard2.c

// Adapted from testDrawCard.c

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "rngs.h"

int randomTestGreat_Hall(int p, struct gameState *post, int *failCount, int *passCount) {
    // Copy starting game state
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));
    
    int r;
    int handPos = 1;
    
    printf ("Great Hall PRE : p %d HC %d DeC %d DiC %d A %d\n",
            p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p], pre.numActions);
    
    //printf("START\n");
    //fflush(stdout);
    
    r = cardEffect(great_hall, 0, 0, 0, post, handPos, NULL);
    
    //printf("DONE\n");
    //fflush(stdout);
    
    printf ("Great Hall POST: p %d HC %d DeC %d DiC %d A %d\n",
            p, post->handCount[p], post->deckCount[p], post->discardCount[p], post->numActions);
    
    // Mimic changes in pre
    int nextCard;
    
    // Handle empty deck if necessary
    if (pre.deckCount[p] < 1) {
        memcpy(pre.deck[p], post->deck[p], sizeof(int) * pre.discardCount[p]);
        memcpy(pre.discard[p], post->discard[p], sizeof(int)*pre.discardCount[p]);
        pre.deckCount[p] = pre.discardCount[p];
        pre.discardCount[p] = 0;
        printf("SHUFFLED\n");
    }
        
    nextCard = pre.deck[p][pre.deckCount[p] - 1];
    pre.deckCount[p]--;
    pre.hand[p][pre.handCount[p]] = nextCard;
    //pre.handCount[p]++;
    printf("Added card: %d\n", nextCard);
    
    //memcpy(pre.discard[p], post->discard[p], sizeof(int)*pre.discardCount[p]);
    
    pre.numActions++;
    
    
    printf ("Great Hall PRE2: p %d HC %d DeC %d DiC %d A %d\n",
            p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p], pre.numActions);
    
    // Check for expected results
    
    assert (r == 0);
    
    if (memcmp(&pre, post, sizeof(struct gameState)) == 0) {
        (*passCount)++;
        printf("<------SUCCESS------>\n\n");
    }
    else {
        (*failCount)++;
        printf("<------FAILURE------>\n\n");
    }
    return 0;
}

int main () {
    
    // Declare variables
    int i, n, p, s;
    int failCount = 0;
    int passCount = 0;
    //int deckCount, discardCount, handCount;
    struct gameState G;
    
    printf ("Random testing playGreat_Hall():\n");
    
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
        
        // Set relevant variables for all players
        for (s = 0; s < 2; s++)
        {
            G.deckCount[s] = floor(Random() * MAX_DECK);
            G.discardCount[s] = floor(Random() * MAX_DECK);
            G.handCount[s] = floor(Random() * MAX_HAND);
            
            // Set cards in deck, hand, discard randomly
            for (i = 0; i < G.deckCount[s]; i++) {
                G.deck[s][i] = floor(Random() * cardTypes);
            }
            for (i = 0; i < G.handCount[s]; i++) {
                G.hand[s][i] = floor(Random() * cardTypes);
            }
            for (i = 0; i < G.discardCount[s]; i++) {
                G.discard[s][i] = floor(Random() * cardTypes);
            }
        }
        
        // Set current player
        G.whoseTurn = p;
        
        // Set played card count
        G.playedCardCount = 0;
        
        // Set number of actions
        G.numActions = 0;
        
        printf("\n");
        fflush(stdout);
        
        // Pass to test function
        randomTestGreat_Hall(p, &G, &failCount, &passCount);
    }
    
    if (failCount == 0) {
        printf ("ALL TESTS OK\n\n");
        
    }
    else {
        printf("Passed: %d, failed: %d\n\n", passCount, failCount);
    }
    
    return 0;
}
