/*
** Multiples of 3 and 5
*/

#include <stdio.h>

int main(void) {
    int sum = 0;
    for (int k = 3; k < 1000; k++) {
        if ((k % 3 == 0) || (k % 5 == 0)) sum += k;
    }
    printf("sum is %d.\n", sum);
}
