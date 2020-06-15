/*
** prime permutations
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

int permutations(unsigned a, unsigned b) {
    char ka[10] = {0}, kb[10] = {0};
    ka[a%10]++; kb[b%10]++;
    a/=10;      b/=10;
    ka[a%10]++; kb[b%10]++;
    a/=10;      b/=10;
    ka[a%10]++; kb[b%10]++;
    a/=10;      b/=10;
    ka[a%10]++; kb[b%10]++;
    for (int k = 0; k < 10; k++) if (ka[k] != kb[k]) return 0;
    return 1;
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
    addprimes(prime, 10000);

    for (unsigned p1 = 1001; p1 < 10000; p1 += 2) {
        if (!isprime(prime, p1)) continue;
        for (unsigned delta = 6; delta < 5000; delta += 6) {
//            if ((p1 == 1487) && (delta == 3330)) {
//                printf("reached 1st solution\n");
//            }
            unsigned p2 = p1 + delta;
            if (p2 >= 10000) continue;
            if (!isprime(prime, p2)) continue;
            if (!permutations(p1, p2)) continue;
            unsigned p3 = p2 + delta;
            if (p3 >= 10000) continue;
            if (!isprime(prime, p3)) continue;
            if (!permutations(p1, p3)) continue;
            printf("primes %u, %u, and %u\n", p1, p2, p3);
        }
    }
    printf("done\n");
}
