;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  euler 005  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Smallest multiple
;;;
;;; 2520 is the smallest number that can be divided by each of the
;;; numbers from 1 to 10 without any remainder.
;;;
;;; What is the smallest positive number that is evenly divisible
;;; by all of the numbers from 1 to 20?

(defun e005-gcd (a b)
    "greatest common divisor of a and b"
    (assert (and (integerp a) (>= a 0)
                 (integerp b) (>= b 0)))
    (if (> b a)
        (e005-gcd b a))              ; tail call
        (if (= b 0)
            a
            (e005-gcd b (mod a b)))) ; tail call

(defun e005-lcm (a b)
    "least common multiple of a b"
    (assert (and (integerp a) (>= a 0)
                 (integerp b) (>= b 0)))
    (/ (* a b) (e005-gcd a b)))

(defun e005-lcm-series (n)
    "compute the lcm of all integers up to n"
    (do* ((k 1 (+ k 1))
          (curr 1 (e005-lcm curr k)))
         ((= k n) curr)
         (print (list k curr))))

(defun e005 ()
    (e005-lcm-series 20))
