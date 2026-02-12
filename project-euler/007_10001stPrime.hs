primes n = primes' 2 [] 0
  where
    primes' x ps len
      | len == n     = ps
      | isPrime x ps = primes' (x+1) (ps++[x]) (len+1)
      | otherwise    = primes' (x+1) ps len
      where
        isPrime _ [] = True
        isPrime a bs = not $ or $ map (\m->a`mod`m==0) bs

main :: IO()
main = print $ last $ primes 10001