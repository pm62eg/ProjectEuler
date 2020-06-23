;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  euler 006  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Sum square difference
;;;
;;; The sum of the squares of the first ten natural numbers is,
;;; 1^2 + 2^2 + ... + 10^2 = 385
;;;
;;; The square of the sum of the first ten natural numbers is,
;;; (1 + 2 + ... + 10)^2 = 55^2 = 3025
;;;
;;; Hence the difference between the sum of the squares of the
;;; first ten natural numbers and the square of the sum is
;;; 3025 − 385 = 2640
;;;
;;; Find the difference between the sum of the squares of the
;;; first one hundred natural numbers and the square of the sum.

(defun e006-sum-of-squares (n)
    "sum of squares up to n, including n"
    (do ((sum2 0 (+ sum2 (* k k)))
         (k 1 (+ k 1)))
        ((> k n) sum2)))

(defun e006-square-of-sum (n)
    "square of sum up to n, including n"
    (do ((sum 0 (+ sum k))
         (k 1 (+ k 1)))
        ((> k n) (* sum sum))))

(defun e006-delta-sum2-2sum (n)
    "difference between sum of squares and square of sum up to, including, n"
    (- (e006-square-of-sum n) (e006-sum-of-squares n)))

(defun e006 ()
    (e006-delta-sum2-2sum 100))
