/*
** sum square difference
*/

#include <stdio.h>

#define LIMIT 100

int main(void) {
    unsigned long long sumsquares = 0;
    unsigned long long squaresum = 0;
    for (int n = 0; n <= LIMIT; n++) {
        squaresum += n;
        sumsquares += n*n;
    }
    squaresum *= squaresum;
    printf("difference is is %llu.\n", squaresum - sumsquares);
}
