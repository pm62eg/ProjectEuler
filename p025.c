/*
** 1000-digit Fibonacci number
*/

#include <stdio.h>
#include <string.h>

#define NUMDIGITS 1000

void invprint(const unsigned char *p) {
    int index = 1007;
    while (p[index] == 0) index--;
    while (index >= 0) putchar(p[index--] + '0');
    putchar('\n');
}

void sum(unsigned char *restrict dst,
         const unsigned char *restrict src1,
         const unsigned char *restrict src2) {
    int carry = 0;
    for (int k = 0; k < 1005; k++) {
        dst[k] = src1[k] + src2[k] + carry;
        if (dst[k] > 9) {
            carry = 1;
            dst[k] -= 10;
        } else {
            carry = 0;
        }
    }
}

int main(void) {
    unsigned char f1[1010] = "\x01", f2[1010] = "\x01", f3[1010] = "";
    int index = 2;
    while (f3[NUMDIGITS-1] == 0) {
        sum(f3, f1, f2); // f3 = f1 + f2
        memcpy(f1, f2, 1010);
        memcpy(f2, f3, 1010);
        index += 1;
        //printf("f(%d) is ", index); invprint(f3);
    }
    printf("the index is %d.\n", index);
}
