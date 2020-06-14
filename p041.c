/*
** pandigital prime
*/

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
    int nnn;
    for (int a = 7; a > 0; a--)
    for (int b = 7; b > 0; b--) if (b==a) continue; else
    for (int c = 7; c > 0; c--) if (c==b||c==a) continue; else
    for (int d = 7; d > 0; d--) if (d==c||d==b||d==a) continue; else
    for (int e = 7; e > 0; e--) if (e==d||e==c||e==b||e==a) continue; else
    for (int f = 7; f > 0; f--) if (f==e||f==d||f==c||f==b||f==a) continue; else
    for (int g = 7; g > 0; g--) {
        if (g==f||g==e||g==d||g==c||g==b||g==a) continue;
        nnn = 1000000*a+100000*b+10000*c+1000*d+100*e+10*f+g;
        if (isprime(p, nnn)) a=b=c=d=e=f=g=0;
    }

    printf("the largest pandigital prime is %d.\n", nnn);
}
