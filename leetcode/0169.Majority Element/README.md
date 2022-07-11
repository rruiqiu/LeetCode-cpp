# [0169.Majority Element](https://leetcode.com/problems/majority-element/)

## Question

Given an array `nums` of size `n`, return *the majority element*.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

**Example 1:**

```
Input: nums = [3,2,3]
Output: 3
```

**Example 2:**

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```



## Solving Ideas

Insert each num into the hashtable(key), if found, let the hashvalue corresponding +1, after that, compare the largest value corresponding to each key in the hashmap and extract out the largest value and return to its position
