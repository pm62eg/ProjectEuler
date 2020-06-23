\ euler 001

\ Multiples of 3 and 5

\ If we list all the natural numbers below 10
\ that are multiples of 3 or 5, we get 3, 5, 6 and 9.
\ The sum of these multiples is 23.

\ Find the sum of all the multiples of 3 or 5 below 1000.

\ determine if n is a multiple of 3 or 5
: e001-m35?      (     n -- flag )
    dup          (   n n --      )
    3 mod        ( n n%3 --      )
    0 = if       (     n --      )
        drop -1  (       -- flag ) \ it is a multiple of 3
    else         (     n --      )
        5 mod    (   n%5 --      )
        0 = if
            -1   (       -- flag ) \ it is a multiple of 5
        else
            0    (       -- flag ) \ not a multiple of either 3 or 5
        then
    then ;

\ sum multiples of 3 or 5 up to, excluding, n
: e001-summ35           (     n -- sum )
    0 swap              ( sum n --     ) \ 0 to start sum
    1 do                                \ loop from 1 to n
        i e001-m35? if  (   sum --     )
            i           ( sum i --     )
            +           (   sum --     )
        then            (   sum --     )
    loop ;              (       -- sum )

: euler001
    1000 e001-summ35 . ;
