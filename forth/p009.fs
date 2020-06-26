\ Special Pythagorean triplet

\ Problem 9

\ A Pythagorean triplet is a set of three natural numbers,
\ a < b < c, for which,
\ a^2 + b^2 = c^2

\ For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

\ There exists exactly one Pythagorean triplet for which a + b + c = 1000.
\ Find the product abc.

: e009-prod3print 2dup * rot rot + rot swap - * . ;
: e009-pythagorean? dup * rot dup * rot dup * + = ;

: e009-3sum
    dup 1 do
        dup i do
             dup i - j - i j rot e009-pythagorean? if dup i j e009-prod3print then
        loop
    loop ;

: euler009
    1000 e009-3sum ;
