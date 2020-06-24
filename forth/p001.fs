\ Multiples of 3 and 5
\ Problem 1

\ If we list all the natural numbers below 10
\ that are multiples of 3 or 5, we get 3, 5, 6 and 9.
\ The sum of these multiples is 23.

\ Find the sum of all the multiples of 3 or 5 below 1000.

\ short circuit mod 3 (use original number as 'true') then mod 5
: e001-multiple3or5? dup 3 mod 0= if exit then 5 mod 0= ;

\ sum multiples of 3 or 5 up to, excluding, n
: e001-summ35 ( n -- sum ) 0 swap 1 do
                           i e001-multiple3or5? if i + then loop ;

: euler001 1000 e001-summ35 . ;
