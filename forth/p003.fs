\ Largest prime factor
\ Problem 3

\ The prime factors of 13195 are 5, 7, 13 and 29.

\ What is the largest prime factor of the number 600851475143 ?

\ extract factor once ( ... k n i -- ... i k+1 n/i i )
: e003-extract1factoronce -rot 2 pick rot 1 + -rot dup -rot / swap ;

\ move factor out of the number as many times as needed
: e003-extract1factor
    begin over over mod 0= while e003-extract1factoronce repeat ;

\ stack has factors and amount: ( f1 f2 ... fn n )
: e003-clearstack 0 do drop loop ;

\ decompose n into k factors (stacked, largest on top)
: e003-find&movefactors ( n -- f1 f2 ... fk k )
    0 swap 2 e003-extract1factor drop
    3 begin e003-extract1factor 2 + dup dup * 2 pick > until drop
    dup 1 = if drop else swap 1 + then ;

: euler003 600851475143 e003-find&movefactors
    ( f1 ... fn n )     over . e003-clearstack ;
