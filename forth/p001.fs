\ euler 001

\ Multiples of 3 and 5

\ If we list all the natural numbers below 10
\ that are multiples of 3 or 5, we get 3, 5, 6 and 9.
\ The sum of these multiples is 23.

\ Find the sum of all the multiples of 3 or 5 below 1000.

\ determine if n is a multiple of 3 or 5
: e001-m35? ( n -- flag )
    dup
    3 mod 0= if exit then \ leave n (true) in the stack
    5 mod 0= ;            \ leave test in the stack

\ sum multiples of 3 or 5 up to, excluding, n
: e001-summ35 ( n -- sum )
    0 swap 1 do             \ loop from 1 to n, add to TOS
        i e001-m35? if
            i + then        \ add i when true
    loop ;

: euler001
    1000 e001-summ35 . ;
