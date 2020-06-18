(defun multiple-of-3-or-5p-version20200617 (n)
    "predicate for multiple of 3 or 5"
    (cond ((= 0 (rem n 3)) t)
          ((= 0 (rem n 5)) t)
          (t nil)))

(defun multiple-of-3-or-5p (n)
    "predicate for multiple of 3 or 5"
    (or (= 0 (rem n 3))
        (= 0 (rem n 5))))

(defun sum35-version20200617 (n)
    "sum all multiples of 3 or 5 up to n (including n)"
    (cond ((= n 0) 0)
          (t (+ (if (multiple-of-3-or-5p n) n 0) (sum35-version20200617 (- n 1))))))

(defun sum35-recursive (n)
    "sum all multiples of 3 or 5 up to n (including n)"
    (if (= n 0)
        0
        (+ (if (multiple-of-3-or-5p n) n 0) (sum35-recursive (1- n)))))

;; in the repl use
;; (sum35-recursive 999)

(defun sum35-iterative (n)
    "sum all multiples of 3 or 5 below n (excluding n)"
    (loop for i below n
          when (multiple-of-3-or-5p i) sum i))

;; in the repl use
;; (sum35-iterative 1000)

(defun predicate-sum-version20200617 (predicate n)
    "sum integers up to n (including n) that match the predicate"
    (cond ((= n 0) 0)                                 ; stop recursion
          (t (+
              (if (funcall predicate n) n 0)          ; add n or 0 and
              (predicate-sum-version20200617 predicate (- n 1))))))   ; the recursed sum to (n - 1)

(defun predicate-sum-recursive (predicate n)
    "sum integers up to n (including n) that match the predicate"
    (cond ((= n 0) 0)                                           ; stop recursion
          (t (+
              (if (funcall predicate n) n 0)                    ; add n or 0 and
              (predicate-sum-recursive predicate (- n 1))))))   ; the recursed sum to (n - 1)

;; in the repl use
;; (predicate-sum-recursive #'multiple-of-3-or-5p 999)

(defun predicate-sum-iterative (predicate n)
    "sum integers below n (excluding n) that match the predicate"
    (loop for i below n
          when (funcall predicate i) sum i))

;; in the repl use
;; (predicate-sum-iterativ #'multiple-of-3-or-5p 1000)
