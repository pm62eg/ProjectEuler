/*
** consecutive prime sum
*/

#include <stdio.h>
#include <stdlib.h>

struct UnsignedArray {
    unsigned m, n; // reserved, used
    unsigned *data;
};

void addprime(struct UnsignedArray *a, unsigned p) {
    if (a->n == a->m) {
        unsigned *tmp = realloc(a->data, 2*a->m * sizeof *tmp);
        // assume it worked
        a->data = tmp;
        a->m *= 2;
    }
    a->data[a->n++] = p;
}

int checkprime(struct UnsignedArray *a, unsigned p) {
    unsigned index = 0;
    while (a->data[index] * a->data[index] <= p) {
        if (p % a->data[index] == 0) return 0;
        index++;
    }
    return 1;
}

void addprimes(struct UnsignedArray *a, unsigned last) {
    unsigned check = a->data[a->n - 1];
    unsigned second;
    do {
        second = 0;
        check += 4;
        if (checkprime(a, check)) { addprime(a, check); }
        check += 2;
        if (checkprime(a, check)) { addprime(a, check); second = 1; }
    } while ((second == 0) || (check < last));
}

int isprime(struct UnsignedArray *a, unsigned p) {
    if (p < 2) return 0;
    if (p > a->data[a->n - 1]) addprimes(a, p);
    for (unsigned k = 0; k < a->n; k++) {
        if (a->data[k] == p) return 1;
    }
    return 0;
}

int main(void) {
    struct UnsignedArray prime[1];
    prime->m = 16;
    prime->data = malloc(prime->m * sizeof *prime->data);
    prime->n = 0;
    prime->data[prime->n++] = 2;
    prime->data[prime->n++] = 3;
    prime->data[prime->n++] = 5;
    prime->data[prime->n++] = 7;
    addprimes(prime, 1000000);

    for (unsigned terms = 6; terms < 10000; terms++) {
        for (unsigned start = 0; start < prime->n; start++) {
            unsigned sum = 0;
            for (unsigned k = 0; k < terms; k++) sum += prime->data[start + k];
            if (sum > 1000000) { start = prime->n; continue; }
            if (isprime(prime, sum)) {
                printf("%u is the sum of %u primes starting with %u\n",
                      sum, terms, prime->data[start]);
            }
        }
    }
    printf("done\n");
}
