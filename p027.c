/*
** quadratic primes
*/

#include <stdio.h>
#include <stdlib.h>

int fx(int a, int b, int n) {
    int val = n*n + a*n + b;
    return val;
}

struct IntArray {
    int m, n; // reserved, used
    int *data;
};

void addprime(struct IntArray *a, int p) {
    if (a->n == a->m) {
        int *tmp = realloc(a->data, 2*a->m * sizeof *tmp);
        // assume it worked
        a->data = tmp;
        a->m *= 2;
    }
    a->data[a->n++] = p;
}

int checkprime(struct IntArray *a, int p) {
    int index = 0;
    while (a->data[index] * a->data[index] <= p) {
        if (p % a->data[index] == 0) return 0;
        index++;
    }
    return 1;
}

void addprimes(struct IntArray *a, int last) {
    int check = a->data[a->n - 1];
    int second;
    do {
        second = 0;
        check += 4;
        if (checkprime(a, check)) { addprime(a, check); }
        check += 2;
        if (checkprime(a, check)) { addprime(a, check); second = 1; }
    } while ((second == 0) || (check < last));
}

int delta(const void *aa, const void *bb) {
    const int *a = aa;
    const int *b = bb;
    return b - a;
}

int isprime(struct IntArray *a, int p) {
    if (p < 2) return 0;
    if (p > a->data[a->n - 1]) addprimes(a, p);
    for (int k = 0; k < a->n; k++) {
        if (a->data[k] == p) return 1;
    }
    return 0;
}

int main(void) {
    struct IntArray p[1];
    p->m = 16;
    p->data = malloc(p->m * sizeof *p->data);
    // assume it worked
    p->n = 0;
    p->data[p->n++] = 2;
    p->data[p->n++] = 3;
    p->data[p->n++] = 5;
    p->data[p->n++] = 7;
    int maxprimes = 0, maxa, maxb;
    for (int a = -999; a <= 999; a++) {
        for (int b = -1000; b <= 1000; b++) {
            int n = 0, primecount = 0;
            for (;;) {
                int candidate = fx(a, b, n);
                if (isprime(p, candidate)) {
                    primecount += 1;
                    n++;
                    candidate = fx(a, b, n);
                } else {
                    break;
                }
            }
            if (primecount > maxprimes) {
                maxprimes = primecount;
                maxa = a;
                maxb = b;
            }
        }
    }
    free(p->data);
    printf("the product for %d primes is at %d.\n", maxprimes, maxa * maxb);
}
