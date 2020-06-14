/*
** integer right triangles
*/

#include <stdio.h>

int root(int v2) {
    static int v[1000];
    if (v[1] == 0) for (int k = 1; k < 1000; k++) v[k] = k*k;
    for (int k = 0; k < 1000; k++) if (v[k] == v2) return k;
    return 0;
}

int main(void) {
    int maxp = 0;
    int p[1001] = {0};
    for (int a = 1; a < 333; a++) {
        for (int b = a+1; b < 1000; b++) {
            int c = root(a*a + b*b);
            if (c && (a+b+c <= 1000)) p[a+b+c] += 1;
        }
    }
    for (int k = 0; k <= 1000; k++) if (p[k] > p[maxp]) maxp = k;
    printf("perimeter %d has maximum solutions.\n", maxp);
}
