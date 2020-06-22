/*
** names scores
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct P22 {
    char name[50];
    int value;
};

int cmp(const void *aa, const void *bb) {
    const struct P22 *a = aa;
    const struct P22 *b = bb;
    return strcmp(a->name, b->name);
}

int main(void) {
    struct P22 p[6000] = {0};
    int np = 0;
    FILE *h = fopen("../p022_names.txt", "r"); // assume it worked
    for (;;) {
        int ch;
        char *t = p[np].name;
        fgetc(h); // read and discard quote
        while ((ch = fgetc(h)) != '"') {
            *t++ = ch;
            p[np].value += ch - 'A' + 1; //assume sequential, contiguous letters
        }
        np++;
        ch = fgetc(h); // read and discard [optional] comma
        if (ch != ',') break;
    }
    fclose(h);                              // assume it worked
    qsort(p, np, sizeof *p, cmp);
    int accum = 0;
    for (int k = 0; k < np; k++) {
        int score = p[k].value * (k + 1);
        accum += score;
    }
    printf("sum of scores is %d\n", accum);
}
