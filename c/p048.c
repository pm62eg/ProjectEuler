/*
** self powers
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//reuse code from problem 29
#define RESULT_SIZE 10

void BigADD(unsigned char *dst, unsigned char *src1, unsigned char *src2, int size) {
    int carry = 0;
    for (int k = 0; k < size; k++) {
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

void BigMUL(unsigned char *dst, unsigned char *src, int size, int factor) {
    unsigned char tmp[size];
    memset(tmp, 0, sizeof tmp);
    while (factor--) {
        BigADD(dst, tmp, src, size);
        memcpy(tmp, dst, size);
    }
}

void BigPOW(unsigned char *dst, int size, int exponent) {
    unsigned char tmp[size];
    memset(tmp, 0, sizeof tmp);
    tmp[0] = 1;
    int base = exponent;
    while (exponent--) {
        BigMUL(dst, tmp, size, base);
        memcpy(tmp, dst, size);
    }
}

int main(void) {
    unsigned char q[RESULT_SIZE] = {0};
    unsigned char r[RESULT_SIZE] = {0};
    unsigned char s[RESULT_SIZE] = {0};
    for (int a = 1; a <= 1000; a++) {
        BigPOW(q, RESULT_SIZE, a);
        BigADD(s, r, q, RESULT_SIZE);
        memcpy(r, s, RESULT_SIZE);
    }
    printf("the series of sums of self powers ends with ");
    for (int k = RESULT_SIZE - 1; k >= 0; k--) putchar(r[k] + '0');
    printf(".\n");
}
