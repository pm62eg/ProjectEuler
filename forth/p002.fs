\ Even Fibonacci numbers
\ Problem 2

\ Each new term in the Fibonacci sequence is generated
\ by adding the previous two terms. By starting with 1 and 2,
\ the first 10 terms will be:

\ 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

\ By considering the terms in the Fibonacci sequence whose values
\ do not exceed four million, find the sum of the even-valued terms.

: e002-even? 2 mod 0= ;
: e002-nextfib ( a b -- b a+b ) tuck + ;
: e002-addifeven dup e002-even? if      \ if even
    ( sum a b )  rot over + -rot then ; \ add to sum

: e002-nextaddifeven e002-nextfib e002-addifeven ;
: e002-sumeven begin e002-nextaddifeven 3 pick over <= until ;

: e002-sumevenfibs ( n -- sum ) 0 1 1 e002-sumeven 2drop nip ;
: euler002 4000000 e002-sumevenfibs . ;
