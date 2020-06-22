/*
** coin sums
*/

#include <stdio.h>

int waystosum(int val, int *v, int n) {
    if (val == 0) return 1;
    if (n == 0) return 0;
    int ret = 0;
    for (int k = 0; k <= val / v[0]; k++) {
        ret += waystosum(val - k * v[0], v + 1, n - 1);
    }
    return ret;
}

int main(void) {
    int p[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int count = waystosum(200, p, 8);
    printf("200p can be made in %d different ways.\n", count);
}
