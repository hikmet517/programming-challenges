#lang racket

(define (read-words filename)
  (define in (open-input-file filename))
  (define str-file (read-line in))
  (close-input-port in)
  (map (λ (s) (string-trim s "\"")) (string-split str-file ",")))

(define (digit-count x)
  (define (iter n i)
    (if (zero? n) i (iter (quotient n 10) (add1 i))))
  (if (zero? x) 1 (iter x 0)))

(define (squares-by-digit-count num-of-digits)
  (let ([limit (λ (n)
                 (exact-ceiling (sqrt (expt 10 (sub1 n)))))]
        [square (λ (n) (* n n))])
    (map square (range (limit num-of-digits) (limit (add1 num-of-digits))))))

(define (word-sign w)
  (map (λ (x) (cons (car x) (length x)))
       (group-by identity (sort (string->list w) char<?))))

(define (number->digits n . args)
  (let ((b (if (null? args) 10 (car args))))
    (let loop ((n n) (d '()))
      (if (zero? n) d
          (loop (quotient n b)
                (cons (modulo n b) d))))))

(define (digits->number ds)
  (let loop ([lst ds] [mul 0])
    (if (empty? lst)
        (quotient mul 10)
        (loop (cdr lst) (* 10 (+ (car lst) mul))))))

(define (map-word-to-num w n)
  (let* ([digits (number->digits n)]
         [chars (string->list w)]
         [mapping (remove-duplicates (map cons chars digits))])
    (if (equal? (group-by car mapping) (group-by cdr mapping))
        mapping
        #f)))

(define (num-from-mapping m w)
  (digits->number
   (map (λ (x) (cdr (assoc x m))) (string->list w))))

(define (square? n) (integer? (sqrt n)))

(define (check-anagram an sqt)
  (filter list?
          (for/list ([s (cadr (assoc (string-length (car an)) sqt))])
            (let ([mapping (map-word-to-num (car an) s)])
              (if mapping
                  (let ([num (num-from-mapping mapping (cadr an))])
                    (if (and (square? num)
                             (equal? (digit-count num)
                                     (digit-count s)))
                        (list s num)
                        #f))
                  #f)))))


(define word-list (read-words "098_words.txt"))
(define word-sign-table (map (λ (w) (cons (word-sign w) w))
                             word-list))
(define anagrams-table-temp (filter (λ (x) (> (length x) 1))
                                    (group-by car word-sign-table)))
(define anagrams-table (let-values ([(t1 t2)
                                     (partition (λ (x) (> (length x) 2)) anagrams-table-temp)])
                         (append (car (map (λ (x) (combinations x 2)) t1)) t2)))
(define anagrams (map (λ (x) (map cdr x)) anagrams-table))
(define max-len (apply max (map string-length (flatten anagrams))))
(define squares-table (map (λ (x) (cons x (list (squares-by-digit-count x))))
                           (range 1 (add1 max-len))))
(filter (λ (lst) (not (empty? lst)))
        (map (λ (x) (check-anagram x squares-table))
             anagrams))
