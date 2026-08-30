{-# OPTIONS_GHC -O2 #-}

isSorted xs = and $ zipWith (<=) xs (tail xs)

extend xs        = map (1:) xs
increment xs     = map (\x->(head x)+1 : tail x) xs
iter xs          = filter isSorted (increment xs ++ extend xs)


getSums n = getSums' [[1 :: Int]] n
  where
    getSums' xs 1 = xs
    getSums' xs n = getSums' (iter xs) (n-1)

main = print $ pred $ length $ getSums 100

