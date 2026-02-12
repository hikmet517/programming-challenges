
;; (4) => (3 1)
;; (4 3 3) => (4 3 2 1)
;; (1 1 1) => #f
(define (expand lst)
  (let-values (((h t) (span (lambda (x) (> x 1)) lst)))
    (if (null? h)
        #f
        (append (except-last-pair h) (append (list (- (last h) 1) 1) t)))))


;; (3 3 1) => (3 2 2)
;; (3 2 1 1) => (2 2 2 1)

(define (transfer xs)
  (let loop ((lst '())
             (carry 0)
             (xs xs))
    (cond ((null? xs)
           (reverse (cons (+ (car lst) carry) (cdr lst))))
          ((and (not (null? lst)) (>= (- (car lst) (car xs)) 1))
           (display "a")
           (loop (cons (+ (car xs) carry) lst) 1 (cdr xs)))
          (else
           (loop (cons (+ (car xs) carry) lst) carry (cdr xs))))))







;; (let loop ((lst '())
;;              (xs xs))
;;     (cond ((null? xs)
;;            (reverse lst))
;;           (else
;;            (loop (cons (car xs) lst) (cdr xs)))))


