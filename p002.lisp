(defun even-fib-sum (n)
    "sum even fibonacci numbers that do not exceed n"
    (do* ((sum 0)      ; no even numbers to care about
          (f-1 0 f-2)
          (f-2 1 f-next)
          (f-next 1 (+ f-1 f-2)))
        ((> f-next n) sum) ; return sum when next > n
        (if (evenp f-next) (incf sum f-next))))

;; in the repl use
;; (even-fib-sum 4000000)
