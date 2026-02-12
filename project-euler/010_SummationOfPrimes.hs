isqrt :: Integer -> Integer
isqrt n
   | n < 0     = error "isqrt"
   | otherwise = isqrt' ((n+1) `div` 2)
   where
     isqrt' s
         | s*s <= n && n < (s+1)*(s+1) = s
         | otherwise                   = isqrt' ((s + (n `div` s)) `div` 2)
         
primes n = primes' 2 []
  where
    primes' x ps
      | x == n                 = ps
      | isPrime x (isqrt x) ps = primes' (x+1) (ps++[x])
      | otherwise              = primes' (x+1) ps
      where
        isPrime _ _ []   = True
        isPrime a k (b:bs)
          | b > k        = True
          | a`mod`b == 0 = False
          | otherwise    = isPrime a k bs

main :: IO()
main = print $ sum $ primes 2000000