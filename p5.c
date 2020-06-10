/*
** smallest multiple
*/

#include <stdio.h>

#define LIMIT 20

int main(void) {
    int k[LIMIT + 1] = {0};
    for (int n = 2; n <= LIMIT; n++) {
        int kk[LIMIT + 1] = {0};
        int m = n;
        while (m % 2 == 0) { m /= 2; kk[2]++; }
        while (m % 3 == 0) { m /= 3; kk[3]++; }
        while (m % 5 == 0) { m /= 5; kk[5]++; }
        while (m % 7 == 0) { m /= 7; kk[7]++; }
        while (m % 11 == 0) { m /= 11; kk[11]++; }
        while (m % 13 == 0) { m /= 13; kk[13]++; }
        while (m % 17 == 0) { m /= 17; kk[17]++; }
        while (m % 19 == 0) { m /= 19; kk[19]++; }
        for (int m = 0; m <= LIMIT; m++) if (kk[m] > k[m]) k[m] = kk[m];
    }
    int p = 1;
    for (int n = 2; n <= LIMIT; n++) {
        while (k[n]--) p *= n;
    }
    printf("smallest multiple is %d.\n", p);
}
