/*
** goldbach's other conjecture
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

void addsquare2s(struct UnsignedArray *a, unsigned last) {
    unsigned check;
    do {
        if (a->n == a->m) {
            unsigned *tmp = realloc(a->data, 2*a->m * sizeof *tmp);
            a->data = tmp;
            a->m *= 2;
        }
        check = a->data[a->n] = 2 * a->n * a->n;
        a->n++;
    } while (check < last);
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
    struct UnsignedArray square2[1];
    square2->m = 12;
    square2->data = malloc(square2->m * sizeof *square2->data);
    square2->n = 0;
    square2->data[square2->n++] = 0;
    square2->data[square2->n++] = 2;
    square2->data[square2->n++] = 8;
    struct UnsignedArray prime[1];
    prime->m = 16;
    prime->data = malloc(prime->m * sizeof *prime->data);
    prime->n = 0;
    prime->data[prime->n++] = 2;
    prime->data[prime->n++] = 3;
    prime->data[prime->n++] = 5;
    prime->data[prime->n++] = 7;
    unsigned n = 7;
    for (;;) {
        n += 2;
        addsquare2s(square2, n);
        addprimes(prime, n);
        if (!isprime(prime, n)) {
            int found = 0;
            unsigned k = square2->n - 1;
            while (n < square2->data[k]) k--;
            while (k > 0) {
                if (isprime(prime, n - square2->data[k])) {
                    printf("%u = %u + 2*(%u^2)\n", n, n - square2->data[k], k);
                    found = 1;
                    break;
                }
                k--;
            }
            if (!found) {
                printf("unable to find sum for %d.\n", n);
                break;
            }
        }
    }
    free(prime->data);
    free(square2->data);
    printf("smallest odd composite is %u.\n", n);
}
