/*
** coded triangle numbers
*/

#include <stdio.h>
#include <stdlib.h>

int makenext(char *a, int n) {
    //1. find the largest k for which a[k] < a[k+1]
    //   if it does not exist return 1
    int k = n - 1;
    while (--k) {
        if (a[k] < a[k+1]) break;
    }
    if (a[k] >= a[k+1]) return 1;

    //2. find the largest i such that i>k and a[k]<a[i]
    int i = n - 1;
    while (i > k) {
        if (a[k] < a[i]) break;
        i--;
    }
    if (a[k] >= a[i]) /*nope*/ return 2;

    //3. swap a[k] and a[i]
    { char tmp = a[k]; a[k] = a[i]; a[i] = tmp; }

    //4. reverse from a[k+1] to a[n]
    while (k+1 < n) {
        char tmp = a[k+1];
        a[k+1] = a[n-1];
        a[n-1] = tmp;
        n--;
        k++;
    }

    return 0;
}

int main(void) {
    unsigned long long sum = 0;
    char number[11] = "0123456789";
    for (;;) {
        if (makenext(number, 10)) break;
        int d8 = 100*(number[7]-'0') + 10*(number[8]-'0') + (number[9]-'0');
        if (d8 % 17) continue;
        int d7 = 100*(number[6]-'0') + 10*(number[7]-'0') + (number[8]-'0');
        if (d7 % 13) continue;
        int d6 = 100*(number[5]-'0') + 10*(number[6]-'0') + (number[7]-'0');
        if (d6 % 11) continue;
        int d5 = 100*(number[4]-'0') + 10*(number[5]-'0') + (number[6]-'0');
        if (d5 % 7) continue;
        int d4 = 100*(number[3]-'0') + 10*(number[4]-'0') + (number[5]-'0');
        if (d4 % 5) continue;
        int d3 = 100*(number[2]-'0') + 10*(number[3]-'0') + (number[4]-'0');
        if (d3 % 3) continue;
        int d2 = 100*(number[1]-'0') + 10*(number[2]-'0') + (number[3]-'0');
        if (d2 % 2) continue;
        printf("%s is good!\n", number);
        unsigned long long xx = strtoull(number, 0, 10);
        sum += xx;
    }
    printf("sum is %llu.\n", sum);
}
