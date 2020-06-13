/*
** pandigital products
*/

/*
** a * b = c, where a<b and #a + #b + #c = 9
** implies #a = 2, #b = 3, #c = 4
*/

#include <stdio.h>

int main(void) {
    int sum = 0;
    for (int a = 1; a < 10; a++) {
        for (int b = 1; b < 10; b++) {
            if (b == a) continue;
            for (int c = 1; c < 10; c++) {
                if (c == a) continue;
                if (c == b) continue;
                for (int d = 1; d < 10; d++) {
                    if (d == a) continue;
                    if (d == b) continue;
                    if (d == c) continue;
                    for (int e = 1; e < 10; e++) {
                        if (e == a) continue;
                        if (e == b) continue;
                        if (e == c) continue;
                        if (e == d) continue;
                        for (int f = 1; f < 10; f++) {
                            if (f == a) continue;
                            if (f == b) continue;
                            if (f == c) continue;
                            if (f == d) continue;
                            if (f == e) continue;
                            for (int g = 1; g < 10; g++) {
                                if (g == a) continue;
                                if (g == b) continue;
                                if (g == c) continue;
                                if (g == d) continue;
                                if (g == e) continue;
                                if (g == f) continue;
                                for (int h = 1; h < 10; h++) {
                                    if (h == a) continue;
                                    if (h == b) continue;
                                    if (h == c) continue;
                                    if (h == d) continue;
                                    if (h == e) continue;
                                    if (h == f) continue;
                                    if (h == g) continue;
                                    for (int i = 1; i < 10; i++) {
                                        if (i == a) continue;
                                        if (i == b) continue;
                                        if (i == c) continue;
                                        if (i == d) continue;
                                        if (i == e) continue;
                                        if (i == f) continue;
                                        if (i == g) continue;
                                        if (i == h) continue;
                                        int multiplicand1 = e*10+f;
                                        int multiplier1 = g*100+h*10+i;
                                        int product1 = a*1000+b*100+c*10+d;
                                        int multiplicand2 = e;
                                        int multiplier2 = f*1000+g*100+h*10+i;
                                        int product2 = a*1000+b*100+c*10+d;
                                        if (multiplicand1 * multiplier1 == product1) {
                                            sum += product1;
                                            e = f = g = h = i = 99; // no more check for this product
                                            break;
                                        }
                                        if (multiplicand2 * multiplier2 == product2) {
                                            sum += product2;
                                            e = f = g = h = i = 99; // no more check for this product
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("sum of pandigital products is %d.\n", sum);
}
