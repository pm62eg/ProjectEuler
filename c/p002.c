/*
** sum even fibonacci numbers
*/

#include <stdio.h>

int main(void) {
    unsigned long long a = 1, b = 2;
    unsigned long long sum = 2;
    while (b <= 4000000) {
        unsigned long long next = a + b;
        a = b;
        b = next;
        if (b % 2 == 0) sum += b;
    }
    printf("sum of even fibonacci numbers is %llu.\n", sum);
}
