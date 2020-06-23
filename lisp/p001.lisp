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
