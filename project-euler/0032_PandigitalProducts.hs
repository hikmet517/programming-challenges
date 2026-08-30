import Data.List

grouped xs = [prod (a+b) c xs| c <- [4..9], b <- [1..c], a <- [1..b], a+b+c==9 && (prod 0 a xs)*(prod a b xs)==prod (a+b) c xs]

prod :: Int -> Int -> String -> Int
prod x n xs = read (take n (drop x xs)) :: Int

main :: IO()
main = print $ sum $ nub $ concat $ map grouped (permutations "123456789")
