/*
** highly divisible triangular number
*/

#include <stdio.h>

int ndivisors(long long unsigned n) {
    if (n == 1) return 1;
    long long unsigned v = 0;
    for (unsigned k = 1; k*k <= n; k++) {
        if (n % k == 0) v += 2;
        if (k*k == n) v--;
    }
    return v;
}

int main(void) {
    unsigned nn = 2;
    long long unsigned n = 1;
    while (ndivisors(n) <= 500) n += nn++;
    printf("%llu has more than 500 divisors.\n", n);
}
