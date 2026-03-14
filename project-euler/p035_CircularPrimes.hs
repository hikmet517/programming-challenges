{-# OPTIONS_GHC -O2 #-}

getRotations :: Integer -> [Integer]
getRotations x = take n (map (\y -> read y) (iterate rotateLeft s))
    where
        s = show x
        n = length s
        rotateLeft []     = []
        rotateLeft (x:xs) = xs ++ [x]

        
isqrt :: Integer -> Integer
isqrt n
   | n < 0     = error "isqrt"
   | otherwise = isqrt' ((n+1) `div` 2)
   where
     isqrt' s
         | s*s <= n && n < (s+1)*(s+1) = s
         | otherwise                   = isqrt' ((s + (n `div` s)) `div` 2)
        
        
isPrime :: Integer -> Bool
isPrime 1 = False
isPrime k = null [ x | x <- [2..isqrt k], k `mod` x == 0]


isCircularPrime :: Integer -> Bool
isCircularPrime x = and ( map isPrime (getRotations x))

main :: IO()
main = print $ length $ filter (==True) (map isCircularPrime [1..1000000])