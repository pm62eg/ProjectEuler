/*
** coded triangle numbers
*/

#include <stdio.h>
#include <string.h>

int tri(int v) {
    int n = 1, m = 1;
    for (;;) {
        if (v == n) return 1;
        if (v < n) return 0;
        m += 1;
        n += m;
    }
}

int main(void) {
    int count = 0;
    char word[100];
    FILE *h = fopen("p042_words.txt", "r");
    for (;;) {
        fgetc(h); // ignore quotes
        int ch;
        char *p = word;
        while ((ch = fgetc(h)) != '"') *p++ = ch;
        *p = 0;
        int val = 0;
        for (unsigned k = 0; k < strlen(word); k++) val += word[k] - 'A' + 1;
        if (tri(val)) count++;
        if (fgetc(h) == EOF) break; // ignore comma or stop
    }
    fclose(h);
    printf("there are %d triangle words.\n", count);
}
