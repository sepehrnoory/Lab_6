{--
    @name: Sepehr Noori
    @date: April 17, 2022
    @assignment: EECS 368 - Assignment 6
    @brief: Define various funcitons in Haskell using list comprehension
--}
--Used to import the 'find' and 'isJust' functions
import Data.list
import Data.Maybe


replicate :: Int -> a -> [a]
replicate n y = [y | x <- [1..n]]

--Helper funciton for the perfects method
--  returns a list of factors of a given number
factors :: Int -> [Int]
factors a = [x | x <- [1..a], a `mod` x == 0]

--Checks every number from 1 to a to see if any are perfect numbers
--  a perfect number is if all of its factors, not including itself, add up to the number
perfects :: Int -> [Int]
perfects a = [x | x <- [1..a], x == (sum (factorsx))]

--similar to predifined positions, checks to see if the type returned is Just.
positions :: Eq a => a -> [a] -> [Int]
positions x xs = [index | (index, x') <- zip [0..] xs, isJust (find (==x) [x'])]

--Returns the scalar producs of two given lists
scalarproduct :: [Int] -> [Int] -> Int
scalaproducs xs ys = sum [x*y | (x,y) <- zip xs ys]