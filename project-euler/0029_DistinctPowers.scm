(define (powers end)
  (do ((b 2 (1+ b))
       (lst (list)))
      ((> b end) lst)
    (set! lst (cons 
               (do ((p 2 (1+ p))
                    (ps (list)))
                   ((> p end) ps)
                 (set! ps (cons (expt b p) ps)))
               lst))))

(display
 (length
  (let loop ((ps (sort (apply append (powers 100)) <))
             (uniques (list)))
    (cond ((null? uniques) ; beggining
           (loop (cdr ps) (cons (car ps) uniques)))
          ((null? ps) ; ending
           uniques)
          ((= (car uniques) (car ps)) ; equal
           (loop (cdr ps) uniques))
          (else ; not equal
           (loop (cdr ps) (cons (car ps) uniques))))))
 )
