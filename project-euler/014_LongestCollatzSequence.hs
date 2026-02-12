process :: Int -> Int
process n
    | n`mod`2 == 0 = n `div` 2
    | otherwise    = 3 * n + 1

processAll n = processAll' n 0
    where
        processAll' 0 _ = 0
        processAll' 1 y = y + 1
        processAll' x y = processAll' (process x) (y+1)

        
main :: IO()
main = print $ maximum $ [(processAll i, i) | i <- [2..999999]]
