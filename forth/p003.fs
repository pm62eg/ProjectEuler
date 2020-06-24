\ Largest prime factor
\ Problem 3

\ The prime factors of 13195 are 5, 7, 13 and 29.

\ What is the largest prime factor of the number 600851475143 ?

\ move factor out of the number
: e003-movefactor ( k n f -- f f ... k+n n/f/f... )
    begin
        over over
        mod 0= while          ( k n f -- f k+1 n/f f  )
        -rot 2 pick           ( k n f -- f k n f )
        rot 1 + -rot          ( f k n f -- f k+1 n f )
        dup -rot              ( f k+1 n f -- f k+1 f n f )
        / swap                ( f k+1 f n f -- f k+1 n/f f )
    repeat
    drop ;

\ decompose n into k factors (stacked, largest on top)
: e003-movefactors          (         n -- <k factors> k       )
    0 swap                  (         n -- 0 n                 )
    2 e003-movefactor       (     0 n 2 -- [2 2 ...] f n[/2^f] )
    3 locals| cf |          \ currentfactor: 3, 5, 7, 9, 11, ...
    begin
        cf e003-movefactor       ( ... k n i -- .... i i newk newn )
        2 cf +
        dup to cf                ( ... -- ... n f )
        dup * over               ( ... -- ... n f*f n )
    > until                      ( ... -- ... k n )
    dup 1 = if                   \ if remaining n is 1
        drop                     \     drop it
    else                         \ otherwise
        swap 1 +                 \     it is a factor
    then ;

\ stack has factors and amount: ( f1 f2 ... fn n )
: e003-clearstack 0 do drop loop ;

: euler003 600851475143 e003-movefactors
    ( f1 ... fn n )     over . e003-clearstack ;
