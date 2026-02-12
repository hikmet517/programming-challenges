main :: IO()
main = print $ head [a*b*c | c <- [3..1000], b <- [1..c], a <- [1..b], a+b+c==1000 && a*a + b*b == c*c]