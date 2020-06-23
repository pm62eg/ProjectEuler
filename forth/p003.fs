\  euler 003

\ Largest prime factor

\ The prime factors of 13195 are 5, 7, 13 and 29.

\ What is the largest prime factor of the number 600851475143 ?

\ move factor out of the number
: e003-movefactor ( k n f - f f ... k+n n/f/f... )
    begin
        over over
        mod 0= while          ( k n f - f k+1 n/f f  )
        -rot 2 pick           ( k n f - f k n f )
        rot 1 + -rot          ( f k n f - f k+1 n f )
        dup -rot              ( f k+1 n f - f k+1 f n f )
        / swap                ( f k+1 f n f - f k+1 n/f f )
    repeat
    drop ;

variable e003-currfactor
\ decompose n into k factors (stacked, largest on top)
: e003-movefactors          (         n - <k factors> k       )
    0 swap                  (         n - 0 n                 )
    2 e003-movefactor       (     0 n 2 - [2 2 ...] f n[/2^f] )
    3 e003-currfactor !
    begin
        e003-currfactor @
        e003-movefactor          ( ... k n i - .... i i newk newn )
        2 e003-currfactor @ +
        dup e003-currfactor !    ( ... - ... n f )
        dup * over               ( ... - ... n f*f n )
    > until                      ( ... - ... k n )
    dup 1 = if                   \ if remaining n is 1
        drop                     \     drop it
    else                         \ otherwise
        swap 1 +                 \     it is a factor
    then ;

: e003-clearstack       ( f1 f2 ... fk k - )
    0 do drop loop ;    \ remove k itself and k stack entries

: euler003
    600851475143        ( n -                )
    e003-movefactors    ( n - f1 f2 ... fk k ) \ k is count of factors
    over .              \ print largest factor
    e003-clearstack ;
