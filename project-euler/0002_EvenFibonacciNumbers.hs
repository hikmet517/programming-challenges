addLastTwo []  = error "need at least one element"
addLastTwo [x] = x + x
addLastTwo xs  = x + y
    where
        x = last xs
        y = last $ init xs

appendSum xs = xs ++ [addLastTwo xs]

main :: IO()
main = print $ sum (filter even (last $ takeWhile (\xs->((last xs) < 4000000)) $ iterate appendSum [1]))
