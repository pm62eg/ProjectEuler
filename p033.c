/*
** digit cancelling fractions
*/

#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void) {
    int numerator = 1;
    int denominator = 1;
    for (int a = 1; a < 10; a++) {
        for (int b = a; b < 10; b++) {
            if (b == a) continue;
            for (int c = 1; c < 10; c++) {
                if (c == a) continue;
                if (c == b) continue;
                int numac = a*10 + c;
                int numca = c*10 + a;
                int numbc = b*10 + c;
                int numcb = c*10 + b;
                if (b * numac == a * numbc) {
                    printf("%d%d/%d%d = %d/%d\n", a, c, b, c, a, b);
                    numerator *= a;
                    denominator *= b;
                }
                if (b * numca == a * numbc) {
                    printf("%d%d/%d%d = %d/%d\n", c, a, b, c, a, b);
                    numerator *= a;
                    denominator *= b;
                }
                if (b * numac == a * numcb) {
                    printf("%d%d/%d%d = %d/%d\n", a, c, c, b, a, b);
                    numerator *= a;
                    denominator *= b;
                }
                if (b * numca == a * numcb) {
                    printf("%d%d/%d%d = %d/%d\n", c, a, c, b, a, b);
                    numerator *= a;
                    denominator *= b;
                }
            }
        }
    }
    int dd = gcd(numerator, denominator);
    numerator /= dd;
    denominator /= dd;
    printf("product is %d/%d.\n", numerator, denominator);
}
