\  euler 002

\ Even Fibonacci numbers

\ Each new term in the Fibonacci sequence is generated
\ by adding the previous two terms. By starting with 1 and 2,
\ the first 10 terms will be:

\ 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

\ By considering the terms in the Fibonacci sequence whose values
\ do not exceed four million, find the sum of the even-valued terms.

\ calculate next fib, update accum if needed
: e002-nextaddeven ( accum a b -- accum b a+b )
    tuck +                     \ next fibonacci
    dup 2 mod 0= if            \ if even
        rot over + -rot then ; \ add to accum

\ evaluate fibonacci, update accum, and test if limit is reached
: e002-mainloop ( limit accum a b -- limit accum a b )
    begin e002-nextaddeven      \ calculate [and add] next fibonacci
          3 pick over < until ; \ check for limit

: euler002
    4000000 0 1 1 e002-mainloop
    drop drop . drop ;  \ print accum, clear stack
