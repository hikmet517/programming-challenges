dayOfWeek :: Integer -> Integer -> Integer -> Integer
dayOfWeek y m d = (d + t1 + k + t2 + t3 + 5 * j) `mod` 7
    where
        t1 = floor(fromIntegral(13 * (m' + 1)) / 5.0)
        t2 = floor((fromIntegral k) / 4.0)
        t3 = floor((fromIntegral j) / 4.0)
        k  = y `mod` 100
        j  = y `div` 100
        m' = if (m<=2) then (m+12) else m


sundays :: Integer -> Integer -> Integer
sundays start end = sundays' start 1
    where
        sundays' :: Integer -> Integer -> Integer
        sundays' y m
            | y > end    = 0
            | otherwise  = if dayOfWeek y m 1 == 1 then rest + 1 else rest
            where
                nextY = if m == 12 then y + 1 else y
                nextM = if m == 12 then 1 else m+1
                rest  = sundays' nextY nextM


leap :: Integer -> Bool
leap y = (y `mod` 4 == 0) && (y `mod` 100 /= 0) || (y `mod` 400 == 0)


daysInMonth :: Integer -> Integer -> Integer
daysInMonth m y
    | m == 2 = if leap y then 29 else 28
    | m == 4 || m == 6 || m == 9 || m == 11 = 30
    | otherwise = 31


main :: IO ()
main = do putStrLn (show (sundays 1901 2000))
