/*
** 10001st prime
*/

#include <stdio.h>
#include <stdlib.h>

#define N 10001

int main(void) {
    int *primes = calloc(N + 1, sizeof *primes);
    if (!primes) { fprintf(stderr, "No memory. Program aborted.\n"); exit(EXIT_FAILURE); }
    int nprimes = 0;
    primes[nprimes++] = 2;
    int n = 3;
    while (nprimes <= N) {
        int p = 0;
        for (int k = 0; k < nprimes; k++) {
            if (n % primes[k] == 0) { p = 1; break; }
        }
        if (!p) primes[nprimes++] = n;
        n += 2;
    }
    for (int k = 0; k < nprimes; k++) printf("prime #%d: %d\n", k + 1, primes[k]);
    printf("The %dth prime is %d\n", N, primes[N-1]);
}
