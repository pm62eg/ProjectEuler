\ Largest palindrome product
\ Problem 4

\ A palindromic number reads the same both ways.
\ The largest palindrome made from the product of two 2-digit numbers
\ is 9009 = 91 × 99.

\ Find the largest palindrome made from the product of two 3-digit numbers.

: e004-digit ( n d -- n[d] )
    begin
        dup 0 > while
        swap 10 / swap 1 -
    repeat
    drop 10 mod ;

: e004-palindrome6? ( 6-digit-n -- flag )
    dup 0 e004-digit       ( n -- n d0 )
    over 5 e004-digit      ( n d0 -- n d0 d5 )
    = if                ( n -- )
        dup 1 e004-digit
        over 4 e004-digit
        = if
            dup 2 e004-digit
            over 3 e004-digit
            = if
            else
                0 *
            then
        else
            0 *
        then
    else
        0 *             \ not palindrome
    then ;

: euler004
    900 999 do
        900 i do
            i j *
            dup e004-palindrome6?
            if . else drop then
        -loop
    -loop ;
