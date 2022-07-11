# [0746.Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)

## Question

You are given an integer array `cost` where `cost[i]` is the cost of `ith` step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

Return *the minimum cost to reach the top of the floor*.

**Example 1:**

```
Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
```

**Example 2:**

```
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
```



## Solving Ideas

This question is kind of tricky, main idea is to compare the smallest and add them during the movement of array and find the smallest cost. Notice it can either climb one or two steps. A diagram can better represent the algorithm below.

![Image text](https://github.com/richardddddddd/LeetCode-cpp/blob/main/leetcode/0746.Min%20Cost%20Climbing%20Stairs/image-20220710221114831.png)
