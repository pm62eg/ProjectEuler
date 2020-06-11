/*
** counting sundays
*/

#include <stdio.h>
#include <time.h>

int main(void) {
    int suncount = 0;
    for (int y = 1901; y <= 2000; y++) {
        for (int m = 1; m <= 12; m++) {
            struct tm tmp;
            tmp.tm_year = y - 1900;
            tmp.tm_mon = m - 1;
            tmp.tm_mday = 1;
            tmp.tm_hour = 12;
            tmp.tm_min = 0;
            tmp.tm_isdst = -1;
            mktime(&tmp);
            if (tmp.tm_wday == 0) suncount++;
        }
    }
    printf("sundays: %d\n", suncount);
}
