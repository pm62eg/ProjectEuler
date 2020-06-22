/*
** factorial digit sum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BU {
    unsigned m, n;        // m = reserved; n = in use; m >= n
    unsigned char *data;
};

void BUprint(const char *msg, const struct BU *p) {
    printf("%s %u/%u ", msg, p->n, p->m);
    for (unsigned k = p->n; k; k--) {
        printf("%d", p->data[k - 1]);
    }
    puts("");
}

struct BU *BUnew(unsigned value) {
    struct BU *p = malloc(sizeof *p);
    if (p) {
        p->data = calloc(200, 1);
        if (p->data == NULL) {
            free(p);
            return NULL;
        }
        p->m = 200;
        p->n = 0;
        if (value == 0) p->data[p->n++] = 0;
        while (value > 0) {
            p->data[p->n++] = value % 10;
            value /= 10;
        }
    }
    return p;
}

void BUrelease(struct BU *p) {
    free(p->data);
    p->m = p->n = 0;
    free(p);
}

void BUadd(struct BU *restrict dst,
           const struct BU *restrict src1,
           const struct BU *restrict src2) {
    unsigned dstlen = src1->n;
    if (src2->n > dstlen) dstlen = src2->n;
    dstlen += 10;
    if (dstlen >= dst->m) {
        dst->m += 32;
        unsigned char *tmp = realloc(dst->data, dst->m);
        // assume it worked
        dst->data = tmp;
    }
    unsigned carry = 0;
    unsigned k = 0;
    while ((k < src1->n) && (k < src2->n)) {
        unsigned v = carry + src1->data[k] + src2->data[k];
        if (v >= 10) {
            carry = 1;
            v -= 10;
        } else {
            carry = 0;
        }
        dst->data[k++] = v;
    }
    while (k < src1->n) {
        unsigned v = carry + src1->data[k];
        if (v >= 10) {
            carry = 1;
            v -= 10;
        } else {
            carry = 0;
        }
        dst->data[k++] = v;
    }
    while (k < src2->n) {
        unsigned v = carry + src2->data[k];
        if (v >= 10) {
            carry = 1;
            v -= 10;
        } else {
            carry = 0;
        }
        dst->data[k++] = v;
    }
    if (carry) dst->data[k++] = carry;
    dst->n = k;
}

void BUmult(struct BU *restrict dst, const struct BU *restrict src, unsigned n) {
    if (n > 10) {
        struct BU *tmp1 = BUnew(0);
        struct BU *tmp2 = BUnew(0);
        BUmult(tmp1, src, 10);
        BUmult(tmp2, tmp1, n / 10);
        struct BU *tmp3 = BUnew(0);
        BUmult(tmp3, src, n % 10);
        BUadd(dst, tmp2, tmp3);
        BUrelease(tmp1);
        BUrelease(tmp2);
        BUrelease(tmp3);
    } else {
        if (n == 10) {
            dst->n = src->n + 1;
            dst->data[0] = 0;
            memcpy(dst->data + 1, src->data, src->n);
        } else {
            dst->n = 1;
            dst->data[0] = 0;
            struct BU *tmp = BUnew(0);
            struct BU *z = BUnew(0);
            for (unsigned k = 0; k < n; k++) {
                BUadd(dst, tmp, src);
                BUadd(tmp, dst, z);
            }
            BUrelease(z);
            BUrelease(tmp);
        }
    }
}

unsigned BUdigits(struct BU *p) {
    return p->n;
}

unsigned BUdigit(struct BU *p, unsigned n) {
    return p->data[n];
}

int main(void) {
    struct BU *v = BUnew(1);
    struct BU *z = BUnew(0);
    for (unsigned k = 1; k <= 100; k++) {
        struct BU *w = BUnew(0);
        BUmult(w, v, k);               // w = v * k
        BUadd(v, w, z);                // v = w + z = w
        BUrelease(w);
    }
    BUrelease(z);
    unsigned sum = 0;
    for (unsigned k = 0; k < BUdigits(v); k++) {
        sum += BUdigit(v, k);
    }
    BUrelease(v);
    printf("sum of digits: %u\n", sum);
}
