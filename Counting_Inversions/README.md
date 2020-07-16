# Counting Inversions

 Let ```S``` be a sequence ```n``` numbers. If ```i<j``` and ```S[i]>S[j]```, then the pair of elements ```(S[i],S[j])``` is called an inversion of ```S```. For example, let
 ```
 S = { 2, 4, 1, 3, 5}
 ```

 The sequence ```S``` has three inversions: ```(2,1), (4,1), (4,3)```.

The wiki link for better understanding of the algorithm and its application is [here](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)).

## Category
> Divide and Conquer

> Advance Recursion 

## The Challenge
This file ```IntegerArr.txt``` contains 100,000 integers between 1 and 100,000 (inclusive) in some order, with no integer repeated.

The task is to compute the number of inversions in the file given where the i<sup>th</sup> row of the file indicates the i<sup>th<sum> entry of an array.

Because of the large size of this array, you should try to implement a fast divide-and-conquer algorithm. (Hint: You need a logic to piggy back onto divide and conquer algorithm of merge sort.)

## [Solution](counting_inversions.cpp)
