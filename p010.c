/*
** summation of primes
*/

#include <stdio.h>
#include <stdlib.h>

#define LIMIT 2000000

int prime(int n, int *p, int m) {
    for (int k = 0; k < m; k++) {
        if (n % p[k] == 0) return 0;
        if (p[k] * p[k] >= n) return 1;
    }
    return 1;
}

int main(void) {
    int *p = calloc(2000000, sizeof *p);
    int np = 1;
    *p = 2;
    int n = 3;
    long long unsigned sum = 2;
    while (n < LIMIT) {
        if (prime(n, p, np)) {
            // add n to p
            p[np++] = n;
            sum += n;
        }
        n += 2;
    }
    printf("sum is %llu\n", sum);
}
