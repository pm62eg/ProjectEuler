\ euler 007

\ 10001st prime

\ By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
\ we can see that the 6th prime is 13.

\ What is the 10 001st prime number?

: e007-prime? ( n -- f )
         dup 2 = if      drop true
    else dup 2 mod 0= if drop false
    else 3
        begin 2dup dup * >=
        while 2dup mod 0=
              if       2drop false exit
              then
              2 +
        repeat
        2drop true
    then then ;

: e007-nthprime               ( n -- p )
    dup 1 = if
        drop 2                \ 2 is the 1st prime
    else
       1 -                    \ 2 is already counted
       1 begin                ( n prev-candidate -- n[-1] curr-candidate )
           2 +                \ update curr-candidate
           dup e007-prime? if
               swap 1 - swap  \ if prime update n
           then
       over 0= until
    then ;

: euler007
    10001 e007-nthprime . drop ;
