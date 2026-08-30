(define (read-file f)
  (with-input-from-file f
    (lambda ()
      (let loop ((lst '())
                 (c (read-char)))
        (if (eof-object? c)
            (apply string (reverse lst))
            (loop (cons c lst) (read-char)))))))

;; read all data
(define data (read-file "0013_data.txt"))

(define (split-string str c)
  (let ((len (string-length str)))
    (let loop ((lst '())
               (i 0)
               (b 0))
      (cond ((= i len)
             (if (= b i)
                 (reverse lst)
                 (reverse (cons (substring str b i) lst))))
            ((char=? (string-ref str i) c)
             (loop (cons (substring str b i) lst) (+ i 1) (+ i 1)))
            (else
             (loop lst (+ i 1) b))))))

;; split newlines
(set! data (split-string data #\newline))

(define (char->digit c)
  (if (char-numeric? c)
      (- (char->integer c) 48)
      #f))


;; to list of list of digits
(set! data
      (map (lambda (line)
             (map char->digit (string->list line)))
           data))


(define (digit-sum data)
  (let loop ((lst '())
             (i 0))
    (if (= i (length (car data)))
        (reverse lst)
        (loop (cons (apply + (map (lambda (x) (list-ref x i)) data)) lst) (+ i 1)))))

(define digit-sums (digit-sum data))


(define (digits x)
  (let loop ((x (abs x))
             (l '()))
    (if (= x 0)
        l
        (loop (quotient x 10) (cons (remainder x 10) l)))))


(define (large-sum data)
  (let loop ((sums (reverse data))
             (lst '())
             (carry 0))
    (if (null? sums)
        (append (digits carry) lst)
        (loop (cdr sums)
              (cons (remainder (+ (car sums) carry) 10) lst)
              (quotient (+ (car sums) carry) 10)))))

(define large-sum-digits (large-sum digit-sums))


(define-syntax dotimes
  (syntax-rules ()
    ((_ (var end) body ...)
     (do ((var 0 (+ var 1)))
         ((= var end))
       body ...))))

(begin
  (dotimes (i 10)
           (display (list-ref large-sum-digits i)))
  (newline))
