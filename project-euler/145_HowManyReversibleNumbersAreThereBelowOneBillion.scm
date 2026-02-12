(define (digits x)
  (do ((lst '()))
      ((= x 0) lst)
    (set! lst (cons (remainder x 10) lst))
    (set! x (quotient x 10))))

(define (from-digits lst)
  (fold-left (lambda (x y) (+ y (* 10 x))) 0 lst))

(define (reversible? x)
  (if (= (remainder x 10) 0)
      #f
      (let ((revx (from-digits (reverse (digits x)))))
        (for-all odd? (digits (+ x revx))))))

(define (iterate n)
  (do ((i 11 (1+ i))
       (count 0))
      ((= i n) count)
    (set! count (+ count
                   (if (reversible? i) 1 0)))))

(display (iterate (expt 10 3)))

(define (iterate-list n)
  (do ((i 1 (1+ i))
       (lst '()))
      ((= i n) (reverse lst))
    (if (reversible? i) (set! lst (cons i lst)))))


;; utility function
(define (range b e s)
  (let ((f (if (< b e) > <)))
    (do ((i b (+ i s))
         (lst '()))
        ((f i e) (reverse lst))
      (set! lst (cons i lst)))))

