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

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  euler 007  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; 10001st prime
;;;
;;; By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
;;; we can see that the 6th prime is 13.
;;;
;;; What is the 10 001st prime number?

(defun e007-primep (n arr)
    "based on array of primes, determine if n is prime"
    (do ((k 0 (1+ k)))
        ((> k (sqrt n)) t)
        (if (= (mod n (aref arr k)) 0) (return nil))))

(defun e007-fill-prime-array (pa nprimes)
    "fills array with nprimes primes"
    (let* ((last-index (length pa))
           (last-value (aref pa (- last-index 1))))
          (if (> nprimes last-index)
              (loop initially (adjust-array pa nprimes :initial-element nil)
                    for candidate from (+ last-value 2) by 2
                    do (if (e007-primep candidate pa)
                        (block innerif
                            (setf (aref pa last-index) candidate)
                            (incf last-index)))
                    until (= last-index nprimes)))))

(defun e007-primes (n)
    "fill an array with n primes, return the last prime"
    (let ((a (make-array 4 :adjustable t :initial-contents '(2 3 5 7))))
         (e007-fill-prime-array a n)
         (aref a (- n 1))))

(defun e007 ()
    (e007-primes 10001))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;  euler 008  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Largest product in a series
;;;
;;; The four adjacent digits in the 1000-digit number that have the
;;; greatest product are 9 × 9 × 8 × 9 = 5832.
;;;
;;; 73167176531330624919225119674426574742355349194934
;;; 96983520312774506326239578318016984801869478851843
;;; 85861560789112949495459501737958331952853208805511
;;; 12540698747158523863050715693290963295227443043557
;;; 66896648950445244523161731856403098711121722383113
;;; 62229893423380308135336276614282806444486645238749
;;; 30358907296290491560440772390713810515859307960866
;;; 70172427121883998797908792274921901699720888093776
;;; 65727333001053367881220235421809751254540594752243
;;; 52584907711670556013604839586446706324415722155397
;;; 53697817977846174064955149290862569321978468622482
;;; 83972241375657056057490261407972968652414535100474
;;; 82166370484403199890008895243450658541227588666881
;;; 16427171479924442928230863465674813919123162824586
;;; 17866458359124566529476545682848912883142607690042
;;; 24219022671055626321111109370544217506941658960408
;;; 07198403850962455444362981230987879927244284909188
;;; 84580156166097919133875499200524063689912560717606
;;; 05886116467109405077541002256983155200055935729725
;;; 71636269561882670428252483600823257530420752963450
;;;
;;; Find the thirteen adjacent digits in the 1000-digit number
;;; that have the greatest product.
;;; What is the value of this product?

(defun e008-digit-value (ch)
    "character digit as integer (#\0 as 0, #\1 as 1, ...)"
    (- (char-code ch) (char-code #\0)))

(defun e008-multseq (data index terms)
    "multiply `terms` digits from data starting at index"
    (do ((res 1)
         (ndx index (1+ ndx)))
        ((or (zerop res) (= ndx (+ index terms))) res)
        (setf res (* res (e008-digit-value (aref data ndx))))))

(defun e008-max-multseq (data len)
    (loop for k from 0 to (- (length data) len)
          maximize (e008-multseq data k len)))

(defun e008-check-off-by-one-error ()
    (let ((data "1111112"))
         (print (list data (e008-max-multseq data 3))))
    (let ((data "1111123"))
         (print (list data (e008-max-multseq data 3))))
    t)

(defun e008 ()
    (let ((data (concatenate 'string "73167176531330624919225119674426574742355349194934"
                                     "96983520312774506326239578318016984801869478851843"
                                     "85861560789112949495459501737958331952853208805511"
                                     "12540698747158523863050715693290963295227443043557"
                                     "66896648950445244523161731856403098711121722383113"
                                     "62229893423380308135336276614282806444486645238749"
                                     "30358907296290491560440772390713810515859307960866"
                                     "70172427121883998797908792274921901699720888093776"
                                     "65727333001053367881220235421809751254540594752243"
                                     "52584907711670556013604839586446706324415722155397"
                                     "53697817977846174064955149290862569321978468622482"
                                     "83972241375657056057490261407972968652414535100474"
                                     "82166370484403199890008895243450658541227588666881"
                                     "16427171479924442928230863465674813919123162824586"
                                     "17866458359124566529476545682848912883142607690042"
                                     "24219022671055626321111109370544217506941658960408"
                                     "07198403850962455444362981230987879927244284909188"
                                     "84580156166097919133875499200524063689912560717606"
                                     "05886116467109405077541002256983155200055935729725"
                                     "71636269561882670428252483600823257530420752963450")))
         (e008-max-multseq data 13)))
