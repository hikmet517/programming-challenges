(define (digits x)
  (let loop ((x (abs x))
             (lst '()))
    (if (= x 0)
        lst
        (loop (quotient x 10) (cons (remainder x 10) lst)))))

(define (main)
  (display (apply + (digits (expt 2 1000))))
  (newline))

;; 1366
(main)
