/*
** double-base palindromes
*/

#include <math.h>
#include <stdio.h>

int pal(unsigned base, unsigned num) {
    int lod = 0;
    int hid = log(num) / log(base);
    while (hid > lod) {
        int nn1 = num, nn2 = num;
        for (int k = 0; k < lod; k++) nn1 /= base;
        for (int k = 0; k < hid; k++) nn2 /= base;
        if (nn1%base != nn2%base) return 0;
        hid--;
        lod++;
    }
    return 1;
}

int main(void) {
    int sum = 0;
    for (int k = 1; k < 1000000; k++) {
        if (pal(2, k) && pal(10, k)) sum += k;
    }
    printf("sum of palindromes is %d.\n", sum);
}
