;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  euler 004  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Largest palindrome product
;;;
;;; A palindromic number reads the same both ways.
;;; The largest palindrome made from the product of two
;;; 2-digit numbers is 9009 = 91 × 99.
;;;
;;; Find the largest palindrome made from
;;; the product of two 3-digit numbers.

(defun e004-digits (n &optional (base 10))
    "return a list with the digits of n"
    (assert (and (integerp n) (>= n 1)
                 (integerp base) (>= base 2)))
    (loop with remainder
          while (> n 0)
          do (setf (values n remainder) (floor n base))
          collect remainder))

(defun e004-palindrome6p (n6)
    "determine if the 6-digit number n6 is a palindrome (in base 10)"
    (assert (and (integerp n6) (>= n6 100000) (<= n6 999999)))
    (let ((dd (e004-digits n6)))
         (and (= (nth 2 dd) (nth 3 dd))
              (= (nth 1 dd) (nth 4 dd))
              (= (nth 0 dd) (nth 5 dd)))))

(defun e004-largest-palindrome-in-square (siz)
    "find maximum palindrome product"
    (do* ((a siz)
          (b siz)
          (nextb)
          (sum (+ siz siz))
          (p (* a b) (* a b)))
         ((e004-palindrome6p p) p)
       ;; following half diagonals ensures (proof needed?)
       ;; the first palindrome product found is the largest
       (setf a (+ a 1))
       (setf b (- b 1))
       (if (> a siz) ; start next diagonal
           (progn (setf (values a nextb) (floor sum 2))
                  (setf b (+ a nextb -1))
                  (setf sum (- sum 1))))))

(defun e004 ()
    (e004-largest-palindrome-in-square 999))
