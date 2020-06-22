/*
** circular primes
*/

#include <stdio.h>
#include <stdlib.h>

//copy from problem 27

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

int buckethas(struct IntArray *b, int v) {
    for (int k = 0; k < b->n; k++) {
        if (b->data[k] == v) return 1;
    }
    return 0;
}

void bucketadd(struct IntArray *b, int val) {
    if (buckethas(b, val)) return;
    if (b->n == b->m) {
        int *tmp = realloc(b->data, 2*b->m * sizeof *tmp);
        b->data = tmp;
        b->m *= 2;
    }
    b->data[b->n++] = val;
}

int main(void) {
    struct IntArray B[1];
    B->m = 2;
    B->data = malloc(B->m * sizeof *B->data);
    // assume it worked
    B->n = 0;

    struct IntArray p[1];
    p->m = 16;
    p->data = malloc(p->m * sizeof *p->data);
    // assume it worked
    p->n = 0;

    //one digit
    p->data[p->n++] = 2; bucketadd(B, 2);
    p->data[p->n++] = 3; bucketadd(B, 3);
    p->data[p->n++] = 5; bucketadd(B, 5);
    p->data[p->n++] = 7; bucketadd(B, 7);
    printf("there are %d circular primes with 1 or fewer digits.\n", B->n);

    // two digits
    for (int a = 1; a <= 9; a+=2)
    for (int b = 1; b <= 9; b+=2) {
        if (buckethas(B, a*10+b)) continue;
        if (isprime(p, 10*a+b) &&
            isprime(p, 10*b+a)) {
            printf("%d%d and its rotations are prime.\n", a, b);
            bucketadd(B, 10*a+b);
            bucketadd(B, 10*b+a);
        }
    }
    printf("there are %d circular primes with 2 or fewer digits.\n", B->n);

    // three digits
    for (int a = 1; a <= 9; a+=2)
    for (int b = 1; b <= 9; b+=2)
    for (int c = 1; c <= 9; c+=2) {
        if (buckethas(B, a*100+b*10+c)) continue;
        if (isprime(p, 100*a+10*b+c) &&
            isprime(p, 100*b+10*c+a) &&
            isprime(p, 100*c+10*a+b)) {
            printf("%d%d%d and its rotations are prime.\n", a, b, c);
            bucketadd(B, 100*a+10*b+c);
            bucketadd(B, 100*b+10*c+a);
            bucketadd(B, 100*c+10*a+b);
        }
    }
    printf("there are %d circular primes with 3 or fewer digits.\n", B->n);

    // four digits
    for (int a = 1; a <= 9; a+=2)
    for (int b = 1; b <= 9; b+=2)
    for (int c = 1; c <= 9; c+=2)
    for (int d = 1; d <= 9; d+=2) {
        if (buckethas(B, a*1000+b*100+c*10+d)) continue;
        if (isprime(p, 1000*a+100*b+10*c+d) &&
            isprime(p, 1000*b+100*c+10*d+a) &&
            isprime(p, 1000*c+100*d+10*a+b) &&
            isprime(p, 1000*d+100*a+10*b+c)) {
            printf("%d%d%d%d and its rotations are prime.\n", a, b, c, d);
            bucketadd(B, 1000*a+100*b+10*c+d);
            bucketadd(B, 1000*b+100*c+10*d+a);
            bucketadd(B, 1000*c+100*d+10*a+b);
            bucketadd(B, 1000*d+100*a+10*b+c);
        }
    }
    printf("there are %d circular primes with 4 or fewer digits.\n", B->n);

    // five digits
    for (int a = 1; a <= 9; a+=2)
    for (int b = 1; b <= 9; b+=2)
    for (int c = 1; c <= 9; c+=2)
    for (int d = 1; d <= 9; d+=2)
    for (int e = 1; e <= 9; e+=2) {
        if (buckethas(B, a*10000+b*1000+c*100+d*10+e)) continue;
        if (isprime(p, 10000*a+1000*b+100*c+10*d+e) &&
            isprime(p, 10000*b+1000*c+100*d+10*e+a) &&
            isprime(p, 10000*c+1000*d+100*e+10*a+b) &&
            isprime(p, 10000*d+1000*e+100*a+10*b+c) &&
            isprime(p, 10000*e+1000*a+100*b+10*c+d)) {
            printf("%d%d%d%d%d and its rotations are prime.\n", a, b, c, d, e);
            bucketadd(B, 10000*a+1000*b+100*c+10*d+e);
            bucketadd(B, 10000*b+1000*c+100*d+10*e+a);
            bucketadd(B, 10000*c+1000*d+100*e+10*a+b);
            bucketadd(B, 10000*d+1000*e+100*a+10*b+c);
            bucketadd(B, 10000*e+1000*a+100*b+10*c+d);
        }
    }
    printf("there are %d circular primes with 5 or fewer digits.\n", B->n);

    // six digits
    for (int a = 1; a <= 9; a+=2)
    for (int b = 1; b <= 9; b+=2)
    for (int c = 1; c <= 9; c+=2)
    for (int d = 1; d <= 9; d+=2)
    for (int e = 1; e <= 9; e+=2)
    for (int f = 1; f <= 9; f+=2) {
        if (buckethas(B, a*100000+b*10000+c*1000+d*100+e*10+f)) continue;
        if (isprime(p, 100000*a+10000*b+1000*c+100*d+10*e+f) &&
            isprime(p, 100000*b+10000*c+1000*d+100*e+10*f+a) &&
            isprime(p, 100000*c+10000*d+1000*e+100*f+10*a+b) &&
            isprime(p, 100000*d+10000*e+1000*f+100*a+10*b+c) &&
            isprime(p, 100000*e+10000*f+1000*a+100*b+10*c+d) &&
            isprime(p, 100000*f+10000*a+1000*b+100*c+10*d+e)) {
            printf("%d%d%d%d%d%d and its rotations are prime.\n", a, b, c, d, e, f);
            bucketadd(B, 100000*a+10000*b+1000*c+100*d+10*e+f);
            bucketadd(B, 100000*b+10000*c+1000*d+100*e+10*f+a);
            bucketadd(B, 100000*c+10000*d+1000*e+100*f+10*a+b);
            bucketadd(B, 100000*d+10000*e+1000*f+100*a+10*b+c);
            bucketadd(B, 100000*e+10000*f+1000*a+100*b+10*c+d);
            bucketadd(B, 100000*f+10000*a+1000*b+100*c+10*d+e);
        }
    }
    printf("there are %d circular primes with 6 or fewer digits.\n", B->n);
    free(B->data);
    free(p->data);
}
