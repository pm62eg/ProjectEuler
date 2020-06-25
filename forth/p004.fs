\ Largest palindrome product
\ Problem 4

\ A palindromic number reads the same both ways.
\ The largest palindrome made from the product of two 2-digit numbers
\ is 9009 = 91 × 99.

\ Find the largest palindrome made from the product of two 3-digit numbers.

: e004-nthdigit ( n d -- n[d] )
    begin dup 0 > while swap 10 / swap 1 - repeat drop 10 mod ;

: e004-palindrome6? ( 6-digit-n -- flag )
    assert( dup 100000 >= )
    assert( dup 999999 <= )
    dup 0 e004-nthdigit over 5 e004-nthdigit <> if drop false exit then
    dup 1 e004-nthdigit over 4 e004-nthdigit <> if drop false exit then
    dup 2 e004-nthdigit swap 3 e004-nthdigit = ;

: euler004
    900 999 do 900 i do
        i j * dup e004-palindrome6? if . else drop then
    -1 +loop -1 +loop ;
