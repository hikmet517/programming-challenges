(define (read-file f)
  (with-input-from-file f
    (lambda ()
      (let loop ((lst '()))
        (let ((c (read-char)))
          (if (eof-object? c)
              (list->string (reverse lst))
              (loop (cons c lst))))))))


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


(define (word->num word)
  (apply + (map (lambda (c) (+ (- (char->integer (char-upcase c))
                                  (char->integer #\A))
                               1))
                (string->list word))))


;; (n * (n-1)) / 2 = x
;; n^2 - n - 2x = 0  => a: 1, b: -1, c: -2x
(define (triangle-num? num)
  (let* ((a 1)
         (b -1)
         (c (* -2 num))
         (k (sqrt (- (* b b) (* 4 a c))))
         (x1 (/ (+ (* -1 b) k) (* 2 a)))
         (x2 (/ (- (* -1 b) k) (* 2 a))))
    (cond ((and (integer? x1) (> x1 0))
           (- x1 1))
          ((and (integer? x2) (> x2 0))
           (- x2 1))
          (else
           #f))))


(define (main)
  (let* ((file-content (read-file "0042_words.txt"))
         (words (map (lambda (s) (substring s 1 (- (string-length s) 1)))
                     (split-string file-content #\,)))
         (count 0))
    (for-each (lambda (w)
                (if (triangle-num? (word->num w))
                    (set! count (+ count 1))))
              words)
    count))


(display (main))  ; 162
(newline)
