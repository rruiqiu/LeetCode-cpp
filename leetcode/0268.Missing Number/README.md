# [0268.Missing Number](https://leetcode.com/problems/missing-number/)

## Question

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return *the only number in the range that is missing from the array.*

**Example 1:**

```
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 2:**

```
Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
```

**Example 3:**

```
Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
```

## Solving Ideas

Sorting Idea: We can sort from the begin to end, because there will be a missing number so if the current index is not equal to i, then it will return the missing value-i. else it will return the last missing number which is the nums.size();

Bitting manipulation: Retrived From: (https://leetcode.com/problems/missing-number/discuss/69777/C%2B%2B-solution-using-bit-manipulation) For people who don't understand this solution: what he's doing is he's using the bitwise XOR operator to single out the missing number. How? First, we need to understand the properties of XOR: firstly, XOR'ing a number by itself results in 0. So if we have 1 ^ 1, this will equal 0. Secondly, XOR is commutative and associative - what this means is we can re-order our XOR operations in any way we want and it will result in the same value we would have if we didn't. Finally, a number XOR'd by 0 will result in the same number unchanged. So, essentially, by XOR'ing all the numbers from 0 to n, and all the numbers in the array, we will end up XOR'ing 2 of every number except for the missing one. As we know, it doesn't matter which order we XOR these numbers in - as long as we XOR 2 of the same number, it will result in 0. So eventually we will get 0 ^ the missing number, which, due to the third property I mentioned, will simply equal the missing number. If you're not convinced as to how these properties work, I would recommend taking a quick look as to how they work.

Simply that means by using the bit operator xor we can exculde all the number exist and by xor the index to return the missing value.
