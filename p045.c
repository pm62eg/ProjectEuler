/*
** pentagon numbers
*/

#include <math.h>
#include <stdio.h>

/*
** all hexagonal numbers are also triangular numbers
*/

int ispenta(unsigned long long n) {
    unsigned long long tmp = 24*n + 1;
    unsigned long long tmp2 = sqrt(tmp);
    if (tmp2 * tmp2 != tmp) return 0;
    if ((tmp2 + 1) % 6 != 0) return 0;
    return (tmp2 + 1) / 6;
}

unsigned long long hexa(int n) {
    unsigned long long val = n * (2 * n - 1);
    return val;
}

int main(void) {
    int n = 1;
    int matches = 0;
    while (matches < 3) {
        unsigned long long h = hexa(n);
        int tmp;
        if ((tmp = ispenta(h)) != 0) {
            printf("found H(%d) = P(%d) = T(%d) = %llu\n", n, tmp, 2*n-1, h);
            matches += 1;
        }
        n++;
    }
}
