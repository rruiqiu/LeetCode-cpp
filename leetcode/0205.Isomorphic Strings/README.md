# [0205.Isomorphic Strings](https://leetcode.com/problems/isomorphic-strings/)

## Question

Given two strings `s` and `t`, *determine if they are isomorphic*.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

**Example 1:**

```
Input: s = "egg", t = "add"
Output: true
```

**Example 2:**

```
Input: s = "foo", t = "bar"
Output: false
```

**Example 3:**

```
Input: s = "paper", t = "title"
Output: true
```

## Solving Ideas

Assign a hashmap which the key coorepsonding to the char of string x and value to the char of string Y, also assign a hashset which store the char of string y, for each iteration, it will check first if the char find in s is already mapped in the string t, if they appear before, the corresponded key value should be equal to the current index char of string t, if not, return false; And if it is not found in the string s, then it will check if y can be found, if y can be found, that means it has been inserted before which will return false; and if not found, it will insert the key of char s and the value of char t, and also inserting the set value of y to find.
