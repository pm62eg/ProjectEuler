/*
** largest prime factor
*/

#include <stdio.h>

int main(void) {
    unsigned long long n = 600851475143;
    //not even!
    unsigned long long k = 3;
    while (n > k) {
        while (n % k == 0) n /= k;
        k += 2;
    }
    printf("largest factor is %llu.\n", n);
}
