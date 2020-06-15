/*
** truncatable primes
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

int isprime(struct IntArray *a, int p) {
    if (p < 2) return 0;
    if (p > a->data[a->n - 1]) addprimes(a, p);
    for (int k = 0; k < a->n; k++) {
        if (a->data[k] == p) return 1;
    }
    return 0;
}

int truncatable(struct IntArray *p, int n) {
    int nn = n;
    while (nn) {
        if (!isprime(p, nn)) return 0;
        nn /= 10;
    }
    nn = n;
    int nnn = 10;
    while (nnn < n) nnn *= 10;
    nnn /= 10;
    while (nnn) {
        while (nn >= nnn) nn -= nnn;
        if (nn && !isprime(p, nn)) return 0;
        nnn /= 10;
    }
    return 1;
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
    int sum = 0, n = 9, k = 0;
    for (;;) {
        n += 2;
        if (truncatable(p, n)) {
            printf("%d is truncatable\n", n);
            sum += n;
            k++;
        }
        if (k == 11) break;
    }
    free(p->data);
    printf("sum of truncatable primes is %d.\n", sum);
}
