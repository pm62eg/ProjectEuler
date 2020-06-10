/*
** special pythagorean triplet
*/

#include <stdio.h>

int main(void) {
    int a, b, c;
    for (a = 1; a < 998; a++) {
        for (b = a + 1; b < 999; b++) {
            c = 1000 - b - a;
            if (a*a + b*b == c*c) printf("%d^2 + %d^2 = %d^2. Product is %d.\n",
                  a, b, c, a*b*c);
        }
    }
    printf("done\n");
}
