;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  euler 002  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Even Fibonacci numbers
;;;
;;; Each new term in the Fibonacci sequence is generated
;;; by adding the previous two terms. By starting with 1 and 2,
;;; the first 10 terms will be:
;;;
;;; 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
;;;
;;; By considering the terms in the Fibonacci sequence whose values
;;; do not exceed four million, find the sum of the even-valued terms.

;; very direct answer, `do` syntax is powerful

(defun e002-even-fib-sum (n)
    "sum even fibonacci numbers that do not exceed n"
    (do* ((sum 0)          ; no even numbers to care about before f-3
          (f-1 0 f-2)
          (f-2 1 f-next)
          (f-next 1 (+ f-1 f-2)))
        ((> f-next n) sum) ; return sum when next > n
        (if (evenp f-next) (incf sum f-next))))

(defun e002 ()
    (e002-even-fib-sum 4000000))
