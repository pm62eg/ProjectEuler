/*
** longest collatz sequence
*/

#include <stdio.h>

int collatzlen(long long unsigned n) {
    int len = 0;
    while (n != 1) {
        len++;
        if (n % 2) n = 3*n + 1;
        else n = n/2;
    }
    return len;
}

int main(void) {
    int max = 0, maxlen = 0;
    for (int k = 2; k < 1000000; k++) {
        int clen = collatzlen(k);
        if (clen > maxlen) {
            max = k;
            maxlen = clen;
        }
    }
    printf("longest collatz chain is produced with %d.\n", max);
}
