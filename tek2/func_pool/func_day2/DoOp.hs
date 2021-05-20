--
-- EPITECH PROJECT, 2021
-- func_day2
-- File description:
-- fromJust, readMaybe, elem, lookup.
--

import Data.Char
import System.Environment

main :: IO()
main = do
    args <- getArgs
    print $ args
    return ()

myElem :: Eq a => a -> [a] -> Bool
myElem a [] = False
myElem a (b:c) | b == a = True
               | otherwise = myElem a c

safeDiv :: Int -> Int -> Maybe Int
safeDiv a 0 = Nothing
safeDiv a b = Just (a `div` b)

safeNth :: [a] -> Int -> Maybe a
safeNth (a:b) 0 = Just a
safeNth (a:b) n | n < 0 || length (a:b) <= n = Nothing
                | otherwise = safeNth b (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc (Just a) = Just (a + 1)
safeSucc _ = Nothing

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup a [] = Nothing
myLookup a ((c, d):e) | a == c = Just d
                      | otherwise = myLookup a e

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo f (Just a) (Just b) = Just (f a b)
maybeDo f _ (Just b) = Nothing
maybeDo f (Just a) _ = Nothing
maybeDo f _ _ = Nothing

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt a | all isDigit a = Just (read a :: Int)
          | otherwise = Nothing

getLineLength :: IO Int
getLineLength = do length <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength s = do
    putStrLn s
    return (length s)

displaySide :: Int -> Int -> IO ()
displaySide len 0 = return ()
displaySide len 1 = putStr $ "+\n"
displaySide len n | n == len = do
    putStr $ "+"
    displaySide len (n - 1)
                  | otherwise = do
    putStr $ "-"
    displaySide len (n - 1)

displayLine :: Int -> Int -> IO ()
displayLine len 0 = return ()
displayLine len 1 = putStr $ "|\n"
displayLine len n | n == len = do
    putStr $ "|"
    displayLine len (n - 1)
                  | otherwise = do
    putStr $ " "
    displayLine len (n - 1)

displayBox :: Int -> Int -> Int -> IO ()
displayBox originN 0 len = return ()
displayBox originN 1 len = displaySide len len
displayBox originN n len | n == originN = do
    displaySide len len
    displayBox originN (n - 1) len
                         | otherwise = do
    displayLine len len
    displayBox originN (n - 1) len


printBox :: Int -> IO ()
printBox n | n <= 0 = return ()
printBox n | n > 0 = do
    let len = n * 2
    displayBox n n len

concatLines :: Int -> IO String
concatLines n | n <= 0 = return ""
              | otherwise = do
                  line <- getLine
                  next <- concatLines (n - 1)
                  let res = line ++ next
                  return res

getInt :: IO (Maybe Int)
getInt = do
    number <- getLine
    return (readInt number)