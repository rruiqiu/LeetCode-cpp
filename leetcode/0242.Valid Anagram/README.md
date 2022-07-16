# [0242.Valid Anagram](https://leetcode.com/problems/valid-anagram/)

## Question

Given two strings `s` and `t`, return `true` *if* `t` *is an anagram of* `s`*, and* `false` *otherwise*.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 **Example 1:**

```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```
Input: s = "rat", t = "car"
Output: false
```

## Solving Ideas

In this question, because change the letter order will not affect anything, so we can simply by using hashmap to count the appearnce of each character and make comparsion of the the second string. If they have the same character overall, return true elese false;

Sorting method is to sort their letter from the beginning to the end and compare if they are equal.
