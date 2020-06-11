/*
** power digit sum
*/

#include <stdio.h>

#define RESULT_LENGTH 320
#define EXPONENT 1000

void twice(unsigned char *v, int n) {
    int carry = 0;
    while (--n) {
        v[n] = 2 * v[n] + carry;
        carry = v[n] / 10;
        v[n] -= carry * 10;
    }
}

int main(void) {
    unsigned char thou[RESULT_LENGTH] = {0};
    thou[RESULT_LENGTH - 1] = 1;
    for (int k = 0; k < EXPONENT; k++) twice(thou, RESULT_LENGTH);
    int sum = 0;
    for (int k = 0; k < RESULT_LENGTH; k++) sum += thou[k];
    printf("sum of digits is %d\n", sum);
}
