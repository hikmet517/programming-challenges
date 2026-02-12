(define (factorial x)
  (let loop ((iter 1)
             (acc 1))
    (if (> iter x)
        acc
        (loop (+ iter 1) (* acc iter)))))

(define (digits x)
  (let loop ((x (abs x))
             (l '()))
    (if (= x 0)
        l
        (loop (quotient x 10) (cons (remainder x 10) l)))))


(define (find-all)
  (let ((limit 1000000))
    (let loop ((iter 3)
               (lst '()))
      (if (< iter limit)
          (if (= (apply + (map factorial (digits iter))) iter)
              (loop (+ iter 1) (cons iter lst))
              (loop (+ iter 1) lst))
          (reverse lst)))))

(let ((all (find-all)))
  (display "list: ")
  (display all)
  (newline)
  (display "sum: ")
  (display (apply + all))
  (newline))

