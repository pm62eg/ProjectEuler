/*
** number letter counts
*/

#include <stdio.h>

int nletters(int n) {
    //special cases
         if (n == 1000) return 11; // one thousand
    else if (n == 0) return 0; // only happens when recursing from 300, 400, ...
    else if (n % 100 == 0) return nletters(n / 100) + 7;
    else if (n > 100) return nletters(n / 100) + 10 + nletters(n % 100);
    else if (n == 1) return 3;  // one
    else if (n == 2) return 3;  // two
    else if (n == 3) return 5;  // three
    else if (n == 4) return 4;  // four
    else if (n == 5) return 4;  // five
    else if (n == 6) return 3;  // six
    else if (n == 7) return 5;  // seven
    else if (n == 8) return 5;  // eight
    else if (n == 9) return 4;  // nine
    else if (n == 10) return 3; // ten
    else if (n == 11) return 6; // eleven
    else if (n == 12) return 6; // twelve
    else if (n == 13) return 8; // thirteen
    else if (n == 14) return 8; // fourteen
    else if (n == 15) return 7; // fifteen
    else if (n == 16) return 7; // sixteen
    else if (n == 17) return 9; // seventeen
    else if (n == 18) return 8; // eighteen
    else if (n == 19) return 8; // nineteen
    else if (n >= 90) return 6 + nletters(n % 10); // ninety
    else if (n >= 80) return 6 + nletters(n % 10); // eighty
    else if (n >= 70) return 7 + nletters(n % 10); // seventy
    else if (n >= 60) return 5 + nletters(n % 10); // sixty
    else if (n >= 50) return 5 + nletters(n % 10); // fifty
    else if (n >= 40) return 5 + nletters(n % 10); // forty
    else if (n >= 30) return 6 + nletters(n % 10); // thirty
    else if (n >= 20) return 6 + nletters(n % 10); // twenty
    else fprintf(stderr, "ERROR: something's missing!\n");
    return 0;
}

int main(void) {
    int count = 0;
    for (int n = 1; n <= 1000; n++) {
        count += nletters(n);
    }
    printf("%d letters used.\n", count);
}
