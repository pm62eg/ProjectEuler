/*
** lexicographic permutations
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    int f[10] = {1, 1, 2, 6, 24, 120, 720};
    f[7] = f[6] * 7;
    f[8] = f[7] * 8;
    f[9] = f[8] * 9;
    int target = 1000000;
    int r[10] = {0};
    r[9] = target/f[9]; target -= (r[9]*f[9]);
    r[8] = target/f[8]; target -= (r[8]*f[8]);
    r[7] = target/f[7]; target -= (r[7]*f[7]);
    r[6] = target/f[6]; target -= (r[6]*f[6]);
    r[5] = target/f[5]; target -= (r[5]*f[5]);
    r[4] = target/f[4]; target -= (r[4]*f[4]);
    r[3] = target/f[3]; target -= (r[3]*f[3]);
    r[2] = target/f[2]; target -= (r[2]*f[2]);
    r[1] = target/f[1]; target -= (r[1]*f[1]);
    char y[] = "0123456789xxxxxxxxxxxx";
    printf("the millionth permutation is: ");
    putchar(y[r[9]]); memmove(y+r[9], y+r[9]+1, 10);
    putchar(y[r[8]]); memmove(y+r[8], y+r[8]+1, 10);
    putchar(y[r[7]]); memmove(y+r[7], y+r[7]+1, 10);
    putchar(y[r[6]]); memmove(y+r[6], y+r[6]+1, 10);
    putchar(y[r[5]]); memmove(y+r[5], y+r[5]+1, 10);
    putchar(y[r[4]]); memmove(y+r[4], y+r[4]+1, 10);
    putchar(y[r[3]]); memmove(y+r[3], y+r[3]+1, 10);
    putchar(y[r[2]]); memmove(y+r[2], y+r[2]+1, 10);
    putchar(y[r[1]]); memmove(y+r[1], y+r[1]+1, 10);
    putchar(y[r[0]]); // memmove(y+r[0], y+r[0]+1, 10);
    puts("");
}
