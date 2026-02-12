{-# OPTIONS_GHC -O2 #-}
import Data.List
  
reduceSum (x1:x2:xs) = rs [] [x1,x2] xs
  where
    rs  b o []  = if (not (null b)) && (last b) >= sum o || null b then [b ++ [sum o]] else []
    rs  b o s   = if (null b || last b /= 1)
                    then if (not (null b)) && (last b) >= sum o || null b then (b ++ [sum o] ++ s) : rs (b++[head o]) [last o, head s] (tail s) else rs (b++[head o]) [last o, head s] (tail s)
                    else []
    
    
    
funn n = fun [replicate n 1] []    

fun [] tot = tot
fun xs tot = fun res (tot ++ xs)
  where
    res = concat $ map reduceSum xs
    

-- 3 3 1 1 1 => [6 1 1 1] [3 3 2 1]
  
-- 4 + 1
-- 3 + 2
-- 3 + 1 + 1          -> 1
-- 2 + 2 + 1          -> 0
-- 2 + 1 + 1 + 1      -> 0,1
-- 1 + 1 + 1 + 1 + 1  -> 0



-- 4 + 1
-- 3 + 1 + 1
-- 2 + 1 + 1 + 1
-- 1 + 1 + 1 + 1 + 1
