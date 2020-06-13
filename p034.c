/*
** digit factorials
*/

#include <stdio.h>

/*
** absolute maximum number has no more than 7 digits
*/

int sumfd(int n) {
    static int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    int sum = 0;
    while (n) {
        sum += f[n % 10];
        n /= 10;
    }
    return sum;
}

int main(void) {
    int sum = 0;
    for (int k = 10; k < 10000000; k++) {
        if (sumfd(k) == k) {
            printf("sumfd(%d) works\n", k);
            sum += k;
        }
    }
    printf("sum of numbers like 145 is %d\n", sum);
}
