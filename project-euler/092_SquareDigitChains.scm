(define (sum lst)
  (apply + lst))

(define (digits x)
  (do ((lst '()))
      ((= x 0) lst)
    (set! lst (cons (remainder x 10) lst))
    (set! x (quotient x 10))))

(define (chain x)
  (do ((x x))
      ((or (= x 1) (= x 89))
       x)
    (set! x (sum (map square (digits x))))))

(define (iterate n)
  (do ((i 1 (1+ i))
       (count 0))
      ((= i n) count)
    (set! count (+ count
                   (let ((ch (chain i)))
                     (if (= ch 89) 1 0))))))

(display (iterate 10000000))
