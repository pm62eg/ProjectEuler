/*
** prime digit replacements
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void recurse(struct UnsignedArray *p, const char *s, int stars) {
    int slen = strlen(s);
    char *ss = malloc(slen + 2);
    if (stars == 0) {
        //work with s
        int primecount = 0, smallestprime = 0;
        for (int x = '0'; x <= '9'; x++) {
            for (int k = 0; k < slen; k++) {
                ss[k] = (s[k] == '*') ? x : s[k];
            }
            if (*ss == '0') continue;
            unsigned N = strtol(ss, 0, 10);
            if (isprime(p, N)) {
                primecount += 1;
                if (smallestprime == 0) smallestprime = N;
            }
        }
        if (primecount >= 8) printf("family %s has %d primes staring with %d\n", s, primecount, smallestprime);
    } else {
        for (int i = 0; i <= slen; i++) {
//            if (s[i] == '*') continue;
            sprintf(ss, "%.*s*%.*s", i, s, slen - i, s + i);
            recurse(p, ss, stars - 1);
        }
    }
    free(ss);
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

    for (int ll = 1; ll < 1000; ll += 2) {
        char tt[10];
        sprintf(tt, "%03d", ll);
        recurse(prime, tt, 3);
    }

    free(prime->data);
    printf("done\n");
}
