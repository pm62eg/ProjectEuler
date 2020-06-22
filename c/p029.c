/*
** distinct powers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//100^100 = (10^2)^100 = 10^200
#define RESULT_SIZE 222

void BigOUT(const unsigned char *p) {
    int index = RESULT_SIZE - 1;
    while (p[index] == 0) index--;
    while (index) putchar(p[index--]);
    puts("");
}

void BigADD(unsigned char *dst, unsigned char *src1, unsigned char *src2) {
    int carry = 0;
    for (int k = 0; k < RESULT_SIZE; k++) {
        unsigned char tmp = src1[k] + src2[k] + carry;
        if (tmp > 9) {
            carry = 1;
            dst[k] = tmp - 10;
        } else {
            carry = 0;
            dst[k] = tmp;
        }
    }
}

void BigMUL(unsigned char *dst, unsigned char *src, int factor) {
    unsigned char tmp[RESULT_SIZE] = {0};
    while (factor--) {
        BigADD(dst, tmp, src);
        memcpy(tmp, dst, RESULT_SIZE);
    }
}

void BigPOW(unsigned char *dst, int base, int exponent) {
    unsigned char tmp[RESULT_SIZE] = {1};
    while (exponent--) {
        BigMUL(dst, tmp, base);
        memcpy(tmp, dst, RESULT_SIZE);
    }
}

int xpto(const void *aa, const void *bb) {
    return memcmp(aa, bb, RESULT_SIZE);
}

int main(void) {
    unsigned char q[101][101][RESULT_SIZE] = {0};
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            BigPOW(q[a][b], a, b);
        }
    }
    int terms = 0;
    unsigned char (*Q)[RESULT_SIZE] = (void*)q;
    qsort(Q, 101*101, RESULT_SIZE, xpto);
    for (int k = 1; k < 101*101; k++) {
        if (memcmp(Q[k], Q[k-1], RESULT_SIZE)) terms++;
    }
    printf("there are %d distinct terms.\n", terms);
}
