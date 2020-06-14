/*
** pentagon numbers
*/

#include <stdio.h>
#include <stdlib.h>

int penta(int n) {
    int val = n * (3*n - 1) / 2;
    return val;
}

struct IntArray {
    int m, n; // reserved, used
    int *data;
};

int delta(const void *aa, const void *bb) {
    const int *key = aa;
    const int *elem = bb;
    return *key - *elem;
}

int ispenta(struct IntArray *b, int v) {
    if (bsearch(&v, b->data, b->n, sizeof v, delta)) return 1;
    return 0;
}

int main(void) {
    struct IntArray P[1];
    P->m = 30;
    P->data = malloc(P->m * sizeof *P->data);
    // assume it worked
    P->n = 0;
    P->data[P->n++] = 0;
    P->data[P->n++] = 1;
    P->data[P->n++] = 5;

    int D = 100000000;
    int row=2, col=1;
    while (row < 2200) {
        int Prow = P->data[row];
        int Pcol = P->data[col];
        while (Prow + Pcol > P->data[P->n - 1]) {
            if (P->n == P->m) {
                int *tmp = realloc(P->data, 2 * P->m * sizeof *tmp);
                // assume it worked
                P->data = tmp;
                P->m *= 2;
            }
            P->data[P->n] = penta(P->n);
            P->n++;
        }
        if (ispenta(P, Prow + Pcol)) {
            if (ispenta(P, Prow - Pcol)) {
                printf("double penta for P(%d) [%d] and P(%d) [%d]\n", row, Prow, col, Pcol);
                if (Prow - Pcol < D) D = Prow - Pcol;
            }
        }
        col++;
        if (col == row) { row++; col=1; }
    }
    printf("value of D is %d.\n", D);
}
