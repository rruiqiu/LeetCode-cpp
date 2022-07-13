# [0202.Happy Number](https://leetcode.com/problems/happy-number/)

## Question

Write an algorithm to determine if a number `n` is happy.

A **happy number** is a number defined by the following process:

- Starting with any positive integer, replace the number by the sum of the squares of its digits.
- Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.
- Those numbers for which this process **ends in 1** are happy.

Return `true` *if* `n` *is a happy number, and* `false` *if not*.

**Example 1:**

```
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

**Example 2:**

```
Input: n = 2
Output: false
```



## Solving Ideas

by using the modulus to extract each digit and add the square of them one by one to the sum. divide them by 10 until they are equal to zero in a while loop, determine if this sum is equal to 1, if not iterate the loop again;

Because the question metion it will loop in an endless cycle if it can't have 1, so it is used the hash_set to implement, insert the key of each value if it is new key, or it is repeating the cycle then return false, unhappy :<
