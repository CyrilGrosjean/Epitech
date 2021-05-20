--
-- EPITECH PROJECT, 2021
-- func_day1
-- File description:
-- My
--

import Data.List

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x | x > 0 = x
        | otherwise = (-x)

myMin :: Int -> Int -> Int
myMin a b | a < b = a
          | otherwise = b

myMax :: Int -> Int -> Int
myMax a b | a < b = b
          | otherwise = a

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead (a:_) = a
myHead [] = error "empty list"

myTail :: [a] -> [a]
myTail (_:a) = a
myTail [] = error "empty list"

myLength :: [a] -> Int
myLength [] = 0
myLength (_:a) = 1 + myLength a

myNth :: [a] -> Int -> a
myNth (a:b) 0 = a
myNth (a:b) n | n < 0 || myLength (a:b) <= n = error "Invalid index"
              | otherwise = myNth b (n - 1)
myNth [] n = error "Invalid index"

myTake :: Int -> [a] -> [a]
myTake 1 (a:b) = [a]
myTake n (a:b) | n < 0 = error "Invalid length"
               | n >= myLength (a:b) = (a:b)
               | otherwise = (a:myTake (n - 1) b)

myDrop :: Int -> [a] -> [a]
myDrop 1 (a:b) = b
myDrop n (a:b) | n < 0 || myLength(a:b) < n = error "Invalid length"
               | n >= myLength (a:b) = []
               | otherwise = myDrop (n - 1) b

myAppend :: [a] -> [a] -> [a]
myAppend [] c = c
myAppend (a:b) c = (a:myAppend b c)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:b) = myAppend (myReverse b) [a]

myInit :: [a] -> [a]
myInit [] = error "List is empty"
myInit a = myTake (myLength a - 1) a

myLast :: [a] -> a
myLast [] = error "List is empty"
myLast a = myNth a (myLength a - 1)

myZip :: [a] -> [b] -> [(a,b)]
myZip [] (c:d) = []
myZip (a:b) [] = []
myZip [] [] = []
myZip (a:b) (c:d) = (a, c):myZip b d

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip ((a,b):c) | myLength ((a,b):c) == 1 = ([a], [b])
                  | otherwise = (myAppend [a] (myFst (myUnzip c)),
                        myAppend [b] (mySnd (myUnzip c)))

myMap :: (a -> b) -> [a] -> [b]
myMap func [] = []
myMap func (a:b) = func a : myMap func b

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter func (a:b) | func a = a : myFilter func b
                    | otherwise = myFilter func b
myFilter func [] = []

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl func first [] = first
myFoldl func first (a:b) = myFoldl func (func first a) b

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr func first [] = first
myFoldr func first (a:b) = func a (myFoldr func first b)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition func (a:b) | func a = (myAppend [a] (myFst (myPartition func b)),
                                        mySnd (myPartition func b))
                       | otherwise = (myFst (myPartition func b), myAppend [a]
                                        (mySnd (myPartition func b)))
myPartition func [] = ([], [])