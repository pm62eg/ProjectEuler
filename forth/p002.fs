\  euler 002

\ Even Fibonacci numbers

\ Each new term in the Fibonacci sequence is generated
\ by adding the previous two terms. By starting with 1 and 2,
\ the first 10 terms will be:

\ 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

\ By considering the terms in the Fibonacci sequence whose values
\ do not exceed four million, find the sum of the even-valued terms.

\ accumulate top 2 values into the 3rd, leave stack ready for next
: e002-nextfib     ( a b -- b a+b )
    swap over + ;

\ calculate next fib, update accum if needed
: e002-helper           (       accum a b -- ACCUM b a+b       )
    e002-nextfib        (       accum a b -- accum b a+b       )
    dup 2 mod if        (       accum a b -- accum b a+b flag  )
    else
        rot             (     accum b a+b -- b a+b accum       )
        over            (     b a+b accum -- a a+b accum a+b   )
        +               ( b a+b accum a+b -- b a+b accum[+a+b] )
        rot rot         (                 -- accum[+a+b] b a+b )
    then ;

\ evaluate fibonacci, update accum, and test if limit is reached
: e002-mainloop
    begin
        e002-helper     ( limit accum a b -- limit ACCUM A B       )
        3 pick          ( limit accum a b -- limit accum a b LIMIT )
        over <          (             ... -- limit accum a b FLAG  )
    until ;             (             ... -- limit accum a b       )

: euler002
    4000000 0 1 1           ( limit accum a b --                   )
    e002-mainloop           ( limit accum a b -- limit ACCUM A B   )
    drop drop swap drop . ; \ print accum, clear stack
