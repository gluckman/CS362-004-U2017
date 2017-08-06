// David Gluckman
// CS 362 Section 400 Summer 2017
// Assignment 3 - unit testing
// unittest4.c

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
    int i, j, m, n, p, q, s, t, u, v;
    int *r;

    printf ("\n\nTESTING kingdomCards():\n");
    for (i = 0; i < 27; i++)
    {
        for (j = 1; j < i; j++)
        {
            for (m = 2; m < j; m++)
            {
                for (n = 3; n < m; n++)
                {
                    for (p = 4; p < n; p++)
                    {
                        for (q = 5; q < p; q++)
                        {
                            for (s = 6; s < q; s++)
                            {
                                for (t = 7; t < s; t++)
                                {
                                    for (u = 8; u < t; u++)
                                    {
                                        for (v = 9; v < u; v++)
                                        {
#if (NOISY_TEST == 1)
                                            printf("Test with %d, %d, %d, %d, %d, %d, %d, %d, %d, %d.\n", i, j, m, n, p, q, s, t, u, v);
#endif
                                            int check[10] = {i, j, m, n, p, q, s, t, u, v};
                                            r = kingdomCards(i, j, m, n, p, q, s, t, u, v);
#if (NOISY_TEST == 1)
                                            printf("result = %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9]);
                                            printf("expect = %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", check[0], check[1], check[2], check[3], check[4], check[5], check[6], check[7], check[8], check[9]);
                                            if (r[0] == check[0] && r[1] == check[1] && r[2] == check[2] && r[3] == check[3] && r[4] == check[4] && r[5] == check[5] && r[6] == check[6] && r[7] == check[7] && r[8] == check[8] && r[9] == check[9]) // check that correct array returned
                                            {
                                                printf("\tPASS\n");
                                                passCount++;
                                            }
                                            else
                                            {
                                                printf("\tFAIL\n");
                                                failCount++;
#endif
                                            }
                                        }
                                    }
                                }
                            }
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
