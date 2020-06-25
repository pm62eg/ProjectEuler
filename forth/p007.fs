\ 10001st prime
\ Problem 7

\ By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
\ we can see that the 6th prime is 13.

\ What is the 10 001st prime number?

\ no need to check for 2 or even numbers
: e007-prime?
    3 ( n factor ) begin 2dup dup * >= while
                   2dup mod 0= if 2drop false exit then 2 + repeat
    2drop true ;

: e007-nthoddprime
    1 ( n prev ) begin 2 + dup e007-prime? if swap 1 - swap then
                 over 0= until nip ;

\ the 1st prime is 2, otherwise calculate the n-1th odd prime
: e007-nthprime
    assert( dup 1 >= )
    dup 1 = if drop 2 exit then 1 - e007-nthoddprime ;

: euler007 10001 e007-nthprime . ;
