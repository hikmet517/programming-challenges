(define (number->digits num)
  (let loop ((x (abs num))
             (res '()))
    (if (< x 10)
        (cons x res)
        (loop (quotient x 10) (cons (remainder x 10) res)))))


(define (digit-count num)
  (let loop ((count 1)
             (x num))
    (if (< x 10)
        count
        (loop (1+ count) (div x 10)))))


(define (unique-digit-count num)
  (let ((digits (number->digits num)))
    (let loop ((i 1)
               (c 0))
      (if (<= i 9)
          (if (member i digits)
              (loop (1+ i) (1+ c))
              (loop (1+ i) c))
          c))))


(define (9pandigital? num)
  (= 9 (digit-count num) (unique-digit-count num)))


(define (generate-9pandigital num)
  (let loop ((i 1)
             (x ""))
    (if (>= (string-length x) 9)
        (string->number x)
        (loop (1+ i) (string-append x (number->string (* i num)))))))


(define (can-generate-9pandigital num)
  (let ((generated (generate-9pandigital num)))
    (if (9pandigital? generated)
        generated
        #f)))


(define (solve)
  (let loop ((i 1)
             (max 0))
    (if (>= i 9999)
        max
        (let ((res (can-generate-9pandigital i)))
          (loop (+ i 1) (if (and res (> res max)) res max))))))


(display (solve))  ; 932718654
(newline)
