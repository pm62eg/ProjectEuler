/*
** non-abundant sums
*/

#include <stdio.h>

#define LIMIT 28124

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
    int abundant[LIMIT] = {0};
    for (int k = 5; k < LIMIT; k++) abundant[k] = (sumdivisors(k) > k);
    int suma[2 * LIMIT] = {0};
    for (int a = 0; a < LIMIT; a++) {
        if (abundant[a]) {
            for (int b = a; b < LIMIT; b++) {
                if (abundant[b]) {
                    suma[a + b] += 1;
                }
            }
        }
    }
    int sumnot = 0;
    for (int k = 0; k < LIMIT; k++) {
        if (suma[k] == 0) {
            sumnot += k;
        }
    }
    printf("sum of numbers that cannot be the sum of two abundants: %d\n", sumnot);
}
