/*
** pandigital multiples
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned pan(int n, int *a, int len) {
    char res[200] = {0};
    while (len--) {
        unsigned tmp = n * *a++;
        char xtmp[60];
        sprintf(xtmp, "%u", tmp);
        strcat(res, xtmp);
        if (strlen(res) >= 10) return 0;
        if (strchr(res, '0')) return 0;
    }
    if (strlen(res) != 9) return 0;
    if (strchr(res, '0')) return 0;
    if (!strchr(res, '1')) return 0;
    if (!strchr(res, '2')) return 0;
    if (!strchr(res, '3')) return 0;
    if (!strchr(res, '4')) return 0;
    if (!strchr(res, '5')) return 0;
    if (!strchr(res, '6')) return 0;
    if (!strchr(res, '7')) return 0;
    if (!strchr(res, '8')) return 0;
    if (!strchr(res, '9')) return 0;
    unsigned val = strtoul(res, 0, 10);
    return val;
}

int main(void) {
    int X[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned maxpan = 0;
    for (int n = 1; n < 10000; n++) {
        for (int len = 2; len <= 9; len++) {
            unsigned x = pan(n, X, len);
            if (x > maxpan) maxpan = x;
        }
    }
    printf("largest pandigital is %d.\n", maxpan);
}
