\ Special Pythagorean triplet

\ Problem 9

\ A Pythagorean triplet is a set of three natural numbers,
\ a < b < c, for which,
\ a^2 + b^2 = c^2

\ For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

\ There exists exactly one Pythagorean triplet for which a + b + c = 1000.
\ Find the product abc.

: e009-prod3print 2dup * rot rot  1000 swap - swap - * . ;
: e009-pythagorean? dup * rot dup * rot dup * + = ;

: e009-3sum
    1000 1 do
        1000 i do
             i j 1000 i - j - e009-pythagorean? if i j e009-prod3print then
        loop
    loop ;

: euler009
    1000 e009-3sum ;
