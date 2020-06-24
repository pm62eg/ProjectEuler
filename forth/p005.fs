\ Smallest multiple
\ Problem 5

\ 2520 is the smallest number that can be divided by each
\ of the numbers from 1 to 10 without any remainder.

\ What is the smallest positive number that is evenly divisible
\ by all of the numbers from 1 to 20?

: e005-gcd ( a b -- n )
    begin
        dup             ( a b -- a b b )
        while           (     -- a b   )
        tuck            (     -- b a b )
        mod             (     -- b a%b )
    repeat
    drop ;              (     -- a     )

: e005-lcm ( a b -- n )
    over over *
    -rot e005-gcd / ;

: euler005
    1                         \ lcm of 1 and whatever
    21 2 do \ 2, 3, ..., 20
        i e005-lcm            \ lcm of 1 and 2, and 3, and 4, ...
    loop . ;
