/*
** amicable numbers
*/

#include <stdio.h>

int sumdivisors(int n) {
    int sum = 1;
    int div = 2;
    while (div*div <= n) {
        if (n % div == 0) {
            sum += div;
            if (div*div != n) sum += (n / div);
        }
        div++;
    }
    return sum;
}

int main(void) {
    int spd[10000] = {0};
    int sum = 0;
    for (int k = 1; k < 10000; k++) {
        spd[k] += sumdivisors(k);
    }
    for (int k = 1; k < 10000; k++) {
        if ((spd[k] < 10000) && (spd[k] != k) && (spd[spd[k]]) == k) {
            printf("amicable numers: %d and %d\n", k, spd[k]);
            sum += k;
        }
    }
    printf("sum of amicable numbers is %d.\n", sum);
}
