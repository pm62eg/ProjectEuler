/*
** digit fifth powers
*/

#include <stdio.h>

int main(void) {
    int sum = 0;
    int p4[10] = {0, 1, 16, 81, 256, 625, 1296, 2401, 4096, 6561};
    int p5[10] = {0, 1, 32, 243, 1024, 3125, 7776, 16807, 32768, 59049};
    for (int n = 10; n < 543210; n++) {
        int d5 = n / 100000 % 10;
        int d4 = n / 10000 % 10;
        int d3 = n / 1000 % 10;
        int d2 = n / 100 % 10;
        int d1 = n / 10 % 10;
        int d0 = n / 1 % 10;
        if (p5[d0] + p5[d1] + p5[d2] + p5[d3] + p5[d4] + p5[d5] == n) {
            sum += n;
            printf("%d\n", n);
        }
    }
    printf("sum of all numbers is %d.\n", sum);
}
