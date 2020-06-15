/*
** distinct prime factors
*/

#include <math.h>
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

unsigned nfactors(unsigned n, struct UnsignedArray *p) {
    unsigned nf = 0;
    for (unsigned k = 0; k < p->n; k++) {
        if (n % p->data[k] == 0) {
            while (n % p->data[k] == 0) n /= p->data[k];
            nf++;
        }
        if (n == 1) break;
    }
    return nf;
}

void addfactors(struct UnsignedArray *a, unsigned last, struct UnsignedArray *h) {
    addprimes(h, sqrt(last) + 7);
    for (unsigned k = a->n; k <= last; k++) {
        if (a->n == a->m) {
            unsigned *tmp = realloc(a->data, 2*a->m * sizeof *tmp);
            a->data = tmp;
            a->m *= 2;
        }
        a->data[a->n] = nfactors(k, h);
        a->n++;
    }
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
    struct UnsignedArray factor[1];
    factor->m = 1000;
    factor->data = malloc(factor->m * sizeof *factor->data);
    factor->n = 0;
    factor->data[factor->n++] = 0; // ignore 0
    factor->data[factor->n++] = 0; // ignore 1
    factor->data[factor->n++] = 1; // 2 is prime
    factor->data[factor->n++] = 1; // 3 is prime
    factor->data[factor->n++] = 1; // 4 = 2^2
    factor->data[factor->n++] = 1; // 5 is prime
    factor->data[factor->n++] = 2; // 6 = 2 * 3

    unsigned n = 4;
    for (;;) {
        addfactors(factor, n + 3, prime);
        if (factor->data[n] >= 4) {
            if (factor->data[n + 1] >= 4) {
                if (factor->data[n + 2] >= 4) {
                    if (factor->data[n + 3] >= 4) {
                        break;
                    }
                }
            }
        }
        n++;
    }
    printf("smallest of four consecutive integer is %u.\n", n);
}
