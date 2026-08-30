-- fark => 2*(ab + ac + bc) = ab + ba + ac + ca + bc + cb

main :: IO()
main = print $ sum [x*y | x <- [1..100], y <- [1..100], x /= y]
