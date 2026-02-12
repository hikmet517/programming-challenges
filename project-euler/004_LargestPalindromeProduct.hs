isPalindrome :: Int -> Bool
isPalindrome x = isSymmetric (show x)
  where
    isSymmetric s = and $ zipWith (==) (reverse (snd pair)) (fst pair)
      where
        pair = splitAt (length s `div` 2) s

isProductOf3DigitNumber :: Int -> Bool
isProductOf3DigitNumber x = not $ null [i | i <- [100..999], x`mod`i==0 && length (show (x`div`i)) == 3]

findLargestPalindrome = [i | i <- [100*100..999*999], isPalindrome i && isProductOf3DigitNumber i]

main :: IO()
main = print $ last $ findLargestPalindrome
