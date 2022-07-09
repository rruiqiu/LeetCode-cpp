# [0001.Two Sum](https://leetcode.com/problems/two-sum/)

## Question

Given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly\* one solution**, and you may not use the *same* element twice.

You can return the answer in any order. 

**Example 1:**

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]. 
```



## Solving Ideas

theta(n^2): Iterate the first list, iterate the second list with the first list index+1 without repition. The first index with the second index of any numbers from the input and determine if meet the target.

theta(n): Space for time, create a HashMap to store the target value required in each list, and search whether the target value exists in HashMap every iteration
