/*
** lattice paths
*/

#include <stdio.h>

int main(void) {
    unsigned long long n = 1;
    for (int k = 1; k <= 20; k++) {
        //multiply and divide at the same time to prevent overflow
        n *= (20 + k);
        n /= k;
    }
    printf("lattice path is %llu\n", n);
}
