(define (fact x)
  (do ((mul 1))
      ((= x 1) mul)
    (set! mul (* x mul))
    (set! x (- x 1))))

(define (sum lst)
  (apply + lst))

(define (digits x)
  (do ((lst (list)))
      ((= x 0) lst)
    (set! lst (cons (remainder x 10) lst))
    (set! x (quotient x 10))))

(display (sum (digits (fact 100))))
