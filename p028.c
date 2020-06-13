/*
** number spiral diagonals
*/

#include <stdio.h>

int main(void) {
    int a[1001][1001];
    a[500][500] = 1;
    int n = 2, row = 500, col = 501;
    for (int addsize = 2; addsize <= 1000; addsize += 2) {
        //add right
        for (int k = 0; k < addsize; k++) a[row++][col] = n++;
        row--;
        col--;
        //add bottom
        for (int k = 0; k < addsize; k++) a[row][col--] = n++;
        row--;
        col++;
        //add left
        for (int k = 0; k < addsize; k++) a[row--][col] = n++;
        row++;
        col++;
        //add top
        for (int k = 0; k < addsize; k++) a[row][col++] = n++;
    }
    int diagsum = 0;
    for (int index = 0; index < 1001; index++) {
        diagsum += a[index][index];
        diagsum += a[1000-index][index];
    }
    diagsum -= a[500][500];
    printf("sum of diagonals is %d.\n", diagsum);
}
