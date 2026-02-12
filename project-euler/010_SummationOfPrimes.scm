(define (prime? k)
  (if (> k 1)
      (let ((end (floor (sqrt k))))
        (let loop ((fac 2))
          (cond ((> fac end)
                 #t)
                ((= (remainder k fac) 0)
                 #f)
                (else (loop (+ fac 1))))))
      #f))


(define (sum-of-primes-below n)
  (let loop ((i 0)
             (sum 0))
    (cond ((= i n)
           sum)
          ((prime? i)
           (loop (+ i 1) (+ i sum)))
          (else
           (loop (+ i 1) sum)))))

(display (sum-of-primes-below 2000000))
(newline)
