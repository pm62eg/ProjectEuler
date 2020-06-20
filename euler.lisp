;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  euler 001  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Multiples of 3 and 5
;;;
;;; If we list all the natural numbers below 10
;;; that are multiples of 3 or 5, we get 3, 5, 6 and 9.
;;; The sum of these multiples is 23.
;;;
;;; Find the sum of all the multiples of 3 or 5 below 1000.

(defun e001-v1-multiple-of-3-or-5p (n)
    "predicate for multiple of 3 or 5"
    (cond ((= 0 (rem n 3)) t)
          ((= 0 (rem n 5)) t)
          (t nil)))

(defun e001-multiple-of-3-or-5p (n)
    "predicate for multiple of 3 or 5"
    (or (= 0 (rem n 3))
        (= 0 (rem n 5))))

(defun e001-v1-sum35 (n)
    "recursively sum all multiples of 3 or 5 up to n (including n)"
    (cond ((= n 0) 0)
          (t (+ (if (e001-multiple-of-3-or-5p n) n 0) ; add 0 or n
                (e001-v1-sum35 (- n 1))))))           ; to the recursion

(defun e001-v2-sum35 (n)
    "recursively sum all multiples of 3 or 5 up to n (including n)"
    (if (= n 0)
        0
        (+ (if (e001-multiple-of-3-or-5p n) n 0) ; add 0 or n
           (e001-v2-sum35 (1- n)))))             ; to the recursion

(defun e001-sum35-iterative (n)
    "sum all multiples of 3 or 5 below n (excluding n)"
    (loop for i below n
          when (e001-multiple-of-3-or-5p i) sum i))

;;; what if I want to use a different predicate?
;;; Pass the predicate to the function, as a first-class value

(defun e001-predicate-sum-recursive (predicate n)
    "recursively sum integers up to n (including n) that match the predicate"
    (cond ((= n 0) 0)                                                ; stop recursion
          (t (+
              (if (funcall predicate n) n 0)                         ; add n or 0 and
              (e001-predicate-sum-recursive predicate (- n 1))))))   ; the recursed sum to (n - 1)

(defun e001-predicate-sum-iterative (predicate n)
    "sum integers below n (excluding n) that match the predicate"
    (loop for i below n
          when (funcall predicate i) sum i))

(defun e001-sum-arithmetic-series (delta lastvalue)
    "sum of 0, d, 2*d, 3*d, ... k*d <= lastvalue < (k+1)*d"
    (let* ((nterms (floor lastvalue delta))
           (lastterm (* nterms delta)))
        (/ (* (1+ nterms) lastterm) 2)))

(defun e001 ()
    (+ (e001-sum-arithmetic-series 3 999)
       (e001-sum-arithmetic-series 5 999)
    (- (e001-sum-arithmetic-series 15 999))))

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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  euler 003  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Largest prime factor
;;;
;;; The prime factors of 13195 are 5, 7, 13 and 29.
;;;
;;; What is the largest prime factor of the number 600851475143 ?

;; writing a function to list all factors of n instead

(defun e003-v1-factors (n)
    "return a list with prime factors of n"
    (let ((result))
        (loop while (zerop (rem n 2))       ; do 2
              do (loop while (zerop (rem n 2))
                       do (setf n (/ n 2))
                       do (push 2 result)))
        (loop for i from 3 by 2             ; do 3, 5, 7, 9, ...
              while (>= n (* i i))          ; until sqrt of what's left of n
              do (loop while (zerop (rem n i))
                       do (setf n (/ n i))
                       do (push i result)))
        (if (= n 1)
            result
            (cons n result))))              ; if n is not 1 it is also a factor

;; use `flet` to refactor inner loop
;; rather than `rem` and `/` in two instruction use `floor`

(defun e003-factors (n)
    "return a list with prime factors of n"
    (let ((result))
        (flet ((transfer-factor (fac)
                "transfer available fac from number `n` to list `result`"
                (loop with quotient and remainder
                      do (setf (values quotient remainder)
                               (floor n fac))
                      while (zerop remainder)
                      do (setf n quotient)
                      do (push fac result))))
            (transfer-factor 2)             ; do 2
            (loop for i from 3 by 2         ; do 3, 5, 7, 9, ...
                  while (>= n (* i i))      ; until sqrt of what's left of n
                  do (transfer-factor i)))
        (when (> n 1) (push n result))      ; n may still be a factor
        result))                            ; return complete list

(defun e003 ()
    (first (e003-factors 600851475143)))

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
         (and (= (nth 0 dd) (nth 5 dd))
              (= (nth 1 dd) (nth 4 dd))
              (= (nth 2 dd) (nth 3 dd)))))

(defun e004 ()
    "find maximum palindrome product"
    (do* ((a 999)
          (b 999)
          (nextb)
          (sum (+ 999 999))
          (p (* a b) (* a b)))
         ((e004-palindrome6p p) p)
       ;; following half diagonals ensures (proof needed?)
       ;; the first palindrome product found is the largest
       (setf a (+ a 1))
       (setf b (- b 1))
       (if (> a 999) (progn (setf (values a nextb) (floor sum 2))
                            (setf nextb (- 1 nextb))
                            (setf b (- a nextb))
                            (setf sum (- sum 1))))))
