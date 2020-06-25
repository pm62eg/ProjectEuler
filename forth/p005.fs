\ Smallest multiple
\ Problem 5

\ 2520 is the smallest number that can be divided by each
\ of the numbers from 1 to 10 without any remainder.

\ What is the smallest positive number that is evenly divisible
\ by all of the numbers from 1 to 20?

: e005-gcd begin dup while tuck mod repeat drop ;
: e005-lcm over over * -rot e005-gcd / ;
: euler005 1 ( result ) 21 2 do i e005-lcm loop . ;
