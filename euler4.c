/*
** largest palindrome product
*/

#include <stdio.h>

int main(void) {
    unsigned long long p = 0;
    char tmp[10];
    for (unsigned long long a = 999; a > 833; a--) {
        for (unsigned long long b = a; b > 833; b--) {
            int n = sprintf(tmp, "%llu", a*b);
            if (tmp[0] != tmp[n-1]) continue;
            if (tmp[1] != tmp[n-2]) continue;
            if (tmp[2] != tmp[n-3]) continue;
            if (a*b > p) p = a*b;
        }
    }
    printf("largest palindrome is %llu.\n", p);
}
