/*
** champernowne's constant
*/

#include <stdio.h>

int main(void) {
    char champ[1000100] = ".";
    char *p = champ + 1;
    int n = 0;
    do {
        int pp = sprintf(p, "%d", ++n);
        p += pp;
    } while (p - champ <= 1000001);
    printf("last number added to constant was %d\n", n);
    int exp = champ[1]-'0';
    exp *= champ[10]-'0';
    exp *= champ[100]-'0';
    exp *= champ[1000]-'0';
    exp *= champ[10000]-'0';
    exp *= champ[100000]-'0';
    exp *= champ[1000000]-'0';
    printf("value of expression is %d.\n", exp);
}
