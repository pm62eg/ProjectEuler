\ Summation of primes

\ Problem 10

\ The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

\ Find the sum of all the primes below two million.

\ no need to check for 2 or even numbers
: e007-prime?
    3 ( n factor ) begin 2dup dup * >= while
                   2dup mod 0= if 2drop false exit then 2 + repeat
    2drop true ;

: e010-sumprimes
    2 swap 3 ( sum limit curr )
    begin 2dup >= while
        dup e007-prime? if rot over + rot rot then 2 +
    repeat drop drop ;

: euler010
    2000000 e010-sumprimes . ;
