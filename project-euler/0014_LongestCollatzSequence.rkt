#lang racket
(define (process-num n)
  (if (= (modulo n 2) 0)
      (quotient n 2)
      (+ 1 (* 3 n))))

(define (collatz-list n)
  (define cache (make-vector n -1))
  (vector-set! cache 0 0)
  (vector-set! cache 1 1)

  (define (process-seq m)
    (define (iter x k)
      (cond
        [(= x 1)
         (vector-set! cache m (+ k 1))
         (+ k 1)]
        [(and (< x n) (not (= (vector-ref cache x) -1)))
         (vector-set! cache m (+ k (vector-ref cache x)))
         (+ k (vector-ref cache x))]
        [else
         (iter (process-num x) (+ 1 k))]))
    (iter m 0))
  
  (for ([i (in-range 2 n)])
    (process-seq i))
  cache)

(define (get-max-index vec)
  (let([index 0]
       [value (vector-ref vec 0)])
    (for ([i (in-range(vector-length vec))])
      (cond
        [(> (vector-ref vec i) value)
         (set! value (vector-ref vec i))
         (set! index i)]))
    index))

(define (calc x)
  (get-max-index (collatz-list x)))

(time (calc 1000000))