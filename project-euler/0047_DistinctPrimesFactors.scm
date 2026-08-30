(define (factorize x)
  (let loop ((num x)
             (fs '())
             (div 2))
    (cond ((= num 1)
           (reverse fs))
          ((= (remainder num div) 0)
           (loop (quotient num div) (cons div fs) div))
          (else
           (loop num fs (+ div 1))))))


(define (num-distinct-factors lst)
  (let loop ((last (car lst))
             (rest (cdr lst))
             (count 1))
    (if (null? rest)
        count
        (if (= last (car rest))
            (loop (car rest) (cdr rest) count)
            (loop (car rest) (cdr rest) (+ count 1))))))


(define (consecutive n)
  (let loop ((count 0)
             (stash '())
             (i 10))
    (if (= count n)
        (begin
          (display stash)
          (newline)
          (- i n))
        (let ((fac (factorize i)))
          (if (= (num-distinct-factors fac) n)
              (loop (+ count 1) (cons fac stash) (+ i 1))
              (loop 0 '() (+ i 1)))))))

(begin
  (display (consecutive 4))
  (newline))
