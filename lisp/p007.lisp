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
