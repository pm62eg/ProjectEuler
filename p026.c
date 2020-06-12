/*
** reciprocal cycles
*/

#include <stdio.h>

// long division (without remembering little steps)
int recurringcycle(int n) {
    int divisor = 1;
    while (divisor * 10 < n) divisor *= 10;
    int divs[1000] = {0};
    int count = 0;
    while (divs[divisor] == 0) {
        divs[divisor] = 1;
        int digit = divisor * 10 / n;
        int tmp = digit * n;
        divisor = divisor * 10 - tmp;
        count++;
    }
    return count;
}

int main(void) {
    int n = 999;
    while (recurringcycle(n) < n - 1) n--;
    printf("the largest recurring cycle is at %d.\n", n);
}
