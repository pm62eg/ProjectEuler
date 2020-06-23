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
