--
-- EPITECH PROJECT, 2021
-- pushswap_checker
-- File description:
-- pushwap
--

import System.Environment
import System.Exit
import Data.Char
import Debug.Trace

main :: IO ()
main = do
    args <- getArgs
    commands <- getLine
    if isInt args
        then
            let argus = map (read::String->Int) args
            in checkArgs argus commands
        else
            putStrLn "Error: Values must be numerical" >>
            exitWith (ExitFailure 84)

isInt :: [String] -> Bool
isInt [] = True
isInt (a:b) | length (a:b) == 0 = False
            | all isDigit a = isInt b
            | otherwise = False

checkArgs :: [Int] -> String -> IO ()
checkArgs (args) (commands) | length (args) == 0 = exitWith (ExitFailure 84)
                            | otherwise = mainSort args commands

mainSort :: [Int] -> String -> IO ()
mainSort (args) (commands) = let cSplit = words commands
                                 values = (args, [])
    in launchSort values cSplit

isSorted :: ([Int], [Int]) -> Bool
isSorted ((a:b:c), []) | a <= b = isSorted ((b:c), [])
                       | otherwise = False
isSorted (a, []) = True
isSorted (a, b) = False

launchSort :: ([Int], [Int]) -> [String] -> IO ()
launchSort ([], []) commands =
    putStrLn "Wrong command !" >>
    exitWith (ExitFailure 84)
launchSort values [] | isSorted values == True =
    putStrLn "OK" >>
    exitWith (ExitSuccess)
                     | otherwise =
                         putStr "KO: " >>
                         print values >>
                         exitWith (ExitFailure 84)
launchSort values (c:d) = let result = checkCommand values c
    in launchSort result d

checkNextCommands :: ([Int], [Int]) -> [Char] -> ([Int], [Int])
checkNextCommands a b = case b of "rrb" -> rotateLastElementsB a
                                  "rrr" -> rotateLastElementsR a
                                  _ -> ([], [])

checkCommand :: ([Int], [Int]) -> [Char] -> ([Int], [Int])
checkCommand a b = case b of "sa" -> swapElementsA a
                             "sb" -> swapElementsB a
                             "sc" -> swapElementsC a
                             "pa" -> putElementsA a
                             "pb" -> putElementsB a
                             "ra" -> rotateElementsA a
                             "rb" -> rotateElementsB a
                             "rr" -> rotateElementsR a
                             "rra" -> rotateLastElementsA a
                             _ -> checkNextCommands a b

swapElem :: [a] -> [a]
swapElem (a:b:c) = (b:a:c)

swapElementsA :: ([a], [b]) -> ([a], [b])
swapElementsA (a, c) = (swapElem a, c)

swapElementsB :: ([a], [b]) -> ([a], [b])
swapElementsB (a, c) = (a, swapElem c)

swapElementsC :: ([a], [b]) -> ([a], [b])
swapElementsC (a, c) = (swapElem a, swapElem c)

putElementsA :: ([Int], [Int]) -> ([Int], [Int])
putElementsA (a, []) = (a, [])
putElementsA (a, (b:c)) = (b:a, c)

putElementsB :: ([Int], [Int]) -> ([Int], [Int])
putElementsB ([], b) = ([], b)
putElementsB ((a:b), c) = (b, a:c)

rotateElem :: [Int] -> [Int]
rotateElem (a:b) = b ++ [a]

rotateElementsA :: ([Int], [Int]) -> ([Int], [Int])
rotateElementsA (a, c) = (rotateElem a, c)

rotateElementsB :: ([Int], [Int]) -> ([Int], [Int])
rotateElementsB (a, c) = (a, rotateElem c)

rotateElementsR :: ([Int], [Int]) -> ([Int], [Int])
rotateElementsR (a, c) = (rotateElem a, rotateElem c)

rotateLastElem :: [Int] -> [Int]
rotateLastElem a = let val = last a
                       list = take (length a - 1) a
    in [val] ++ list

rotateLastElementsA :: ([Int], [Int]) -> ([Int], [Int])
rotateLastElementsA (a, c) = (rotateLastElem a, c)

rotateLastElementsB :: ([Int], [Int]) -> ([Int], [Int])
rotateLastElementsB (a, c) = (a, rotateLastElem c)

rotateLastElementsR :: ([Int], [Int]) -> ([Int], [Int])
rotateLastElementsR (a, c) = (rotateLastElem a, rotateLastElem c)