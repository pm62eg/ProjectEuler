;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  euler 009  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Special Pythagorean triplet
;;;
;;; A Pythagorean triplet is a set of three natural numbers, a < b < c,
;;; for which, a^2 + b^2 = c^2
;;;
;;; For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
;;;
;;; There exists exactly one Pythagorean triplet
;;; for which a + b + c = 1000.
;;; Find the product abc.

(defun e009 ()
    "solve project euler problem 9"
    (do ((a 1 (1+ a)))
        ((> a 1000) t)
        (do ((b (+ a 1) (1+ b))
             (c 0))
            ((> b 1000) t)
            (setf c (- 1000 (+ a b)))
            (if (= (+ (* a a) (* b b))(* c c))
                (print (list a b c (* a b c)))))))
