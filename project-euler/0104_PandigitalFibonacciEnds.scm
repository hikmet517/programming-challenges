(define (char->digit c)
  (if (char-numeric? c)
      (- (char->integer c) 48)
      #f))

(define (digit->char d)
  (if (and (>= d 0) (<= d 9))
      (integer->char (+ d 48))
      #f))

(define (strnum->vecnum strnum)
  ;; (strnum->vecnum "1234")
  ;; => #(4 3 2 1)
  (list->vector (reverse (map char->digit (string->list strnum)))))

(define (vecnum->strnum vecnum)
  ;; (vecnum->strnum (vector 4 3 2 1))
  ;; => "1234"
  (list->string (reverse (map digit->char (vector->list vecnum)))))

(define (vecnum-add vecnum1 vecnum2)
  ;; (vecnum->strnum (vecnum-add (strnum->vecnum "268") (strnum->vecnum "37")))
  ;; => "305"
  (let* ((len1 (vector-length vecnum1))
         (len2 (vector-length vecnum2))
         (len (+ (max len1 len2) 1))
         (vecnumres (make-vector len)))
    (do ((i 0 (+ i 1))
         (carry 0))
        ((= (- len 1) i) vecnumres)
      (let* ((sum (+ (if (< i len1) (vector-ref vecnum1 i) 0)
                     (if (< i len2) (vector-ref vecnum2 i) 0)
                     carry))
             (digit (if (>= sum 10) (- sum 10) sum)))
        (set! carry (if (>= sum 10) 1 0))
        (vector-set! vecnumres i digit)
        (vector-set! vecnumres (+ i 1) carry)))
    (if (= (vector-ref vecnumres (- (vector-length vecnumres) 1)) 0)
        (list->vector (reverse (cdr (reverse (vector->list vecnumres)))))
        vecnumres)))

(define (strnum-add strnum1 strnum2)
  ;; (strnum-add "268" "37")
  ;; => "305"
  (vecnum->strnum (vecnum-add (strnum->vecnum strnum1)
                              (strnum->vecnum strnum2))))

(define (string-includes str char)
  (let loop ((i 0))
    (if (< i (string-length str))
        (if (char=? (string-ref str i) char)
            #t
            (loop (+ i 1)))
        #f)))

(define (strnum-pandigital? strnum)
  (and (string-includes strnum #\1)
       (string-includes strnum #\2)
       (string-includes strnum #\3)
       (string-includes strnum #\4)
       (string-includes strnum #\5)
       (string-includes strnum #\6)
       (string-includes strnum #\7)
       (string-includes strnum #\8)
       (string-includes strnum #\9)))

(define (solve)
  (call-with-current-continuation
   (lambda (exit)
     (let loop ((i 1)
                (num1 (strnum->vecnum "0"))
                (num2 (strnum->vecnum "1")))
       (if (<= i 1000000)
           (let* ((fib num2)
                  (fib-strnum (vecnum->strnum fib)))
             (if (and (>= (string-length fib-strnum) 9)
                      (strnum-pandigital? (substring fib-strnum 0 9))
                      (strnum-pandigital? (substring fib-strnum
                                                     (- (string-length fib-strnum) 9)
                                                     (string-length fib-strnum))))
                 (begin (display i)
                        (newline)
                        (exit)))
             (loop (+ i 1)
                   num2
                   (vecnum-add num1 num2))))))))

;; takes 5-6 minutes with chez scheme
(solve)
